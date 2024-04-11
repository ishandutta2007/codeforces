#include<bits/stdc++.h>

using namespace std;

void solve(){
	int x;
	scanf("%d",&x);
	if (x%7==0) printf("%d\n",x);
	else if (x%10>=x%7) printf("%d\n",x-x%7);
	else printf("%d\n",x+7-x%7);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}