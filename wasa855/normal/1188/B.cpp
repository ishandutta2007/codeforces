#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 300005
int a[N];
map<int,int> mp;
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n,p,k;
	cin>>n>>p>>k;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		int x=a[i]*a[i]%p*a[i]%p*a[i]%p-k*a[i]%p;
		x=(x+p)%p;
		ans+=mp[x];
		mp[x]++;
	}
	cout<<ans<<endl;
	return 0;
}

//asasef