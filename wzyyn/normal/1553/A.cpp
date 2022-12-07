#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

void solve(){
	int x;
	scanf("%d",&x);
	printf("%d\n",(x+1)/10);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}