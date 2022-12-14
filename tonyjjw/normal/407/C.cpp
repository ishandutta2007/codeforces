#include<stdio.h>
#include<vector>
#define MN 100001
#define MOD 1000000007

std::vector<int> st[MN],ed[MN],edd[MN];

int N,M;
int A[MN];
int C[MN+102][102];
int D[MN][102];

inline int comb(int a,int b){
	if(b<0)return 0;
	return C[a][b];
}

inline void mod(int &a){
	if(a>=MOD)a-=MOD;
	if(a<0)a+=MOD;
}

int main(){
	int i,j,l,r,k;
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&M);
	for(i=0;i<=N+100;i++){
		C[i][0]=1;
		for(j=1;j<=i && j<=100;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			mod(C[i][j]);
		}
	}
	for(i=0;i<N;i++)scanf("%d",&A[i]);
	for(i=0;i<M;i++){
		scanf("%d%d%d",&l,&r,&k),--l,--r;
		st[l].push_back(k);
		ed[r+1].push_back(k);
		edd[r+1].push_back(k+r-l+1);
	}
	for(i=0;i<N;i++){
		for(k=0;k<st[i].size();k++){
			for(j=0;j<=100;j++){
				D[i][j]+=comb(st[i][k],st[i][k]-j),mod(D[i][j]);
			}
		}
		for(k=0;k<ed[i].size();k++){
			for(j=0;j<=100;j++){
				D[i][j]-=comb(edd[i][k],ed[i][k]-j),mod(D[i][j]);
			}
		}
		for(j=0;i && j<=100;j++){
			D[i][j]+=D[i-1][j],mod(D[i][j]);
			D[i][j]+=D[i-1][j+1],mod(D[i][j]);
		}
	}
	for(i=0;i<N;i++){
		A[i]+=D[i][0],mod(A[i]);
		printf("%d ",A[i]);
	}
	return 0;
}