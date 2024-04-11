#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

void solve(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if ((a+b+c)%9) puts("NO");
	else{
		int v=(a+b+c)/9;
		if (min(min(a,b),c)<v) puts("NO");
		else puts("YES");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}