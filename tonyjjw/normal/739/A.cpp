#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
#include<queue>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 100000 + 5;

int N, M;
int A[MN];
pii q[MN];
priority_queue<pii, vector<pii>, greater<pii>> Q;

int main(){
	scanf("%d%d",&N,&M);
	int ans = 1e9, p = -1;
	for(int i=0;i<M;i++){
		scanf("%d%d",&q[i].first,&q[i].second);
		q[i].first--, q[i].second--;
		if(ans > q[i].second - q[i].first+1){
			ans = q[i].second - q[i].first+1;
			p = i;
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<N;i++) printf("%d ",i%ans);
	return 0;
}