#include<cstdio>
const int N=2000;
int k;
int min(int a,int b){return a<b?a:b;}
int main(){
	scanf("%d",&k);k+=N;
	printf("%d\n%d ",N,-1);
	for(int i=1;i<N;++i)printf("%d ",min(k,1000000)),k-=min(k,1000000);
	return 0;
}