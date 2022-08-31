//CF 803E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
const int mod = 1e9+7;
int a[111111],b[111111],p2[111111],f[111111];
long long ans;
int main()
{
	int n,i,j,s;
	cin>>n;
	p2[0]=1;
	for(i=1;i<=n;i=i+1)
	{
		cin>>a[i];
		b[a[i]]++;
		p2[i]=p2[i-1]*2;
		p2[i]%=mod;
	}
	for(i=1;i<=100000;i=i+1)
		f[i]=2;
	f[1]=2;
	for(i=2;i<=100000;i=i+1)
		for(j=2*i;j<=100000;j=j+i)
			f[j]-=f[i]-3;
	ans=p2[n]-1;
	for(i=2;i<=333;i=i+1){
		s=0;
		for(j=1;j<=n;j=j+1)
			if(a[j]%i==0)
				s++;
		ans+=(long long)(p2[s]-1)*(f[i]-3);
		ans+=(long long)100*mod;
		ans=ans%mod;
		//if(s!=0)
			//cout<<i<<' '<<f[i]<<' '<<ans<<endl;
	}
	//cout<<ans<<endl;
	for(i=334;i<=100000;i=i+1){
		s=0;
		for(j=i;j<=100000;j=j+i)
			s+=b[j];
		ans+=(long long)(p2[s]-1)*(f[i]-3);
		ans+=(long long)100*mod;
		ans=ans%mod;
	}
	cout<<(ans+(long long)1000*mod)%mod<<endl;
	return 0;
}