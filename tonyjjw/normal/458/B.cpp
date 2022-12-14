#include<stdio.h>
#include<algorithm>
//#pragma warning(disable:4996)
#define MN 100010

long long A[MN],B[MN];

long long N,M;
long long SA,SB,sa,sb,ans,ma,mb;

int main(){
	int i;
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%lld%lld",&N,&M);
	for(i=0;i<N;i++)scanf("%lld",&A[i]);
	for(i=0;i<M;i++)scanf("%lld",&B[i]);
	std::sort(A,A+N),std::sort(B,B+M);
	for(i=0;i<N;i++)SA+=A[i];
	for(i=0;i<M;i++)SB+=B[i];
	ans=1e15;
	for(i=N-1,sa=SA;i>=0;i--){
		sa-=A[i];
		if(SB>(1e15-sa)/(N-i))break;
		if(ans>SB*(N-i)+sa){
			ans=SB*(N-i)+sa;
		}
	}
	for(i=M-1,sb=SB;i>=0;i--){
		sb-=B[i];
		if(SA>(1e15-sb)/(M-i))break;
		if(ans>SA*(M-i)+sb){
			ans=SA*(M-i)+sb;
		}
	}
	printf("%lld",ans);
	return 0;
}