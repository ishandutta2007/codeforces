#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 20 + 5;

int N, M;
int A[MN][MN];

void swap_col(int j1,int j2){
	for(int i=0;i<N;i++) swap(A[i][j1], A[i][j2]);
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)for(int j=0;j<M;j++){
		scanf("%d",&A[i][j]);
	}
	for(int j1=0;j1<M;j1++)for(int j2=j1;j2<M;j2++){
		swap_col(j1,j2);
		bool flag = true;
		for(int i=0;i<N;i++){
			int cnt = 0;
			for(int j=0;j<M;j++){
				if(A[i][j] != j+1) cnt++;
			}
			if(cnt>2) flag = false;
		}
		if(flag){
			puts("YES");
			return 0;
		}
		swap_col(j1,j2);
	}
	puts("NO");
	return 0;
}