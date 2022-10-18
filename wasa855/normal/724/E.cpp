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
#define int long long
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
#define N 500005
int n,c,a[N],b[N];
signed main()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read(),b[i]=b[i]-a[i]+c*(n-i);
	sort(b+1,b+n+1);
	int sum=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	int ans=sum;
	for(int i=1;i<=n;i++)
	{
		sum=sum+b[i]-(i-1)*c;
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}