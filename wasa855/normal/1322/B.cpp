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
#define N 400005
int a[N],n,b[N];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	int ans=0;
	for(int i=24;i>=0;i--)
	{
		for(int j=1;j<=n;j++) b[j]=a[j]%(1<<i+1);
		sort(b+1,b+n+1);
		// for(int j=1;j<=n;j++) printf("%d ",b[j]); cout<<"\n";
		ll cnt=0;
		int r=n+1;
		for(int j=1;j<=n;j++)
		{
			while(b[j]+b[r-1]>=(1<<i)&&r>=2) r--;
			int R=(n-r+1); cnt+=R;
		}
		// cout<<cnt<<endl;
		r=n+1;
		for(int j=1;j<=n;j++)
		{
			while(b[j]+b[r-1]>=(1<<i+1)&&r>=2) r--;
			int R=(n-r+1); cnt-=R;
		}
		// cout<<cnt<<endl;
		r=n+1;
		for(int j=1;j<=n;j++)
		{
			while(b[j]+b[r-1]>=((1<<i+1)+(1<<i))&&r>=2) r--;
			int R=(n-r+1); cnt+=R;
		}
		// cout<<cnt<<endl;
		for(int j=1;j<=n;j++)
		{
			if((b[j]+b[j]>=(1<<i)&&b[j]+b[j]<(1<<i+1))||(b[j]+b[j]>=((1<<i+1)+(1<<i))&&b[j]+b[j]<=(1<<i+2))) cnt--;
		}
		// cout<<cnt<<endl;
		cnt=(cnt/2)&1;
		if(cnt) ans|=(1<<i);
	}
	cout<<ans<<endl;
	return 0;
}