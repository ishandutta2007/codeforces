#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	if (k>(n-1)/2) printf("%d\n",-1);
	else{
		for (;k;k--,n-=2)
			printf("%d %d ",n-1,n);
		for (;n;--n)
			printf("%d ",n);
		puts("");
	}
} 
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}