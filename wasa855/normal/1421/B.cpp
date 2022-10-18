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
#define N 205
char s[N][N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	int A=s[1][2]-'0',B=s[2][1]-'0',C=s[n-1][n]-'0',D=s[n][n-1]-'0';
	vector<pii> ans;
	if(A+B==2)
	{
		if(C==1) ans.eb(n-1,n);
		if(D==1) ans.eb(n,n-1);
	}
	else if(A+B==0)
	{
		if(C==0) ans.eb(n-1,n);
		if(D==0) ans.eb(n,n-1);
	}
	else if(C+D==2)
	{
		if(A==1) ans.eb(1,2);
		if(B==1) ans.eb(2,1);
	}
	else if(C+D==0)
	{
		if(A==0) ans.eb(1,2);
		if(B==0) ans.eb(2,1);
	}
	else
	{
		if(A==0) ans.eb(1,2);
		if(B==0) ans.eb(2,1);
		if(C==1) ans.eb(n-1,n);
		if(D==1) ans.eb(n,n-1);
	}
	cout<<ans.size()<<endl;
	for(auto [x,y]:ans) printf("%d %d\n",x,y);
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}