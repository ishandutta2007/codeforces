#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
#define N 100005
int a[N],b[N],cnt[N],id[N],n,k,p;
int _p[N];
map<int,int> mp;
int _cnt=0;
int add1(int x) {return x==n?1:x+1;}
int sub1(int x) {return x==1?n:x-1;}
int query(int pos)
{
	printf("? %d\n",pos); fflush(stdout);
	_cnt++;
#ifdef __LOCAL__
	return a[(pos-p+n)%n+1];
#else
	return read();
#endif
}
signed main()
{
#ifdef __LOCAL__
//	p=read();
	n=100000,k=2,p=89745;
#else
	n=read(),k=read();
#endif
	for(int i=1;i<=n;i++) _p[i]=i;
	set<int> s; for(int i=1;i<=n;i++) s.insert(i);
	for(int i=1;i<=n;i++) a[i]=k;
	while(s.size()>150)
	{
		int pos=rnd()%n+1;
		int r=query(pos);
		vector<int> del;
		for(int i:s)
		{
			if(a[(pos-i+n)%n+1]!=r) del.pb(i);
		}
		for(int i:del) s.erase(i);
		for(int i=1;i<=n;i++)
		{
			if(i==1) b[add1(i)]+=a[i];
			else
			{
				b[sub1(i)]+=a[i]/2;
				b[add1(i)]+=(a[i]+1)/2;
			}
		}
		memcpy(a,b,sizeof(a));
		memset(b,0,sizeof(b));
	}
	while(s.size()>1)
	{
		shuffle(_p+1,_p+n+1,rnd);
		int minn=inf,pos=0;
		for(int c=1;c<=min(n,12345);c++)
		{
			int i=_p[c];
			int maxn=0;
			for(int j:s)
			{
				mp[a[(i-j+n)%n+1]]++;
				if(mp[a[(i-j+n)%n+1]]>maxn) maxn=mp[a[(i-j+n)%n+1]];
			}
			if(maxn<minn) minn=maxn,pos=i;
			mp.clear();
		}
		int r=query(pos);
		vector<int> del;
		for(int i:s)
		{
//			printf("%d %d %d\n",i,pos,(i+pos-2)%n+1);
			if(a[(pos-i+n)%n+1]!=r) del.pb(i);
		}
		for(int i:del) s.erase(i);
		for(int i=1;i<=n;i++)
		{
			if(i==1) b[add1(i)]+=a[i];
			else
			{
				b[sub1(i)]+=a[i]/2;
				b[add1(i)]+=(a[i]+1)/2;
			}
		}
		memcpy(a,b,sizeof(a));
		memset(b,0,sizeof(b));
	}
	printf("! %d\n",*s.begin());
	cerr<<_cnt<<endl;
	return 0;
}