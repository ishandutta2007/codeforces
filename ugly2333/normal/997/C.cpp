//CF 995C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1e6+16;
const int MO = 998244353;
int fpow(int x,int y=MO-2){
	LL z=1;
	while(y){
		if(y&1)
			z=z*x%MO;
		x=(LL)x*x%MO;
		y>>=1;
	}
	return z;
}
int pw[N],f[N],g[N];
int main()
{
	int n,i,w,q,s,t,c,x,y;
	cin>>n;
	pw[0]=1;
	for(i=1;i<=n;i=i+1)
		pw[i]=(LL)pw[i-1]*3%MO;
	w=pw[n];
	q=fpow(w,n);
	s=q-fpow(w-3,n)+MO;
	s=(LL)s*2%MO;
	t=0;
	c=1;
	//cout<<s<<endl;
	for(i=1;i<=n;i=i+1){
		c=(LL)c*(n-i+1)%MO*fpow(i)%MO;
		y=(LL)fpow(pw[n-i],n)-fpow(pw[n-i]-1,n)+MO;
		f[i]=c,g[i]=y%MO;
		//cout<<i<<' '<<f[i]<<' '<<g[i]<<endl;
		x=(LL)f[i]*g[i]%MO;
		if(i&1)
			t=(t+x)%MO;
		else
			t=(t-x+MO)%MO;
	}
	s-=(LL)t*3%MO;
	s=(s+MO)%MO;
	cout<<s<<endl;
	return 0;
}