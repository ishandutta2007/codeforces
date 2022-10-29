#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
const int N = 1e5+10;
const double pi = acos(-1);
 
pair<double, double> a[N],inter[N<<1]; 
double d[N],ang[N];
int n,m,f[N],f1[N],g[N],g1[N];
 
bool check(double r,int m){
	rep(i,1,n){
		double ang1 = acos(r/d[i]);
		inter[i] = MP(ang[i]+ang1, ang[i]-ang1);//first:r; second:l
		if(inter[i].first>pi*2) inter[i].first-=pi*2,inter[i].second-=pi*2;
	}
	sort(inter+1,inter+n+1);
	rep(i,1,n) inter[i+n] = MP(inter[i].first+pi*2, inter[i].second+pi*2);
	int j=1;
	rep(i,1,n){
		for(;inter[j].second<=inter[i].first&&j<n*2;++j);
		f[i] = j, g[i] = i;
	}
	for(int x=1;m;x<<=1){
		if(m&x){
			rep(i,1,n){
				g1[i] = g[(f[i]-1)%n+1] + (f[i]-1)/n*n;
				if(g1[i]>=n+i) return true;
			}
			m -= x;
			memcpy(g,g1,sizeof g);
		}
		rep(i,1,n) f1[i] = f[(f[i]-1)%n+1] + (f[i]-1)/n*n;
		memcpy(f,f1,sizeof f);
	}
	return false;
}
 
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%lf%lf",&a[i].first,&a[i].second);
	double l=0, r=2e5;
	rep(i,1,n){
		d[i] = sqrt(a[i].first*a[i].first+a[i].second*a[i].second);
		ang[i] = acos(a[i].first/d[i]);
		if(a[i].second<0) ang[i]=2*pi-ang[i];
		r = min(r, d[i]);
	}
	while(r-l>2e-7){
		double mid = (l+r)/2;
		if(check(mid,m)) l=mid;
		else r=mid;
	}
	printf("%.10lf",l);
	return 0;
}