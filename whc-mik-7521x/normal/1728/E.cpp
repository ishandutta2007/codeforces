#include<bits/stdc++.h>
using namespace std;
const long long N=3e5+10;
long long n,que,a[N],b[N],s[N],sum,pos;
long long exgcd(long long a,long long b,long long &x,long long &y){
	if(!b)return x=1,y=0,a;
	long long d=exgcd(b,a%b,y,x);y-=a/b*x;
	return d;
}
long long ask1(long long x,long long y){
	if(y<0)x=-x,y=-y;
	return x>=0?x/y+(x%y!=0):x/y;
}
long long ask2(long long x,long long y){
	if(y<0)x=-x,y=-y;
	return x>=0?x/y:x/y-(x%y!=0);
}
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)scanf("%lld%lld",&a[i],&b[i]),s[i]=a[i]-b[i],sum+=b[i];
	sort(s+1,s+n+1);
	reverse(s+1,s+n+1);
	for(int i=1;i<=n;++i){
		if(s[i]>=0)pos=i;
		s[i]+=s[i-1];
	}
	scanf("%d",&que);
	while(que--){
		long long p,q;
		scanf("%lld%lld",&p,&q);
		long long x,y,d=exgcd(p,q,x,y);
		if(n%d){puts("-1");continue;}
		long long L=ask1(-n*x,q),R=ask2(n*y,p),stp=q/d;
		x*=n/d;
		if(L>R){puts("-1");continue;}
		long long k1=max(L,min(R,ask2(pos-x*p,stp*p))),k2=max(L,min(R,ask1(pos+1-x*p,stp*p)));
		long long res1=sum+s[p*(x+k1*stp)],res2=sum+s[p*(x+k2*stp)];
		printf("%lld\n",max(res1,res2));
	}
	return 0;
}