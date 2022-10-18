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
inline char rdchar()
{
	char ch=getchar();
	while(!(ch>='a'&&ch<='z')&&!(ch>='A'&&ch<='Z')&&!(ch>='0'&&ch<='9')) ch=getchar();
	return ch;
}
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 2005
bitset<N> f[N];
int n,Q,m,a[N],b[N],ans[N];
char opt[10];
vector<int> rdvector()
{
	int s=read(); vector<int> v(s);
	for(int i=0;i<s;i++) v[i]=read();
	return v;
}
signed main()
{
	cin>>n>>Q;
	for(int i=1;i<=n;i++) a[i]=1,b[i]=2;
	while(Q--)
	{
		scanf("%s",opt+1);
		if(opt[1]=='m')
		{
			vector<int> v=rdvector();
			int ans; char ch=rdchar();
			if(ch=='R') ans=1;
			else if(ch=='Y') ans=2;
			else if(ch=='B') ans=3;
			else ans=0;
			m++; for(int i:v)
			{
				if(a[i]&1) f[m][i]=1;
				if(a[i]>>1) f[m][i+n]=1;
			}
			f[m][2*n+1]=ans&1;
			m++; for(int i:v)
			{
				if(b[i]&1) f[m][i]=1;
				if(b[i]>>1) f[m][i+n]=1;
			}
			f[m][2*n+1]=ans>>1;
		}
		else if(opt[1]=='R'&&opt[2]=='Y')
		{
			vector<int> v=rdvector();
			for(int i:v) swap(a[i],b[i]);
		}
		else if(opt[1]=='R'&&opt[2]=='B')
		{
			vector<int> v=rdvector();
			for(int i:v) b[i]^=a[i];
		}
		else
		{
			vector<int> v=rdvector();
			for(int i:v) a[i]^=b[i];
		}
		// cout<<Q<<" :\n";
		// for(int i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
		// for(int i=1;i<=n;i++) printf("%d%c",b[i]," \n"[i==n]);
	}
	// for(int i=1;i<=m;i++) for(int j=1;j<=n*2+1;j++) printf("%d%c",(int)f[i][j]," \n"[j==n*2+1]);
	int cur=1;
	for(int i=1;i<=n*2;i++)
	{
		int pos=0;
		for(int j=cur;j<=m;j++) if(f[j][i]) {pos=j; break;}
		if(!pos) continue;
		swap(f[pos],f[cur]);
		for(int j=cur+1;j<=m;j++) if(f[j][i]) f[j]^=f[cur];
		cur++;
	}
	// for(int i=1;i<=m;i++) for(int j=1;j<=n*2+1;j++) printf("%d%c",(int)f[i][j]," \n"[j==n*2+1]);
	for(int i=cur;i<=m;i++) if(f[i][n*2+1]) {cout<<"NO\n"; return 0;}
	cout<<"YES\n";
	for(int i=cur-1;i>=1;i--)
	{
		int beg=n*2; for(int j=n*2;j>=1;j--) if(f[i][j]) beg=j;
		if(beg>n) ans[beg-n]|=f[i][n*2+1]*2;
		else ans[beg]|=f[i][n*2+1];
		for(int j=i-1;j>=1;j--) if(f[j][beg]) f[j][n*2+1]=f[j][n*2+1]^f[i][n*2+1];
	}
	for(int i=1;i<=n;i++) printf("%c",".RYB"[ans[i]]);
	cout<<"\n";
	return 0;
}