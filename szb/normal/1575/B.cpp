#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,x,y)	for(ll i=(ll)(x);i<=(ll)(y);++i)
#define FOr(i,x,y)	for(ll i=(ll)(x);i>=(ll)(y);--i)
#define rep(i,x,y)	for(ll i=(ll)(x);i<(ll)(y);++i)
#define pa pair<double,ll>
ll read(){
	ll x;scanf("%lld",&x);
	return x;
}
const ll N=1000010;
double eps=1e-9,pi=acos(-1);
pa q[N];
ll n,k,x[N],y[N],tot;
bool cmp(pa a,pa b){
	return a.first<b.first;
}
bool check(double R){
	tot=0;
	For(i,1,n){
		double d=sqrt(x[i]*x[i]+y[i]*y[i]);
		if (R*2+eps<d)continue;
		double dlt=acos(d/2/R);
		double phi;
		if (y[i]>=0) phi=acos(x[i]/d);
		else phi=pi*2-acos(x[i]/d);
		double l=phi-dlt,r=phi+dlt;
//		cout<<dlt<<' '<<phi<<' '<<l<<' '<<r<<endl;
		if (r>pi*2){
			q[++tot].first=0;
			q[tot].second=1;
			q[++tot].first=r-2*pi;
			q[tot].second=-1;
			q[++tot].first=l;
			q[tot].second=1;
		}
		else{
			if (l<0){
				q[++tot].first=0;
				q[tot].second=1;
				q[++tot].first=r;
				q[tot].second=-1;
				q[++tot].first=l+pi*2;
				q[tot].second=1;
			}
			else{
				q[++tot].first=l;
				q[tot].second=1;
				q[++tot].first=r;
				q[tot].second=-1;
			}
		}
	}
	
	For(i,1,tot)if (q[i].second==1)q[i].first-=eps;
	sort(q+1,q+tot+1,cmp);
	ll inf=0;
	For(i,1,tot){
		inf+=q[i].second;
		if (inf>=k)return 1;
	}
	return 0;
}
int main(){
	n=read();	k=read();
	For(i,1,n){
		x[i]=read(),y[i]=read();
		if (x[i]==0&&y[i]==0){
			--i;--k;--n;
		}
	}
	if (k<=0){
		puts("0.0000000000");
		return 0;
	}
	double l=0,r=200000,mid;
	For(ci,1,50){
		mid=(l+r)/2;
//		cout<<mid<<' '<<check(mid)<<endl;
		if (check(mid))r=mid;
		else	l=mid;
	}
	printf("%.10lf\n",mid);
}