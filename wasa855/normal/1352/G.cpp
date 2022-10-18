#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
int a[]={0,2,4,1,3};
int b[]={0,1,4,2,6,3,5};
void work()
{
	int n=read();
	if(n==2||n==3) {cout<<"-1\n"; return ;}
	int l=n/6,r=n%6;
	if(r==2||r==3) r+=6,l--;
	for(int i=1;i<=l;i++)
	{
		for(int j=1;j<=6;j++) printf("%d ",(i-1)*6+b[j]);
	}
	int k=r/4;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=4;j++) printf("%d ",l*6+(i-1)*4+a[j]);
	}
	if(n&1) cout<<n;
	cout<<"\n";
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}