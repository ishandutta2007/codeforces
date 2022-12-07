#include<bits/stdc++.h>

using namespace std;

void solve(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if (a+b+c==max(max(a,b),c)*2) puts("YES");
	else if (a==b&&c%2==0) puts("YES");
	else if (a==c&&b%2==0) puts("YES");
	else if (b==c&&a%2==0) puts("YES");
	else puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}