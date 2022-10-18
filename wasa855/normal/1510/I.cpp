#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false)
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
int distribute(vector<ll> a)
{
	ll sum=0; for(int i=0;i<(int)a.size();i++) sum+=a[i];
	ll id=rnd()%sum;
	for(int i=0;i<(int)a.size();i++)
	{
		if(id-a[i]<0) return i;
		id-=a[i];
	}
	assert(0);
} 
#define N 10005
int wacnt[N],a[N],n,m,re,mywa;
int val[N];
char s[N];
ll f(int x) {return val[x];}
signed main()
{
	cin>>n>>m;
	for(int i=0;i<=20;i++) val[i]=pow(20-i,3);
//	for(int i=5;i<=100;i++) val[i]=pow(200-i,2.5);
//	for(int i=100;i<=1000;i++) val[i]=pow(2000-i,1.5);
//	for(int i=1000;i<=10000;i++) val[i]=20000-i;
	for(int i=1;i<=m;i++)
	{
#ifdef __LOCAL__
		re=rnd()&1;
		for(int j=0;j<n;j++) a[j]=rnd()&1;
//		a[0]=a[1]=re;
//		if(rnd()%5==0) a[0]^=1;
//		if(rnd()%5==0) a[1]^=1;
#else
		scanf("%s",s);
		for(int j=0;j<n;j++) a[j]=s[j]-'0';
#endif
		vector<ll> v(n); int maxn=0;
		for(int j=0;j<n;j++) maxn=max(maxn,i-wacnt[j]);
		for(int j=0;j<n;j++) v[j]=f(maxn-(i-wacnt[j]));
		int id=distribute(v);
#ifdef __LOCAL__
//		print(v); cout<<id<<endl;
		mywa+=a[id]!=re;
#else
		cout<<a[id]<<endl;
		re=read();
		mywa+=a[id]!=re;
#endif
		for(int j=0;j<n;j++) wacnt[j]+=a[j]!=re;
	}
#ifdef __LOCAL__
	int minn=inf;
	for(int i=0;i<n;i++) minn=min(minn,wacnt[i]);
	printf("minn : %lld\n",minn);
	printf("lim  : %lld\n",(int)(1.3*minn+100));
	printf("my   : %lld\n",mywa);
#endif
	return 0;
}