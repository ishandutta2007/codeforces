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
#define N 5005
int a[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	if(m==0)
	{
		for(int i=1;i<=n;i++) printf("%d ",2*i-1); cout<<"\n";
		return 0;
	}
	int cur=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=i; cnt++;
		cur+=((i+1)/2)-1;
		if(cur>=m)
		{
			cur-=(((i+1)/2)-1);
			int ned=m-cur;
			int X=i-2*ned;
			a[i]=a[X]+a[i-1];
			cur=m;
			break;
		}
	}
	if(cur<m)
	{
		cout<<"-1\n";
		return 0;
	}
	int dif=a[cnt]; if(dif%2==1) dif++;
	int las=a[cnt]+a[cnt-1]; if(las%2==0) las++;
	for(int i=cnt+1;i<=n;i++)
	{
		a[i]=las+dif;
		las=a[i];
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}