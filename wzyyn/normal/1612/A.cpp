#include<bits/stdc++.h>

using namespace std;

void solve(){
	int x,y;
	scanf("%d%d",&x,&y);
	if ((x+y)&1) puts("-1 -1");
	else if (x%2==0) printf("%d %d\n",x/2,y/2);
	else printf("%d %d\n",(x+1)/2,(y-1)/2);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}