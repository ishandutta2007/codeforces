#include <bits/stdc++.h>
using namespace std;

const int MN = 200005;
struct qu{int t, l, r;}q[MN];
int N, M, Q, i, j, x, orig[MN];

int main(){
	for(scanf("%d%d%d",&N,&Q,&M),i=1;i<=N;i++)
		scanf("%d",&orig[i]);
	for(i=0;i<Q;i++)
		scanf("%d%d%d",&q[Q-i].t,&q[Q-i].l,&q[Q-i].r);
	for(i=1;i<=M;i++){
		scanf("%d",&x);
		for(j=1;j<=Q;j++){
			if(q[j].l <= x && q[j].r >= x){
				if(q[j].t == 1) x = (x==q[j].l)? q[j].r:x-1;
				else x = q[j].r + q[j].l - x;
			}
		}
		printf("%d ",orig[x]);
	}
	return 0;
}