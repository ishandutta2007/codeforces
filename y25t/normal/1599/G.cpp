#include<bits/stdc++.h>
#define lf double
#define pll std::pair<lf,lf>
#define fr first
#define sc second
#define eps 1e-9
#define N 200005

inline lf dis(pll x,pll y){
	return std::sqrt((x.fr-y.fr)*(x.fr-y.fr)+(x.sc-y.sc)*(x.sc-y.sc));
}

inline bool chk(pll x,pll y,pll z){
	return std::fabs((y.fr-x.fr)*(z.sc-x.sc)-(z.fr-x.fr)*(y.sc-x.sc))<eps;
}

int n,m;
pll a[N],b;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].fr,&a[i].sc);
	b=a[m];
	if(chk(a[1],a[2],a[3])){
		for(int i=4;i<=n;i++)
			if(!chk(a[1],a[2],a[i])){
				std::swap(a[i],a[n]);
				break;
			}
	}
	else if(n>3){
		if(chk(a[1],a[2],a[4]))
			std::swap(a[3],a[n]);
		else if(chk(a[1],a[3],a[4]))
			std::swap(a[2],a[n]);
		else
			std::swap(a[1],a[n]);
	}
	std::sort(a+1,a+n);
	for(int i=1;i<=n;i++)
		if(a[i]==b)
			m=i;
	if(m==n)
		return printf("%.11lf\n",std::min(dis(a[n],a[1]),dis(a[n],a[n-1]))+dis(a[1],a[n-1])),0;
	lf ans=dis(a[1],a[n-1])+std::min(dis(a[m],a[1])+dis(a[n-1],a[n]),dis(a[m],a[n-1])+dis(a[1],a[n]));
	for(int i=1;i<n-1;i++){
		pll A=a[i],B=a[i+1],C=a[1],D=a[n-1];
		if(i<m)
			std::swap(A,B),std::swap(C,D);
		ans=std::min(ans,std::min(
		dis(a[m],A)+dis(A,C)+dis(C,a[n])+dis(a[n],B)+dis(B,D),
		dis(a[m],C)+dis(C,A)+dis(A,a[n])+dis(a[n],B)+dis(B,D)));
	}
	printf("%.11lf\n",ans);
}