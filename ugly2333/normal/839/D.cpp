//CF 839D
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
typedef long long LL;
const int m = 1e6;
const int mod = 1e9+7;
int a[222222],s[1111111],t[1111111],p2[222222];
int main()
{
	int n,i,j;
	LL ans;
	scanf("%d",&n);
	p2[0]=1;
	memset(s,0,sizeof(s));
	for(i=1;i<=n;i=i+1){
		p2[i]=(p2[i-1]*2)%mod;
		scanf("%d",a+i);
		for(j=1;j*j<=a[i];j=j+1){
			if(a[i]%j==0){
				s[j]++;
				if(j*j!=a[i])
					s[a[i]/j]++;
			}
		}
	}
	for(i=1;i<=m;i=i+1)
		if(s[i])
			t[i]=(LL)s[i]*p2[s[i]-1]%mod;
	for(i=m;i>=2;i=i-1){
		if(!s[i])
			continue;
		//cout<<t[i]<<endl;
		for(j=2;j*j<=i;j=j+1){
			if(i%j==0){
				t[j]=(t[j]-t[i]+mod)%mod;
				if(j*j!=i)
					t[i/j]=(t[i/j]-t[i]+mod)%mod;
			}
		}
	}
	ans=0;
	for(i=2;i<=m;i=i+1){
		ans=(ans+(LL)i*t[i]%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}