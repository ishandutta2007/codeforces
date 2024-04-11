//*

#include<stdio.h>
#include<vector>
//#pragma warning(disable:4996)
#define MN 1000000
#define ML 5000

typedef long long LL;

using namespace std;

long long mod,C[ML+1],S[MN];
int B[ML+1][ML+1];
vector<int> D[MN];
int N,M;
int L[MN];
int A[ML];


long long MOD(LL a){
	a%=mod;
	return a;
}

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(){
	int i,j;
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d%lld",&N,&M,&mod);
	for(i=0;i<N;i++){
		scanf("%d",&L[i]);
		for(j=0;j<L[i]+1;j++)D[i].push_back(0);
	}
	for(C[0]=1,i=1;i<=ML;i++){
		A[i-1]=M-(i-1);
		int t=i;
		for(j=0;j<i && t!=1;j++){
			int g=gcd(t,A[j]);
			A[j]/=g;
			t/=g;
		}
		for(C[i]=1,j=0;j<i;j++){
			C[i]=MOD((LL)C[i]*A[j]);
		}
	}
	B[1][1]=1;
	for(i=2;i<=ML;i++){
		for(j=2;j<=i;j++){
			B[i][j]=MOD((LL)(B[i-1][j]+B[i-1][j-1])*(j-1));
		}
	}
	for(j=1;j<=L[0];j++){
		D[0][j]=MOD((LL)j*B[L[0]][j]);
		S[0]=MOD(S[0]+C[j]*D[0][j]);
	}
	for(i=1;i<N;i++){
		for(j=1;j<=L[i];j++){
			if(j<=L[i-1]){
				D[i][j]=MOD(MOD((S[i-1]-D[i-1][j])*B[L[i]][j])*j);
			}
			else{
				D[i][j]=MOD(MOD(S[i-1]*B[L[i]][j])*j);
			}
			S[i]=MOD(S[i]+C[j]*D[i][j]);
		}
	}
	if(S[N-1]<0)S[N-1]+=mod;
	printf("%lld",S[N-1]);
	return 0;
}

//*/