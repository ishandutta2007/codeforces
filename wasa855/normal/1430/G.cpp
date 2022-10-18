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
#define ll long long
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
#define N 18
int u[N*N],v[N*N],w[N*N];
int val[1<<N],f[1<<N],fr[1<<N];
bool ok[1<<N],qaq[1<<N];
int a[N];
int n,m;
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) u[i]=read()-1,v[i]=read()-1,w[i]=read();
	for(int i=0;i<1<<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int A=i>>u[j]&1,B=i>>v[j]&1;
			if(A&&B) ok[i]=1;
			if(A&&!B) val[i]+=w[j];
			if(!A&&B) qaq[i]=1;
		}
	}
	memset(f,0x3f,sizeof(f)); f[0]=0;
	for(int i=1;i<1<<n;i++)
	{
		if(qaq[i]) continue;
		for(int j=i;j!=0;j=(j-1)&i)
		{
			if(!ok[j])
			{
				if(f[i^j]<f[i]) f[i]=f[i^j],fr[i]=i^j;
			}
		}
		f[i]+=val[i];
	}
	int tmp=(1<<n)-1;
	int cur=0;
	while(tmp)
	{
		int x=tmp^fr[tmp]; tmp=fr[tmp];
		for(int i=0;i<n;i++) if(x>>i&1) a[i]=cur;
		cur++;
	}
	for(int i=0;i<n;i++) printf("%d%c",a[i]," \n"[i==n-1]);
	return 0;
}