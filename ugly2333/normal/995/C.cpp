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
const int N = 111111;
const LL inf = (LL)1500000*1500000;
LL dis(int x,int y){
	return (LL)x*x+(LL)y*y;
}
int n,x[N],y[N],z[N],p[N];
int main()
{
	srand(19260817);
	int i,j,a,b;
	scanf("%d",&n);
	for(i=0;i<n;i=i+1){
		scanf("%d%d",x+i,y+i);
		p[i]=i;
	}
	while(1){
		random_shuffle(p,p+n);
		a=0,b=0;
		for(j=0;j<n;j=j+1){
			i=p[j];
			if(dis(a+x[i],b+y[i])<dis(a-x[i],b-y[i]))
				a+=x[i],b+=y[i],z[i]=1;
			else
				a-=x[i],b-=y[i],z[i]=-1;
		}
		if(dis(a,b)<=inf)
			break;
	}
	for(i=0;i<n;i=i+1)
		cout<<z[i]<<' ';
	return 0;
}