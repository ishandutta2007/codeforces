#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MN = 500 + 1;

int N;
int c[MN];
int D[MN][MN];

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&c[i]);
	}
	for(int l=0;l<N;l++){
		for(int i=0;i+l<N;i++){
			int j=i+l;
			if(l==0){
				D[i][j]=1;
				continue;
			}
			D[i][j]=D[i+1][j]+1;
			if(c[i]==c[i+1]){
				D[i][j]=min(D[i][j],D[i+2][j]+1);
			}
			for(int k=i+2;k<=j;k++)if(c[i]==c[k]){
				D[i][j] = min(D[i][j],D[i+1][k-1]+D[k+1][j]);
			}
		}
	}
	printf("%d\n",D[0][N-1]);
	return 0;
}