#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
#define N 200005
int a[N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	bool as=1;
	for(int i=1;i<n;i++) as&=(a[i]==a[i+1]);
	if(as)
	{
		cout<<"1\n";
		for(int i=1;i<=n;i++) printf("1 ");
		putchar('\n');
		return ;
	}
	if(n%2==0)
	{
		cout<<"2\n";
		for(int i=1;i<=n;i++) printf("%d ",i%2+1);
		putchar('\n');
		return ;
	}
	int pl=0;
	a[n+1]=a[1];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1]) pl=i;
	}
	if(pl)
	{
		cout<<"2\n";
		for(int i=1;i<=pl;i++) printf("%d ",i%2+1);
		for(int i=pl+1;i<=n;i++) printf("%d ",(i+1)%2+1);
		putchar('\n');
		return ;
	}
	cout<<"3\n";
	for(int i=1;i<n;i++) printf("%d ",i%2+1);
	printf("3\n");
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}