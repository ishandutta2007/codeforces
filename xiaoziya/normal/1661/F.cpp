#include<stdio.h>
const int maxn=200005;
int n;
int a[maxn],x[maxn];
long long m;
inline long long calc(int a,int b){
	if(a<=b)
		return a;
	int c=a/b,d=a%b;
	return 1ll*(c+1)*(c+1)*d+1ll*c*c*(b-d);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]),a[i]=x[i]-x[i-1];
	scanf("%lld",&m);
	long long L=-1,R=1e18;
	int cost=0;
	while(L+1<R){
		long long MID=(L+R)>>1,sum=0;
		for(int i=1;i<=n;i++){
			int l=0,r=a[i]+2;
			while(l+1<r){
				int mid=(l+r)>>1;
				if(calc(a[i],mid)-calc(a[i],mid+1)<MID)
					r=mid;
				else l=mid;
			}
			sum+=calc(a[i],r);
		}
		if(sum<=m)
			L=MID;
		else R=MID;
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		int l=0,r=a[i]+2;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(calc(a[i],mid)-calc(a[i],mid+1)<L)
				r=mid;
			else l=mid;
		}
		cost+=r-1,sum+=calc(a[i],r);
	}
	printf("%d\n",cost-(m-sum)/L);
	return 0;
}