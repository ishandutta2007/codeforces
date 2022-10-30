#include <bits/stdc++.h>
using namespace std;

#define prev prev_
#define next next_

int N,K,S;
int q[153];
vector<vector<int> > prev, next;
const int INF = 1e9;

int main() {
	scanf("%d%d%d",&N,&K,&S);
	S = min(S,N*(N-1)/2);
	for (int i=1;i<=N;i++) scanf("%d",&q[i]);
	prev = vector<vector<int> >(K+1,vector<int>(S+1,INF));
	prev[0][0] = 0;
	for (int i=1;i<=N;i++) {
		next = prev;
		for (int j=1;j<=min(K,i);j++) for (int k=0;k<=S;k++) {
			if (k+abs(i-j)<=S) next[j][k+abs(i-j)] = min(next[j][k+abs(i-j)],prev[j-1][k]+q[i]);
		}
		swap(prev,next);
	}
	int ans = INF;
	for (int i=0;i<=S;i++) ans = min(ans,prev[K][i]);
	printf("%d\n",ans);

	return 0;
}