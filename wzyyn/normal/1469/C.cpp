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

int n,k,a[200005];
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	int L=a[1],R=a[1];
	For(i,2,n){
		L=max(a[i],L-k+1);
		R=min(a[i]+k-1,R+k-1);
		if (L>R){
			puts("NO");
			return;
		}
	}
	if (L!=a[n]) puts("NO");
	else puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}