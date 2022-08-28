//CF1053D
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
const int N = 2e6+26;
const int MO = 1e9+7;
int n,a[N],b[N],c[N],d[N],e[N],r[N];
int main()
{
	int i,j,x,f;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		a[x]++;
	}
	n=2e6;
	for(i=2;i<=n;i=i+1)
		for(j=i+i;j<=n;j=j+i)
			e[j]=1;
	for(i=n;i>1;i=i-1){
		if(!a[i])
			continue;
		a[i]--;
		x=0;
		for(j=i;j<=n;j=j+i)
			x|=b[j];
		if(x)
			b[i-1]++;
		else
			b[i]++;
		i++;
	}
	for(i=1;i<=n;i=i+1)
		for(j=i;j<=n;j=j+i)
			if(b[j])
				c[i]+=b[j],d[i]=j;
	f=1;
	for(i=2;i<=n;i=i+1){
		if(e[i])
			continue;
		x=1;
		while((LL)x*i<=n&&c[x*i]){
			x*=i;
		}
		f=(LL)f*x%MO;
		if(c[x]==1)
			r[d[x]]=1;
	}
	for(i=1;i<=n;i=i+1){
		if(b[i]&&!r[i]){
			f++;
			break;
		}
	}
	cout<<f%MO;
	return 0;
}