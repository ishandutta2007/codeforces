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
#define N 200005
int a[N],sum[N];
void work()
{
	int n,p,k; cin>>n>>p>>k;
	for(int i=1;i<=n;i++) a[i]=rdchar()-'0';
	int x=read(),y=read();
	int ans=inf;
	for(int i=n;i>=p;i--)
	{
		sum[i]=sum[i+k];
		if(!a[i]) sum[i]++;
		ans=min(ans,sum[i]*x+(i-p)*y);
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) sum[i]=0;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}