#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 3000005
char s[N];
vector<int> v[N];
int n,k;
signed main()
{
	cin>>n>>k;
	scanf("%s",s+1);
	bool ok=1;
	int minn=0,maxn=0;
	while(ok)
	{
		ok=0; minn++;
		for(int i=1;i<n;i++) if(s[i]=='R'&&s[i+1]=='L') v[minn].pb(i),maxn++,ok=1;
		for(int i=0;i<(int)v[minn].size();i++) swap(s[v[minn][i]],s[v[minn][i]+1]);
		if(!ok) minn--;
	}
	if(k<minn||k>maxn)
	{
		cout<<"-1\n";
		return 0;
	}
	for(int i=1;i<=minn;i++)
	{
		k--;
		int res=k-minn+i;
		int to=min(res,(int)v[i].size()-1);
		for(int j=0;j<to;j++) printf("%d %d\n",1,v[i][j]),k--;
		printf("%d ",(int)v[i].size()-to);
		for(int j=to;j<(int)v[i].size();j++) printf("%d ",v[i][j]); cout<<"\n";
	}
	return 0;
}