#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 400005
struct Node{int x,y;};
Node t[N];
namespace solve
{
	Node a[N];
	bool cmp(Node x,Node y) {return x.x<y.x;}
	int ql[N],qr[N];
	int Main(vector<Node> _t)
	{
		int n=_t.size();
		for(int i=1;i<=n;i++) a[i]=_t[i-1];
		sort(a+1,a+n+1,cmp);
		int tl=inf,tr=-inf,cur=1;
		for(int i=0;i<N;i++)
		{
			while(cur<=n&&a[cur].x+1==i)
			{
				tl=min(tl,a[cur].y+1),tr=max(tr,a[cur].y);
				cur++;
			}
			ql[i]=tl,qr[i]=tr;
		}
		tl=inf,tr=-inf,cur=n;
		int ans=0;
		for(int i=N;i>=0;i--)
		{
			while(cur>=1&&a[cur].x==i)
			{
				tl=min(tl,a[cur].y+1),tr=max(tr,a[cur].y);
				cur--;
			}
			ql[i]=max(ql[i],tl),qr[i]=min(qr[i],tr);
			// if(ql[i]<=qr[i]) printf("%lld : %lld %lld\n",i,ql[i],qr[i]);
			ans+=max(qr[i]-ql[i]+1,0LL);
		}
		// for(int i=1;i<=n;i++) printf("%lld %lld\n",a[i].x,a[i].y);
		// cout<<ans<<endl;
		return ans;
	}
};
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++) t[i].x=read()+100000,t[i].y=read()+100000;
	vector<Node> A,B;
	for(int i=1;i<=n;i++)
	{
		if((t[i].x+t[i].y)%2==0) A.pb(t[i]);
		else t[i].y--,B.pb(t[i]);
	}
	for(int i=0;i<(int)A.size();i++)
	{
		int x=A[i].x,y=A[i].y;
		A[i].x=(x+y)/2,A[i].y=(x-y)/2;
	}
	for(int i=0;i<(int)B.size();i++)
	{
		int x=B[i].x,y=B[i].y;
		B[i].x=(x+y)/2,B[i].y=(x-y)/2;
	}
	int Ax=solve::Main(A),Bx=solve::Main(B);
	cout<<Ax+Bx<<endl;
	return 0;
}