#include<cstdio>
#include<algorithm>
#define N 400005
 
int n,m,a[N];
 
inline int sch(int x){
	int l=1,r=n,res;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]<=x){
			l=mid+1;
			res=mid;
		}
		else
			r=mid-1;
	}
	return res;
}
 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	int num=0,tmp=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=tmp||i==1)
			num++;
		tmp=a[i];
		a[i]=num;
	}
	int len=1<<std::min(8*m/n,30),ans=0; 
	for(int i=1;i<=n;i++)
		ans=std::max(ans,sch(a[i]+len-1)-i+1);
	printf("%d",n-ans);
}