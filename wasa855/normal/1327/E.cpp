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
#define INF 0x3fffffff
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
#define N 200005
int f[N],pw[N];
signed main()
{
	int n=read();
	pw[1]=10; for(int i=2;i<N;i++) pw[i]=mul(pw[i-1],10);
	for(int i=1;i<n;i++)
	{
		int R=mul(81,pw[n-i-1]),S=mul(18,pw[n-i]);
		printf("%d ",add(mul(n-i-1,R),S));
	}
	cout<<10<<endl;
	return 0;
}