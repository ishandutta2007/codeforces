#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

void solve(){
	int n,mx=0;
	scanf("%d",&n);
	for (;n;n/=10) mx=max(mx,n%10);
	cout<<mx<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
prod
(1-x)^1+(1-w^ix)j

0
*/