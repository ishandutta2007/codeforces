#include<bits/stdc++.h>
#define ll long long
#define lf long double
#define N 100005

int n;
ll t;
lf a[N],b[N],c[N],mx;

int p[N],q[N],m;

inline lf fp(lf x,ll k){
	lf res=1;
	for(;k;k>>=1,x*=x) if(k&1)
		res*=x;
	return res;
}
inline lf cal(int i,ll s,lf f,ll k){
	lf tmp=fp(1-c[i],k);
	return tmp*f+(a[i]+c[i]*mx*(s+k))*(1-tmp)/c[i]-c[i]*mx*(1-(1+c[i]*k)*tmp)/(c[i]*c[i]);
}

int main(){
	scanf("%d%lld",&n,&t);
	for(int i=1;i<=n;i++)
		scanf("%Lf%Lf%Lf",&a[i],&b[i],&c[i]),a[i]*=c[i],b[i]*=c[i],mx=std::max(mx,b[i]);
	std::iota(p+1,p+n+1,1),std::sort(p+1,p+n+1,[&](int i,int j){
		return c[i]!=c[j]?c[i]<c[j]:a[i]>a[j];
	});
	for(int o=1;o<=n;o++){
		int i=p[o];
		while(m>1&&(a[i]-a[q[m]])*(c[q[m]]-c[q[m-1]])>=(a[q[m]]-a[q[m-1]])*(c[i]-c[q[m]]))
			m--;
		if(!m||c[i]!=c[q[m]])
			q[++m]=i;
	}
	ll s=0;
	lf f=0;
	for(int o=1;o<=m;o++){
		int i=q[o];
		lf l=o==m?1e18:-(a[q[o+1]]-a[i])/(c[q[o+1]]-c[i]);
		ll L=0,R=t-s-1,res=-1;
		while(L<=R){
			ll mid=(L+R)>>1;
			if((s+mid)*mx-cal(i,s,f,mid)<l)
				res=mid,L=mid+1;
			else
				R=mid-1;
		}
		f=cal(i,s,f,res+1),s+=res+1;
	}
	printf("%.10Lf\n",f);
}