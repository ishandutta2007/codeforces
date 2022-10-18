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
int mod;
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
struct FastMod
{
	typedef unsigned long long ull;
	typedef __uint128_t lll;
	ull b,m;
	void init(ull b) {this->b=b,m=ull((lll(1)<<64)/b);}
	ull operator()(ull a)
	{
		ull q=(ull)((lll(m)*a)>>64),r=a-q*b;
		return r>=b?r-b:r;
	}
}M;
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return M(1ULL*x*y);}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
#define N 4000005
int n;
struct BIT
{
	int len,t[N];
	void init(int l){len=l,memset(t,0,sizeof(t));}
	inline int lowbit(int x){return x&(-x);}
	void update(int u,int v){for(int i=u;i<=len;i+=lowbit(i)) t[i]=add(t[i],v);}
	int query(int u)
	{
		int ans=0;
		for(int i=u;i>0;i-=lowbit(i)) ans=add(ans,t[i]);
		return ans;
	}
	int query(int l,int r) {return sub(query(r),query(l-1));}
}bit;
int f[N];
signed main()
{
	cin>>n>>mod;
	f[n]=1; bit.init(n),bit.update(n,1);
	int sum=1;
	for(int i=n-1;i>=1;i--)
	{
		f[i]=sum;
		for(int j=2;i*j<=n;j++)
		{
			int L=i*j,R=min(n,(i+1)*j-1);
			f[i]=add(f[i],bit.query(L,R));
		}
		sum=add(sum,f[i]);
		bit.update(i,f[i]);
	}
	cout<<f[1]<<endl;
	return 0;
}