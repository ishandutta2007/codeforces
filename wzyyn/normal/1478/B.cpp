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
int q,d,f[5005];
bool check(int x,int v){
	for (;x;x/=10)
		if (x%10==v) return 1;
	return 0;
}
void solve(){
	scanf("%d%d",&q,&d);
	For(i,0,1000) f[i]=(i==0);
	For(i,1,999) if (check(i,d))
		For(j,i,1000) f[j]|=f[j-i];
	while (q--){
		int x;
		scanf("%d",&x);
		if (x>1000) puts("YES");
		else puts(f[x]?"YES":"NO");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}