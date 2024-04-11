#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;
const ll Mod=1e9+7;
const int maxn=200005;
 
ll a[100005];
ll prime[102005],check[1000000];
ll b[100005],v[1000005],c[maxn],vis[1000005];
int main()
{
	sync;
	int n,k;
	cin>>n>>k;
	int cnt=1;
	for(int i=0;i<=100003;i++)
	{
		b[i]=1;
		v[i]=0;
	}
	for (int i=2;i < 102005; i++) { //i
		if (check[i] == 0) { //i0
			prime[cnt++] = i; //
			vis[i]=1;
		}
		// 
		int j = 1;
		// jnum
		for ( ; j < cnt; j++) {
			if (prime[j]*i > 102000) {
				break;
			}
			check[prime[j]*i] = 1;
			if(i % prime[j] == 0) // 
				break;
		}
	}
	vis[2]=1;
	int g;
	int f=0;
	ll ss=0;
	ll u;
	int ff=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		u=a[i];
		if(vis[u]==0)
		{
			for(int j=1;j<cnt-1&&prime[j]<=u;j++)
			{
				g=0;
				f=0;
				while(a[i]%prime[j]==0)
				{
					g++;
					a[i]/=prime[j];
					u/=prime[j];
				}
				g%=k;
				if(g)
				{
					for(int d=1;d<=k-g;d++)
					{
						b[i]*=prime[j];
						if(b[i]>100000)
						{
							f=1;
							b[i]=12345577;
							a[i]=123433;
							break;
						}
					}
				}
				if(f==1)
					break;
				for(int d=1;d<=g;d++)
				{
					a[i]*=prime[j];
				}
			}
		}
		else 
		{
			for(int d=1;d<=k-1;d++)
			{
				b[i]*=u;
				if(b[i]>100000)
				{
					b[i]=12345577;
					a[i]=123433;
					break;
				}
			}
		}
		if(a[i]==b[i])
			c[a[i]]++;
		else
		{
			if(a[i]<=100000)
			v[a[i]]++;
		}
	}
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
//        cout<<a[i]<<' '<<b[i]<<endl;
		if(b[i]<=100000&&a[i]!=1)
		{
			if(a[i]==b[i])
				continue;
			sum+=v[b[i]];
		}
	}
	sum/=2;
	for(int i=1;i<maxn;i++)
	{
		if(c[i]>1)
			sum+=c[i]*(c[i]-1)/2;
	}
	cout<<sum<<endl;
	return 0;
}