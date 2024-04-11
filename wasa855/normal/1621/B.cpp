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
#define N 100005
int l[N],r[N],c[N],n;
void work()
{
	cin>>n;
	for(int i=1;i<=n;i++) l[i]=read(),r[i]=read(),c[i]=read();
	int ans=INT_MAX,A=inf,B=inf;
	int mn=inf,mx=0;
	for(int i=1;i<=n;i++)
	{
		if(l[i]<mn) mn=l[i],ans=INT_MAX,A=inf;
		if(r[i]>mx) mx=r[i],ans=INT_MAX,B=inf;
		if(l[i]==mn&&r[i]==mx) ans=min(ans,c[i]);
		if(l[i]==mn) A=min(A,c[i]);
		if(r[i]==mx) B=min(B,c[i]);
		printf("%d\n",min(ans,A+B));
	}
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}