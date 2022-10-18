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
#define mod 1000000007
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
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
void inc(int &x,int y) {x=add(x,y);}
#define N 2005
char s[2][N],t[N];
const int B=13131;
int hs[2][N],ht[N],pw[N];
int lcp[2][2][N][N];
int n,m,f[2][N][N];
void init()
{
	pw[0]=1; for(int i=1;i<N;i++) pw[i]=mul(pw[i-1],B);
	for(int i=0;i<2;i++) for(int j=1;j<=n;j++) hs[i][j]=add(mul(hs[i][j-1],B),s[i][j]);
	for(int i=1;i<=m;i++) ht[i]=add(mul(ht[i-1],B),t[i]);
	for(int i=0;i<2;i++)
	{
		for(int j=1;j<=n;j++) for(int k=1;k<=m;k++)
		{
			if(s[i][j]==t[k]) lcp[0][i][j][k]=lcp[0][i][j-1][k+1]+1;
			else lcp[0][i][j][k]=0;
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=n;j>=1;j--) for(int k=1;k<=m;k++)
		{
			if(s[i][j]==t[k]) lcp[1][i][j][k]=lcp[1][i][j+1][k+1]+1;
			else lcp[1][i][j][k]=0;
		}
	}
}
int geths(int i,int l,int r) {return sub(hs[i][r],mul(hs[i][l-1],pw[r-l+1]));}
int getht(int l,int r) {return sub(ht[r],mul(ht[l-1],pw[r-l+1]));}
int solve()
{
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			int len=2*(i-j)+1;
			if(len<=m&&len!=3)
			{
				for(int o=0;o<2;o++)
				{
//					printf("--- %d %d %d * %d %d * %d %d\n",o,i,len,lcp[0][o^1][i-1][1],i-j,lcp[1][o][j][i-j+1],i-j+1);
					if(lcp[0][o^1][i-1][1]>=i-j&&lcp[1][o][j][i-j+1]>=i-j+1)
					{
						inc(f[o][i][len],1);
//						printf("+++ %d %d %d\n",o,i,len);
					}
				}
			}
			else if(len!=3) break;
		}
		if(i==n) break;
		for(int o=0;o<2;o++)
		{
			for(int k=1;k<=m;k++)
			{
				if(s[o][i+1]==t[k+1]) inc(f[o][i+1][k+1],f[o][i][k]);
				if(s[o^1][i]==t[k+1]&&s[o^1][i+1]==t[k+2]) inc(f[o^1][i+1][k+2],f[o][i][k]);
			}
		}
	}
//	for(int o=0;o<2;o++,cout<<"\n") for(int i=1;i<=n;i++) for(int k=0;k<=m;k++) printf("%d%c",f[o][i][k]," \n"[k==m]);
	int ans=0;
	for(int o=0;o<2;o++) for(int i=1;i<=n;i++)
	{
		ans=add(ans,f[o][i][m]);
		for(int k=1;k<m;k++)
		{
			int ned=m-k+1,len=ned/2;
			if(ned&1) continue;
			if(i+len-1>n) continue;
//			printf("** %d %d %d %d - %d %d * %d\n",o,i,k,f[o][i][k],lcp[1][o][i][k],lcp[0][o^1][i+len-1][k+len],len);
			if(lcp[1][o][i][k]>=len&&lcp[0][o^1][i+len-1][k+len]>=len) ans=add(ans,f[o][i][k]);
		}
	}
//	if(m%2==0)
//	{
//		for(int o=0;o<2;o++) for(int i=1;i+m/2-1<=n;i++)
//		{
//			if(lcp[1][o][i][1]>=m/2&&lcp[0][o^1][i+m/2-1][m/2+1]>=m/2) inc(ans,1);
//		}
//	}
	return ans;
}
signed main()
{
	scanf("%s%s%s",s[0]+1,s[1]+1,t+1);
	n=strlen(s[1]+1),m=strlen(t+1);
	if(m==1)
	{
		int ans=0;
		for(int o=0;o<2;o++) for(int i=1;i<=n;i++) if(s[o][i]==t[1]) ans++;
		cout<<ans<<endl;
		return 0;
	}
	if(m==2)
	{
		int ans=0;
		for(int o=0;o<2;o++)
		{
			for(int i=1;i<n;i++) if(s[o][i]==t[1]&&s[o][i+1]==t[2]) ans++;
			for(int i=1;i<n;i++) if(s[o][i+1]==t[1]&&s[o][i]==t[2]) ans++;
		}
		for(int i=1;i<=n;i++) if(s[0][i]==t[1]&&s[1][i]==t[2]) ans++;
		for(int i=1;i<=n;i++) if(s[0][i]==t[2]&&s[1][i]==t[1]) ans++;
		cout<<ans<<endl;
		return 0;
	}
	init();
	int ans=solve();
	reverse(s[0]+1,s[0]+n+1),reverse(s[1]+1,s[1]+n+1);
	init();
	ans=add(ans,solve());
	cout<<ans<<endl;
	// m=1 & m=2
	return 0;
}