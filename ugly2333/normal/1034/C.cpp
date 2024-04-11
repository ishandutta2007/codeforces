//CF 1034C
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
const int MO = 1e9+7;
LL gcd(LL x,LL y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
int n,a[N],p[N],b[N];
LL s[N],f[N];
int main()
{
	int i,j,k,o;
	LL x;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i),s[i]=a[i];
	for(i=2;i<=n;i=i+1)
		scanf("%d",p+i);
	for(i=n;i>1;i=i-1)
		s[p[i]]+=s[i];
	for(i=1;i<=n;i=i+1){
		x=s[1]/gcd(s[1],s[i]);
		if(x<=n)
			b[x]++;
	}
	for(i=n;i;i=i-1)
		for(j=i+i;j<=n;j=j+i)
			b[j]+=b[i];
	f[1]=1;
	x=0;
	for(i=1;i<=n;i=i+1){
		if(b[i]!=i)
			continue;
		f[i]%=MO;
		x+=f[i];
		for(j=i+i;j<=n;j=j+i)
			f[j]+=f[i];
	}
	cout<<x%MO;
	return 0;
}