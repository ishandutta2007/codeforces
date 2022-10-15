#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int maxn=300007;
int x[maxn],y[maxn],z[maxn];
int x1=1e18,x2=-1e18,y1=1e18,y2=-1e18,z1=1e18,z2=-1e18;
string s;
int n;
bool f(int u,int &ansl,int &ansr){
	int xl,xr,yl,yr,zl,zr;
	xl=max(0ll,x2-u),xr=x1+u, yl=max(0ll,y2-u), yr=y1+u, zl=z2-u, zr=z1+u;
//	cout<<xl<<" "<<xr<<" "<<yl<<" "<<yr<<" "<<zl<<" "<<zr<<endl;
	if (xl>xr||yl>yr||zl>zr) return 1;
	if (yr-xl>=zl&&yl-xr<=zr){
		if (yr-xl<=zr){
			ansl=xl, ansr=yr;
			return 0;
		}
		if (yl-xr>=zl){
			ansl=xr, ansr=yl;
			return 0;
		}
		int diff=yr-xl-zr;
		if (yr-diff>=yl){
			ansl=xl, ansr=yr-diff;
			return 0;
		}
		diff=zl-yl+xr;
		ansl=xr-diff,ansr=yl;
		return 0;
	}
	return 1;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for (int i=0;i<n;++i){
		cin>>s;
		for (auto c:s){
			if (c=='B') x[i]++;
			else y[i]++;
		}
		z[i]=y[i]-x[i];
		x1=min(x1,x[i]), x2=max(x2,x[i]), y1=min(y1,y[i]), y2=max(y2,y[i]), z1=min(z1,z[i]), z2=max(z2,z[i]);
	}
	int l=0, r=1e18,md,ansl=0,ansr=0;
	while (l<r){
		md=(l+r)>>1;
		if (f(md,ansl,ansr)) l=md+1;
		else r=md;
	}
	cout<<l<<endl;
	f(l,ansl,ansr);
//	cout<<ansl<<" "<<ansr<<endl;
	for (int i=0;i<ansl;++i) cout<<"B";
	for (int i=0;i<ansr;++i) cout<<"N";
	if (ansl+ansr==0) cout<<"BN";
	return 0;
}