#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MN = 1000 + 5;

int D[MN][MN][11];
int N,M,K;
char s1[MN],s2[MN];
int len[MN][MN];

int main(){
	scanf("%d%d%d",&N,&M,&K);
	scanf("%s%s",s1,s2);
	D[0][0][1] = (s1[0]==s2[0]);
	for(int i=0;i<N;i++)for(int j=0;j<M;j++){
		if(s1[i]!=s2[j])continue;
		len[i][j] = 1;
		if(i>0 && j>0) len[i][j] = len[i-1][j-1] + 1;
	}
	for(int i=1;i<N;i++){
		D[i][0][1] = max((int)(s1[i]==s2[0]),D[i-1][0][1]);
	}
	for(int i=1;i<M;i++){
		D[0][i][1] = max((int)(s1[0]==s2[i]),D[0][i-1][1]);
	}
	for(int i=1;i<N;i++)for(int j=1;j<M;j++)for(int k=1;k<=K;k++){
		D[i][j][k] = max(D[i-1][j][k],D[i][j-1][k]);
		if(s1[i]==s2[j]){
			int l = len[i][j];
			if(i-l>=0 && j-l>=0){
				D[i][j][k] = max(D[i][j][k],D[i-l][j-l][k-1]+l);
			}
			else{
				D[i][j][k] = max(D[i][j][k],l);
			}
		}
	}
	int ans=0;
	for(int k=1;k<=K;k++){
		if(ans<D[N-1][M-1][k]) ans=D[N-1][M-1][k];
	}
	printf("%d\n",ans);
	return 0;
}