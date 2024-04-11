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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 1000005
int pos[N],a[N],b[N],sa[N],sb[N],rp[N],n,fl;
vector<int> A,B;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read(),sa[i]=sa[i-1]+a[i];
	for(int i=1;i<=n;i++) b[i]=read(),sb[i]=sb[i-1]+b[i];
	if(sa[n]>sb[n])
	{
		for(int i=1;i<=n;i++) swap(a[i],b[i]),swap(sa[i],sb[i]);
		fl=1;
	}
	memset(rp,-1,sizeof(rp));
	int cur=0;
	for(int i=0;i<=n;i++)
	{
		while(sa[i]>sb[cur]) cur++;
		// printf("** %d %d\n",sa[i],sb[cur]);
		pos[i]=cur; int q=sb[cur]-sa[i];
		// printf("%d : %d %d\n",i,cur,q);
		if(rp[q]!=-1)
		{
			int L=rp[q],R=i;
			// printf("%d %d\n",pos[L],pos[R]);
			for(int i=L+1;i<=R;i++) A.pb(i);
			for(int i=pos[L]+1;i<=pos[R];i++) B.pb(i);
			break;
		}
		else rp[q]=i;
	}
	if(fl) swap(A,B);
	cout<<A.size()<<endl;
	print(A);
	cout<<B.size()<<endl;
	print(B);
	return 0;
}