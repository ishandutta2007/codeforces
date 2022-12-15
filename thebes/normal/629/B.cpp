#include <bits/stdc++.h>
using namespace std;

int m[400], f[400], n, i, x, y, ans;
char c;

int main(){
	for(scanf("%d",&n),i=0;i<n;i++){
		scanf(" %c%d%d",&c,&x,&y);
		if(c=='M') m[x]++, m[y+1]--;
		else f[x]++, f[y+1]--;
	}
	x=0; y=0;
	for(i=1;i<=380;i++){
		x += m[i];
		y += f[i];
		ans=max(ans,min(x,y));
	}
	printf("%d\n",ans*2);
	return 0;
}