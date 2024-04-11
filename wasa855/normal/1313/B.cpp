#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
void work()
{
	int n,a,b;
	cin>>n>>a>>b;
	if(a+b<=n) cout<<"1 ";
	else cout<<min(a+b+1-n,n)<<" ";
	if(a+b>=n+1) cout<<n<<"\n";
	else cout<<a+b-1<<"\n";
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}