#include<bits/stdc++.h>
#define ll long long
#define N 1000000

int k,a[6];

ll f[N];
inline void upd(ll x,ll y){
	for(int i=N-1;i>=x;i--)
		f[i]=std::max(f[i],f[i-x]+y);
}
inline void upd(ll x,ll y,ll z){
	for(int i=1;i<=z;i<<=1)
		upd(x*i,y*i),z-=i;
	upd(x*z,y*z);
}

int main(){
	scanf("%d",&k);
	for(int i=0;i<6;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<N;i++)
		for(int j=0,tmp=1;j<6;j++,tmp=tmp*10)
			f[i]+=i/tmp%10%3==0?1ll*i/tmp%10/3*a[j]:0;
	for(int i=0,tmp=1;i<6;i++,tmp*=10)
		upd(3*tmp,a[i],3*(k-1));
	int q;
	scanf("%d",&q);
	while(q--){
		int n;
		scanf("%d",&n);
		printf("%lld\n",f[n]);
	}
}