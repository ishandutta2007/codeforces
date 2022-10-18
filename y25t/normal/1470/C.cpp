#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long

inline ll qry(int x){
	printf("? %d\n",x);
	fflush(stdout);
	ll res;
	scanf("%lld",&res);
	return res;
}

int n,k;

int m;

int l,r;

int main(){
	scanf("%d%d",&n,&k);
	m=(int)std::floor(std::sqrt((double)n))-1;
	for(int i=1;i<=m+10;i++)
		qry(1);
	for(int i=1;i<=n;i+=m){
		ll tmp=qry(i);
		if(tmp<k)
			l=i;
		if(tmp>k)
			r=i;
	}
	if(l>r)
		r+=n;
	int ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(qry(mid>n?mid-n:mid)<=k){
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	printf("! %d\n",ans>n?ans-n:ans);
}