#include<bits/stdc++.h>
using namespace std;
long long n,a,r,m,h[100005];
//456364686123567461235476123
//456364686123567461235476123
//456364686123567461235476123
//456364686123567461235476123
//456364686123567461235476123
//456364686123567461235476123
//456364686123567461235476123
//456364686123567461235476123
//456364686123567461235476123
//456364686123567461235476123
long long check(int hei){
	long long cl=0,cb=0;
	for(int i=1;i<=n;i++){
		if(h[i]>hei)cb+=h[i]-hei;
		else cl+=hei-h[i];
	}
	long long to=min(cb,cl);
	cb-=to,cl-=to;
	return 1ll*to*min(a+r,m)+1ll*cb*r+1ll*cl*a;
}
int main(){
	scanf("%Ld%Ld%Ld%Ld",&n,&a,&r,&m);
	for(int i=1;i<=n;i++){
		scanf("%Ld",&h[i]);
	}
	long long l=0,r=1e18+1,midl,midr;
	while(r-l>2){
		midl=(r-l)/3+l;
		midr=r-(r-l)/3;
		if(check(midl)<check(midr)){
			r=midr;
		}
		else l=midl;
	}
	long long ans=1e18;
	for(long long i=l;i<=r;i++){
		long long mo=check(i);
		if(mo<ans)ans=mo;
	}
	printf("%lld",ans);
	return 0;
}
//46531231564561