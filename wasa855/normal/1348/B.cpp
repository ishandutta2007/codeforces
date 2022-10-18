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
#define N 10005
int a[N];
void work()
{
	memset(a,0,sizeof(a));
	int n,k; cin>>n>>k; set<int> s;
	for(int i=1;i<=n;i++) a[i]=read(),s.insert(a[i]);
	if((int)s.size()>k) {cout<<"-1\n"; return ;}
	vector<int> v; for(int i:s) v.pb(i);
	while((int)v.size()<k) v.pb(1);
	cout<<n*v.size()<<endl;
	for(int i=1;i<=n;i++) for(int j:v) printf("%d ",j);
	cout<<"\n";
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}