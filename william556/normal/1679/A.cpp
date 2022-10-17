#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;		
}
int n;
void solve(){
	long long n;
	scanf("%lld",&n);
	if(n&1||n<4){
		puts("-1");
		return;	
	}
	printf("%lld %lld\n",(n-1)/6+1,n/4);
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}