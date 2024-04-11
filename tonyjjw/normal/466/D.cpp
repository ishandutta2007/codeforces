#include<stdio.h>
#pragma warning(disable:4996)
#define MN 2000
#define MOD 1000000007

int N,H;
int A,bef;
long long ans=1;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&H);
	int i;
	for(i=0;i<N;i++){
		scanf("%d",&A);
		if(A+bef+1==H){
			bef++;
		}
		else if(A+bef==H){
			ans*=bef+1;
			ans%=MOD;
		}
		else if(A+bef-1==H){
			ans*=bef;
			ans%=MOD;
			bef--;
		}
		else{
			ans=0;
			break;
		}
	}
	if(bef>1)ans=0;
	printf("%lld",ans);
	return 0;
}