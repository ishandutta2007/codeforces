#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
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
#define N 800005
int a[N],b[N];
vector<int> v[N];
signed main()
{
#ifdef __LOCAL__
//	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		int X=a[i]-i+200000;
		v[X].pb(i);
	}
	int ans=0;
	for(int i=0;i<N;i++)
	{
		int cur=0;
		for(int j:v[i]) cur+=a[j];
		if(cur>ans) ans=cur;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}