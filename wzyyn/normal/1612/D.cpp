#include<bits/stdc++.h>

using namespace std;

long long x,y,a;
bool ok;

void gcd(long long x,long long y,long long a){
	if (y==0) return;
	gcd(y,x%y,a);
	if (a<=x&&(x-a)%y==0) ok=1;
	if (x!=y&&a<=x&&(x-a)%(x-y)==0) ok=1; 
}
void solve(){
	ok=0;
	scanf("%lld%lld%lld",&x,&y,&a);
	if (x<y) swap(x,y);
	gcd(x,y,a);
	puts(ok?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}