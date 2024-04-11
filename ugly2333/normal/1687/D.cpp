//CF1687D
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
const int N = 6e6+66;
int n,m=6e6,a[N],l[N],r[N];
int main()
{
	int i,j,x,y,z,f,g;
	scanf("%d",&n);
	//n=9e5;
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		//a[i]=i*2;
		l[a[i]]=a[i],r[a[i]]=a[i];
	}
	l[0]=-1,r[0]=-1,l[m]=N,r[m]=N;
	for(i=1;i<=m;i++)
		if(!l[i])
			l[i]=l[i-1];
	for(i=m;i>=1;i--)
		if(!r[i])
			r[i]=r[i+1];
	for(i=2;1;i++){
		if((LL)a[1]>(LL)i*(i-1))
			continue;
		f=0,g=i-1;
		if((LL)a[1]>(LL)(i-1)*(i-1))
			f=a[1]-(LL)(i-1)*(i-1);
		x=a[1];
		j=i;
		//cout<<i<<' '<<f<<' '<<g<<endl;
		while(x<=a[n]){
			y=x+j;
			z=y+j-1;
			if(l[y-1]>=x)
				g=min(g,y-1-l[y-1]);
			if(r[y]<z)
				f=max(f,z-r[y]);
			x=z;
			j++;
		}
		if(f<=g){
			printf("%lld\n",(LL)(i-1)*(i-1)-a[1]+f);
			return 0;
		}
	}
	return 0;
}