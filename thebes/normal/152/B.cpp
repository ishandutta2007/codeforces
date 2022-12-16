#include <bits/stdc++.h>
using namespace std;

int x, y, n, m, k, dx, dy, i, sx, sy;
long long ans;

int main(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(scanf("%d",&k),i=0;i<k;i++){
		scanf("%d%d",&dx,&dy);
		sx = sy = 1<<30;
		if(dx<0) sx=(x-1)/(-dx);
		if(dx>0) sx=(n-x)/(dx);
		if(dy<0) sy=(y-1)/(-dy);
		if(dy>0) sy=(m-y)/(dy);
		int s = min(sx, sy);
		x += dx*s; y += dy*s;
		ans += s;
	}
	printf("%lld\n",ans);
	return 0;
}