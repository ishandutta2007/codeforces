#include<stdio.h>
#include<vector>
#define MN 2000
#define MOD (1000000007)

using namespace std;

int N,K,ans;
int D[MN][MN+1];
vector<int> C[MN+1];

int main(){
	int i,j,k;
	scanf("%d%d",&N,&K);
	for(i=1;i<=N;i++){
		for(j=1;j<=i;j++){
			if(i%j==0)C[i].push_back(j);
		}
	}
	for(i=1;i<=N;i++)D[0][i]=1;
	for(i=1;i<K;i++){
		for(j=1;j<=N;j++){
			for(k=0;k<C[j].size();k++){
				D[i][j]+=D[i-1][C[j][k]];
				if(D[i][j]>=MOD)D[i][j]-=MOD;
			}
		}
	}
	for(i=1;i<=N;i++){
		ans+=D[K-1][i];
		if(ans>=MOD)ans-=MOD;
	}
	printf("%d",ans);
	return 0;
}