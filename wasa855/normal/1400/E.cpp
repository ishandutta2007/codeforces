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
#define N 5005
int a[N],n;
int solve(int l,int r,int val)
{
	if(l>r) return 0;
	if(l==r)
	{
		if(a[l]==val) return 0;
		else return 1;
	} 
	int minn=inf;
	for(int i=l;i<=r;i++) minn=min(minn,a[i]);
	int las=l,ans=minn-val;
	for(int i=l;i<=r;i++)
	{
		if(a[i]==minn) ans+=solve(las,i-1,minn),las=i+1;
	}
	ans+=solve(las,r,minn);
	return min(ans,r-l+1);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	cout<<solve(1,n,0)<<endl;
	return 0;
}