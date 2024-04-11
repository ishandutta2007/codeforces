#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

void solve(){
	int a,b;
	scanf("%d%d",&a,&b);
	if (a==0&&b==0) puts("0");
	else if (a==b) puts("1");
	else puts((a+b)&1?"-1":"2");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}