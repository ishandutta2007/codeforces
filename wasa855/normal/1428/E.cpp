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
#define N 100005
int calc(int x,int y)
{
	if(x<y) return INF;
	int D=x/y,B=x%y,A=y-x%y;
	return A*D*D+B*(D+1)*(D+1);
}
struct Node
{
	int pos,cnt,val;
	Node(int a=0,int b=0,int c=0){pos=a,cnt=b,val=c;}
	bool operator < (const Node &x) const {return val<x.val;}
};
int a[N];
signed main()
{
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	priority_queue<Node> q;
	for(int i=1;i<=n;i++) q.emplace(i,1,calc(a[i],1)-calc(a[i],2));
	int ans=0; for(int i=1;i<=n;i++) ans+=a[i]*a[i];
	for(int i=n+1;i<=k;i++)
	{
		Node x=q.top(); q.pop();
		ans-=x.val;
		x.cnt++; x.val=calc(a[x.pos],x.cnt)-calc(a[x.pos],x.cnt+1);
		q.push(x);
	}
	cout<<ans<<endl;
	return 0;
}