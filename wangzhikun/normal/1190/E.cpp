//determined
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <complex>
#include <cassert>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
#define FF first
#define SS second
#define MP make_pair
using namespace std;

typedef double db;
typedef pair< db,db > pdb;

const int N = 200010;
const double pi = acos(-1);

int n,m,f[N],g[N],cc1[N];
pdb a[N],inter[N<<1];
db d[N],ang[N];
bool check(db r){
	for(int i=1;i<=n;i++){
		double ang1 = acos(r/d[i]);
		inter[i] = make_pair(ang[i]+ang1,ang[i]-ang1);
		if(inter[i].first>pi*2) inter[i].first-=pi*2,inter[i].second-=pi*2;
	}
	sort(inter+1,inter+n+1);
	for(int i=1;i<=n;i++)inter[i+n] = make_pair(inter[i].FF+2*pi,inter[i].SS+2*pi);
	int j=1;
	for(int i=1;i<=2*n;i++){
		while(inter[j].second<=inter[i].first&&j<n*2)j+=1;
		f[i] = j, g[i] = i;
	}
	for(int x=1;x<=m;x<<=1){
		if(m&x){
			for(int i=1;i<=n;i++){
				cc1[i] = g[(f[i]-1)%n+1] + (f[i]-1)/n*n;
				if(cc1[i]>=n+i) return true;
			}
			memcpy(g,cc1,sizeof g);
		}
		for(int i=1;i<=n;i++) cc1[i] = f[(f[i]-1)%n+1] + (f[i]-1)/n*n;
		memcpy(f,cc1,sizeof f);
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout<<setprecision(15)<<fixed;
	cin>>n>>m;
	db l = 0,r = 2e5;
	for(int i=1;i<=n;i++){
		cin>>a[i].FF>>a[i].SS;
		
		d[i] = sqrt(a[i].FF*a[i].FF+a[i].SS*a[i].SS);
		ang[i] = acos(a[i].first/d[i]);
		if(a[i].second<0) ang[i]=2*pi-ang[i];
		r = min(r,d[i]);
	}
	
	while(r-l>2e-7){
		db mid = (l+r)/2;
		//cout<<mid<<endl;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout<<l<<endl;
	return 0;
}