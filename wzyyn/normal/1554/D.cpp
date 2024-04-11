#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

void solve(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		if (i==n/2) putchar('b');
		else putchar(i==n/2+1&&n%2==1?'c':'a');
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}