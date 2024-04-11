#include<bits/stdc++.h>
using namespace std;

void solve(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if (min(a,b)>max(c,d)) puts("NO");
	else if (min(c,d)>max(a,b)) puts("NO");
	else puts("YES"); 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}