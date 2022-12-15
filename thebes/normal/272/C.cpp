#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e5+5;
ll N, M, i, x, y, h, arr[MN];

int main(){
	for(scanf("%lld",&N),i=1;i<=N;i++)
		scanf("%lld",&arr[i]);
	for(scanf("%lld",&M),i=1;i<=M;i++){
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",max(arr[x],h));
		h=max(arr[x],h)+y;
	}
	return 0;
}