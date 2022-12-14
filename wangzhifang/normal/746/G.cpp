#include <cstdio>
#define max_t 200000
using namespace std;
int a[max_t+1];
int main(){
	int n,t,k,l,r;
	scanf("%d%d%d",&n,&t,&k),l=r=0,a[0]=1;
	for(int i=0; ++i<=t; a[i-1]>a[i]&&(l+=a[i-1]-a[i]),r+=(a[i]-1)){
		scanf("%d",a+i);
		if(!a[i]){
			puts("-1");
			return 0;
		}
	}
	l+=a[t],++r;
	if(k<l||k>r){
		puts("-1");
		return 0;
	}
	printf("%d\n",n);
	k=r-k;
	for(int d=0,prv=1,cnt=1; ++d<=t; cnt+=a[d]){
		if(k){
			if(a[d]>=a[d-1])
				if(k<a[d-1]){
					for(int i=k+1; --i; printf("%d %d\n",prv+i,cnt+i));
					for(int i=k; ++i<=a[d]; printf("%d %d\n",prv,cnt+i));
					k=0;
				}
				else{
					for(int i=a[d-1]; --i; printf("%d %d\n",prv+i,cnt+i));
					for(int i=a[d-1]-1; ++i<=a[d]; printf("%d %d\n",prv,cnt+i));
					k-=a[d-1]-1;
				}
			else
				if(k<a[d]){
					for(int i=k+1; --i; printf("%d %d\n",prv+i,cnt+i));
					for(int i=k; ++i<=a[d]; printf("%d %d\n",prv,cnt+i));
					k=0;
				}
				else{
					for(int i=a[d]+1; --i; printf("%d %d\n",prv+i,cnt+i));
					k-=a[d]-1;
				}
		}
		else
			for(int i=0; ++i<=a[d]; printf("%d %d\n",prv,cnt+i));
		prv=cnt+1;
	}
	return 0;
}