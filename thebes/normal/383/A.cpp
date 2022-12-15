#include <bits/stdc++.h>
using namespace std;

const int MN = 200005;
int cnt, N, i, x;
long long tot;

int main(){
	for(scanf("%d",&N),i=0;i<N;i++){
		scanf("%d",&x);
		if(!x) tot += cnt;
		else cnt++;
	}
	printf("%lld\n",tot);
	return 0;
}