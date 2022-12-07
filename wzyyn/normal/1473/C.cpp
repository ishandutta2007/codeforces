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
	int n,k;
	scanf("%d%d",&n,&k);
	int m=n-k;
	For(i,1,k-m-1) printf("%d ",i);
	Rep(i,k,k-m) printf("%d ",i);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}