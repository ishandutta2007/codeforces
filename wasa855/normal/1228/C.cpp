#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
#define mod 1000000007
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
int kasumi(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int x,n;
	cin>>x>>n;
	int ans=1;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			int sum=0;
			int y=1;
			while(1)
			{
				if((double)y*(double)i>3e18) break;
				y*=i;
				sum=(sum+n/y)%(mod-1);
			}
//			cout<<sum<<endl;
			ans=ans*kasumi(i,sum)%mod;
//			cout<<ans<<endl;
			while(x%i==0) x/=i;
		}
	}
	if(x!=1)
	{
		int sum=0;
		int y=1;
		while(1)
		{
			if((double)y*(double)x>3e18) break;
			y*=x;
			sum=(sum+n/y)%(mod-1);
		}
		ans=ans*kasumi(x,sum)%mod;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}