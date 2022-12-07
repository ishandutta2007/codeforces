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
int n,k,a[105];
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	for (;k;--k){
		int p=1;
		for (;p!=n;++p) if (a[p]<a[p+1]) break;
		if (p==n) return puts("-1"),void(0);
		else{
			++a[p];
			if (k==1) printf("%d\n",p);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}