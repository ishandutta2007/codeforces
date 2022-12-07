#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	int n,x,t;
	scanf("%d%d%d",&n,&x,&t);
	int A=t/x;
	if (A>=n)
		cout<<1ll*n*(n-1)/2<<endl;
	else
		cout<<1ll*A*(n-A)+1ll*A*(A-1)/2 <<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}