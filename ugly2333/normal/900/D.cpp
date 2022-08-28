//CF 900D
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
const int mod = 1e9+7;
int fpow(LL x,LL p){
	LL res,i;
	res=1,i=1;
	while(p){
		if(p&i)
			res=res*x%mod,p-=i;
		i<<=1;
		x=x*x%mod;
	}
	return res;
}
int a[11111];
LL f[11111];
int main()
{
	int x,y,z,i,j;
	LL ans;
	cin>>x>>y;
	if(y%x){
		cout<<0<<endl;
		return 0;
	}
	y/=x;
	z=0;
	for(i=1;i*i<=y;i=i+1){
		if(y%i)
			continue;
		a[++z]=i;
		if(i*i<y)
			a[++z]=y/i;
	}
	sort(a+1,a+z+1);
	reverse(a+1,a+z+1);
	for(i=1;i<=z;i=i+1){
		f[i]+=fpow(2,y/a[i]-1);
		f[i]%=mod;
		for(j=i+1;j<=z;j=j+1)
			if(a[i]%a[j]==0)
				f[j]+=mod-f[i];
	}
	cout<<f[z]%mod<<endl;
	return 0;
}