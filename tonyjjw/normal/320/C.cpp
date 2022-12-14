#include<stdio.h>
#include<string.h>
#define MOD (1000000007)

char A[200];

int L;
long long pow[200],ans;

int main(){
	int i;
	scanf("%s",A);
	L=strlen(A);
	pow[0]=1;
	for(i=1;i<200;i++){
		pow[i]=pow[i-1]<<1;
		while(pow[i]>=MOD)pow[i]-=MOD;
	}
	for(i=0;i<L;i++){
		if(A[i]=='1'){
			ans+=pow[i+2*(L-i-1)];
			ans%=MOD;
		}
	}
	printf("%lld",ans);
	return 0;
}