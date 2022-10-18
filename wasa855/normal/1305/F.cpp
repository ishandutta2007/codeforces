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
#define N 200005
int a[N],n,res;
set<int> b;
void getans(int x)
{
//	printf("%lld\n",x);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<x) ans+=x-a[i];
		else
		{
			ans+=min(a[i]%x,x-a[i]%x);
		}
		if(ans>res) return ;
	}
	if(ans<res) res=ans;
}
void xxxx(int x)
{
	if(x<=1) return ;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			if(!b.count(i)) getans(i),b.insert(i);
			while(x%i==0) x/=i;
		}
	}
	if(x!=1)
	{
//		cout<<"***"<<x<<endl;
		b.insert(x);
		getans(x);
	}
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	mt19937 rng(time(NULL));
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	res=n+10;
	getans(2);
	if(res==0)
	{
		cout<<"0\n";
		return 0;
	}
	while((double)clock()/CLOCKS_PER_SEC<=2.2)
	{
		int id=rng()%n+1;
		xxxx(a[id]);
		xxxx(a[id]-1);
		xxxx(a[id]+1);
	}
	cout<<res<<endl;
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}


//