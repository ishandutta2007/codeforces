// CF 822D
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
const int mod = 1000*1000*1000+7;
//vector<int> v[5555555];
int g[5555555];
LL f[5555555];
int main()
{
	int t,l,r,i,j,s,x,y;
	LL ans;
	scanf("%d%d%d",&t,&l,&r);
	for(i=2;i<=r;i=i+1){
		f[i]=(LL)i*(i-1)/2;
		x=g[i];
		if(x){
			y=i/x;
			if((LL)x*f[y]+f[x]<f[i])
				f[i]=(LL)x*f[y]+f[x];
			if((LL)y*f[x]+f[y]<f[i])
				f[i]=(LL)y*f[x]+f[y];
		}
		else{
			if((LL)i*i>r)
				continue;;
			for(j=i*i;j<=r;j=j+i)
				if(!g[j])
					g[j]=i;
		}
		//cout<<i<<"     "<<f[i]<<"    "<<f[i]/i<<"     "<<f[i]%i<<endl;
	}
	ans=0;
	for(i=r;i>=l;i=i-1){
		ans=(ans*t+f[i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}
/*
2 2 100
*/