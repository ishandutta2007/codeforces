#include<bits/stdc++.h>
#define ll long long
#define N 10005

ll n,k,a[N];

inline ll sum(int i,int j){
	printf("and %d %d\n",i,j);
	fflush(stdout);
	static ll x;
	scanf("%lld",&x);
	printf("or %d %d\n",i,j);
	fflush(stdout);
	static ll y;
	scanf("%lld",&y);
	return x+y;
}

int main(){
	scanf("%lld%lld",&n,&k);
	ll x=sum(1,2),y=sum(2,3),z=sum(3,1);
	ll s=(x+y+z)>>1;
	a[3]=s-x,a[1]=s-y,a[2]=s-z;
	for(int i=4;i<=n;i++)
		a[i]=sum(1,i)-a[1];
	std::sort(a+1,a+n+1);
	printf("finish %lld\n",a[k]);
}