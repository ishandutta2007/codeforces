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
	int n,k,S; 
	scanf("%d%d",&n,&k);
	S=n-(k+1)/2;
	printf("%d\n",S);
	For(i,(k+1)/2,n) if (i!=k) printf("%d ",i);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}