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
#define N 100005
int a[N],b[N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=rdchar()-'0';
	for(int i=1;i<=n;i++) b[i]=rdchar()-'0';
	int l=1,r=n,rev=0;
	vector<int> ans;
	for(int i=n;i>1;i--)
	{
		int R=rev?a[r]:a[l]; R^=rev;
		if(R==b[i]) ans.pb(1),ans.pb(i);
		else ans.pb(i);
		if(!rev) l++;
		else r--;
		rev^=1;
	}
	if(rev) a[l]^=1;
	if(a[l]!=b[1]) ans.pb(1);
	cout<<ans.size()<<" ";
	for(int i:ans) printf("%d ",i); cout<<"\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}