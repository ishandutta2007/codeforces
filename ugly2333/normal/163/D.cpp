//CF 163D
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
const int K = 111;
const int M = 1e6+7;
const int Q = 1e9+7;
LL p[K];
int c[K];
int a[M];
LL ans,tx,ty,tz;
void calc(LL x,LL y,LL z){
	LL res;
	res=(LL)x*y+y*z+z*x;
	if(res<ans){
		ans=res;
		tx=x;
		ty=y;
		tz=z;
	}
}
int main()
{
	int T,i,j,k,l,m;
	LL n,x,h,o,r;
	cin>>T;
	while(T--){
		cin>>k;
		n=1;
		m=1;
		a[1]=1;
		for(i=1;i<=k;i=i+1){
			cin>>p[i]>>c[i];
			for(j=1;j<=c[i];j=j+1)
				n*=p[i];
			o=m;
			for(l=1;l<=o;l=l+1){
				x=1;
				for(j=1;j<=c[i];j=j+1){
					x*=p[i];
					if((LL)x*a[l]>Q)
						break;
					else
						a[++m]=a[l]*x;
				}
			}
		}
		ans=(LL)n*2+1;
		tx=1,ty=1,tz=n;
		sort(a+1,a+m+1);
		r=1;
		for(i=m;i>=1;i=i-1){
			//cout<<a[i]<<endl;
			h=a[i];
			if(h>M||(LL)n/h+(LL)2*sqrt(n)*sqrt(h)>ans)
				continue;
			o=n/h;
			while(r<=m&&(LL)a[r]*a[r]<=o){
				r++;
			}
			r--;
			for(j=r;j>=i;j=j-1){
				if(o%a[j]==0){
					calc(a[i],a[j],o/a[j]);
					break;
				}
			}/**/
		}
		cout<<ans*2<<' '<<tx<<' '<<ty<<' '<<tz<<endl;
	}
	return 0;
}
/*
*/