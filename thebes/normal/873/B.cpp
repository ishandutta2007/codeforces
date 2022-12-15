#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, i, x, ans, p[200005], sh = 100001;

int main(){
	memset(p, -1, sizeof(p)); p[0+sh] = 0;
	for(scanf("%I64d",&N),getchar(),i=1;i<=N;i++){
		if(getchar()=='1') x++;
		else x--;
		if(p[x+sh] != -1) ans = max(ans,i-p[x+sh]);
		else p[x+sh] = i;
	}
	printf("%I64d\n",ans);
	return 0;
}