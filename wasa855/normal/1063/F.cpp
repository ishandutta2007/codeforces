#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#pragma GCC target("popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("no-stack-protector")
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
#define mod 916761323
#define B 372021921
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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1uLL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 500005
char s[N];
int n;
int pw[N],val[N];
inline int gethash(int l,int r){return sub(val[r],mul(val[l-1],pw[r-l+1]));}
struct Bitset
{
	typedef unsigned long long ull;
	int tmp[N],tp;
	ull tb[(mod/64)+5];
	inline bool find(int x){return tb[x>>6]&(1uLL<<(x&63));}
	inline void insert(int x){tb[x>>6]|=1uLL<<(x&63),tmp[++tp]=x;}
	inline void erase(int x){tb[x>>6]&=~(1uLL<<(x&63));}
	void clear()
	{
		for(int i=1;i<=tp;i++) erase(tmp[i]);
		tp=0;
	}
}b;
bool ok[N],tmp[N];
int t[N];
signed main()
{
	cin>>n; scanf("%s",s+1);
	pw[0]=1; for(int i=1;i<N;i++) pw[i]=mul(pw[i-1],B);
	for(int i=1;i<=n;i++) val[i]=add(mul(val[i-1],B),s[i]-'a');
	for(int i=1;i<=n;i++) ok[i]=1;
	for(int i=2;i<=1000;i++)
	{
		if(n<i)
		{
			cout<<i-1<<endl;
			return 0;
		}
		memset(tmp,0,(n+3));
		for(int j=1;j+i-2<=n;j++) t[j]=gethash(j,j+i-2);
		for(int j=n-i;j>=1;j--)
		{
			if(ok[j+i]) b.insert(t[j+i]);
			tmp[j]=b.find(t[j])||b.find(t[j+1]);
		}
		memcpy(ok,tmp,(n+3));
		bool Ok=0;
		for(int j=1;j<=n-i+1;j++) Ok|=ok[j];
		if(!Ok)
		{
			cout<<i-1<<endl;
			return 0;
		}
		b.clear();
		n-=i-1;
	}
	cout<<1000<<endl;
	return 0;
}