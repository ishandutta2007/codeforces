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
#define N 25
int f[N][N],a[N],s[N],sa,ss;
void work()
{
	ll A,S; cin>>A>>S;
	sa=ss=0;
	while(A) a[++sa]=A%10,A/=10;
	while(S) s[++ss]=S%10,S/=10;
	int qsa=sa;
	while(sa<ss) a[++sa]=0;
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(int i=0;i<=sa;i++) for(int j=0;j<=ss;j++) if(f[i][j])
	{
		if(s[j+1]>=a[i+1]) f[i+1][j+1]=1;
		if(s[j+2]!=0&&s[j+2]*10+s[j+1]-a[i+1]>=0&&s[j+2]*10+s[j+1]-a[i+1]<=9) f[i+1][j+2]=1;
	}
	while(sa&&!f[sa][ss]) sa--;
	if(sa<qsa) cout<<"-1\n";
	else
	{
		int fl=0;
		while(sa&&ss)
		{
			if(f[sa-1][ss-1])
			{
				int r=s[ss]-a[sa];
				fl|=r;
				if(fl) printf("%d",r);
				ss--,sa--;
			}
			else if(f[sa-1][ss-2])
			{
				int r=s[ss]*10+s[ss-1]-a[sa];
				fl|=r;
				printf("%d",r);
				ss-=2,sa--;
			}
			else assert(0);
		}
		cout<<"\n";
	}
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}