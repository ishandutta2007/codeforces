//CF1408A
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
int n,p,l,r,vl,vr,a[N];
DB tl,tr,t1,t2,t;
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&p);
		for(i=1;i<=n;i=i+1)
			scanf("%d",a+i);
		a[0]=0,a[n+1]=p;
		l=0,r=n+1;
		vl=1,vr=1;
		tl=0,tr=0;
		while(r-l>1){
			t1=tl+(DB)(a[l+1]-a[l])/vl;
			t2=tr+(DB)(a[r]-a[r-1])/vr;
			if(t1<t2){
				l++;
				vl++;
				tl=t1;
			}
			else{
				r--;
				vr++;
				tr=t2;
			}
		}
		t=a[r]-a[l];
		if(tl<tr)
			t-=(tr-tl)*vl;
		else
			t-=(tl-tr)*vr;
		t/=(DB)(vl+vr);
		printf("%.9lf\n",max(tl,tr)+t);
	}
	return 0;
}