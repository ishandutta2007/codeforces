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
inline char rdchar()
{
	char ch=getchar();
	while(!(ch>='a'&&ch<='z')&&!(ch>='A'&&ch<='Z')&&!(ch>='0'&&ch<='9')) ch=getchar();
	return ch;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 2005
int a[N][N],d[N],id[N],n;
int chk()
{
	for(int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){return d[x]<d[y];});
	int s=0;
	for(int i=1;i<n;i++)
	{
		s+=d[id[i]];
		if(s==i*(i-1)/2) return 0;
	}
	return 1;
}
void flip(int x,int y)
{
	if(a[x][y]) d[x]--;
	else d[x]++;
	a[x][y]^=1;
	if(a[y][x]) d[y]--;
	else d[y]++;
	a[y][x]^=1;
}
void sol()
{
	if(chk()) printf("0 1\n");
	else
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) if(i!=j) flip(i,j);
			if(chk()) cnt++;
			for(int j=1;j<=n;j++) if(i!=j) flip(i,j);
		}
		printf("1 %d\n",cnt);
	}
}
void bf()
{
	int mn=inf,cnt=0;
	for(int i=0;i<1<<(n+1);i+=2)
	{
		for(int j=1;j<=n;j++) if(i>>j&1)
		{
			for(int k=1;k<=n;k++) if(j!=k) flip(j,k);
		}
		if(chk())
		{
			int c=__builtin_popcount(i);
			if(c<mn) mn=c,cnt=0;
			if(c==mn) cnt++;
		}
		for(int j=1;j<=n;j++) if(i>>j&1)
		{
			for(int k=1;k<=n;k++) if(j!=k) flip(j,k);
		}
	}
	for(int i=1;i<=mn;i++) cnt*=i;
	if(mn==inf) printf("-1\n");
	else printf("%d %d\n",mn,cnt);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=rdchar()-'0';
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(a[i][j]) d[i]++;
	// for(int i=1;i<=n;i++) if(i!=3) flip(3,i);
	// cout<<chk()<<endl;
	// return 0;
	if(n>=7) sol();
	else bf();
	return 0;
}