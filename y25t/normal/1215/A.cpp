#include<cstdio>
#include<algorithm>

int a1,a2,k1,k2,n;

int main(){
	scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&n);
	printf("%d ",std::max(0,n-a1*(k1-1)-a2*(k2-1)));
	if(k2<k1){
		std::swap(k1,k2);
		std::swap(a1,a2);
	}
	if(n/k1<=a1)
		printf("%d",n/k1);
	else{
		n-=k1*a1;
		printf("%d",n/k2+a1);
	}
}