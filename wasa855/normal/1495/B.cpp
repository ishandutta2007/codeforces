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
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
int a[N],l[N],r[N],n;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1]) l[i]=l[i-1]+1;
		else l[i]=1;
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]>a[i+1]) r[i]=r[i+1]+1;
		else r[i]=1;
	}
	int maxn=0;
	for(int i=1;i<=n;i++) maxn=max(maxn,l[i]);
	for(int i=1;i<=n;i++) maxn=max(maxn,r[i]);
	int ans=0;
	for(int i=1;i<=n;i++) ans+=l[i]==maxn,ans+=r[i]==maxn;
	if(ans!=2) {cout<<"0\n"; return 0;}
	ans=0;
	for(int i=2;i<n;i++) if(l[i]==r[i]&&(l[i]&1)&&l[i]==maxn) ans++;
	cout<<ans<<endl;
	return 0;
}