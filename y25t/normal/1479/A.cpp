#include<cstdio>
#define N 100005

int n,a[N];

inline int geta(int i){
	if(a[i])
		return a[i];
	printf("? %d\n",i);
	fflush(stdout);
	scanf("%d",&a[i]);
	return a[i];
}

int main(){
	scanf("%d",&n);
	a[0]=a[n+1]=n+1;
	int L=1,R=n;
	while(L<=R){
		int mid=(L+R)>>1;
		int x=geta(mid-1),y=geta(mid),z=geta(mid+1);
		if(x>y&&y<z){
			printf("! %d\n",mid);
			break;
		}
		if(x<z)
			R=mid-1;
		else
			L=mid+1;
	}
}