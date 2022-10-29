#include<bits/stdc++.h>
using namespace std;
#define N 600010
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef complex<double> cp;
const double PI = acos(-1);

LL n,m,k,x,sum=0,ans0=0,eq[N],id[N];
cp a[N],b[N];

inline void fft(cp *x, int n, int t){
	rep(i,0,n-1)if(i<id[i])swap(x[i],x[id[i]]);  //swap 
	for(int h=2; h<=n; h<<=1){
		cp wn(cos(2*PI/h), t*sin(2*PI/h));
		for(int j=0; j<n; j+=h){
			cp w(1,0), tmp;
			rep(k, j, j+(h>>1)-1){
				tmp = x[k+(h>>1)] * w;
				x[k+(h>>1)] = x[k] - tmp;
				x[k] += tmp;
				w *= wn;
			}
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%lld%lld",&n,&k);
	eq[0] = 1;
	rep(i,1,n){
		scanf("%lld",&x);
		sum += (x<k);
		++eq[sum];
	}
	rep(i,0,n) ans0 += eq[i] * (eq[i]-1) / 2;
	for(m=1;m<=(n<<1);m<<=1);
	rep(i,0,n) a[i] = b[n-i] = eq[i];
	rep(i,0,m-1) id[i] = (id[i>>1]>>1)|(i&1?m>>1:0);
	
	fft(a,m,1); fft(b,m,1);	rep(i,0,m)a[i] *= b[i];	fft(a,m,-1);
	printf("%lld", ans0);
	rep(i,n+1,n<<1)printf(" %lld",(LL)(a[i].real()/m+.5));
	return 0;
}