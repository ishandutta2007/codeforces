#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
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
#define N 1005
int a[N],used[N];
signed main()
{
	int n=read();
	int maxn=0,k=0;
	for(int i=1;i<=n;i++)
	{
		int R=n/i*(i-1)-(i-1);
		if(n%i!=0) R+=n%i-1;
		if(R>maxn) maxn=R,k=i;
	}
	if(maxn==0) {cout<<0<<endl;	return 0;}
	int cur=0;
	for(int i=1;i<n;i++) if(i%k) used[i]=1;
	while(cur<maxn)
	{
		vector<int> v;
		for(int i=1;i<=n;i++)
		{
			if(!a[i]&&used[i]) v.pb(i),a[i]=1,cur++;
			if(v.size()==k) break;
		}
		cout<<v.size()<<" ";
		for(int i:v) printf("%d ",i); cout<<endl;
		int x=read();
		for(int i=1;i<=(int)v.size();i++)
		{
			if(a[x]) cur--;
			a[x]=0; x++;
			if(x==n+1) x=1;
		}
	}
	cout<<0<<endl;
	return 0;
}