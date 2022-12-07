#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void solve(){
	int x;
	scanf("%d",&x);
	printf("%d\n",100/gcd(100,x));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}