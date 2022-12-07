#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int x[105],y[105],n,k;
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	bool flg=0;
	For(i,1,n){
		bool flg2=1;
		For(j,1,n) if (abs(x[i]-x[j])+abs(y[i]-y[j])>k) flg2=0;
		flg|=flg2;
	}
	puts(flg?"1":"-1");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}