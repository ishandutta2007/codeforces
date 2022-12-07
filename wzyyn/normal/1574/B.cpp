#include<bits/stdc++.h>

using namespace std;

void solve(){
	int a,b,c,m;
	scanf("%d%d%d%d",&a,&b,&c,&m);
	if (a>b) swap(a,b);
	if (a>c) swap(a,c);
	if (b>c) swap(b,c);
	int mnseg=3;
	int mxseg=min(2*(a+b)+1,a+b+c);
	if (a+b+c-mxseg<=m&&m<=a+b+c-mnseg)
		puts("YES");
	else puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}