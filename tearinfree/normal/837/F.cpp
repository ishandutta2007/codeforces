#include <cstdio>
#include <algorithm>

typedef long long lli;
const lli INF=1e18;
int n;
lli k,arr[200000];

lli mul(lli a,lli b) {
	if(a==0||b==0) return 0;
	if(a>=INF||b>=INF) return INF;
	if(INF/b+1<a) return INF;
	return std::min(INF,a*b);
}
lli gcd(lli a,lli b) {
	while(b) {
		lli tmp=a%b;a=b;b=tmp;
	}
	return a;
}
lli com(lli base,lli u,lli d) {
	if(base>=INF) return INF;
	if(u>=INF) return INF;
	if(base%d==0) base/=d;
	else if(u%d==0)u/=d;
	else {
		lli g=gcd(u,d);
		u/=g;
		base/=(d/g);
	}
	
	return mul(base,u);
}
bool Check(lli i) {
	if(i==1) {
		lli sum=0;
		for(int j=0;j<n;j++) {
			sum+=arr[j];
			if(sum>=k) return true;
		}
		return false;
	}
	lli c=1,d=1,m=i,sum=0;
	for(int j=n-1;j>=0;j--) {
		lli val=mul(arr[j],c);
		if(val==INF) return true;
		sum+=val;
		if(sum>=k) return true;

		c=com(c,m++,d++);
	}
	return false;
}
int main() {
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++) scanf("%lld",arr+i);
	for(int i=0;i<n;i++) {
		if(arr[i]>=k) {
			printf("0\n");
			return 0;
		}
	}
	
	lli lo=0,up=1e18+3;
	while(up-lo>1) {
		lli md=(lo+up)>>1;
		if(Check(md)) up=md;
		else lo=md;
	}
	printf("%lld\n",up);
	return 0;
}