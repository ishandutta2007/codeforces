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
int a[105],b[2],n;
void solve(){
	int fl1=0,fl2=0;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	For(i,1,n){
		if (a[i]==a[i-1]+1&&i-1) fl1=1;
		if (a[i]&1) fl2^=1;
	}
	puts(fl2&&!fl1?"NO":"YES");
	 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}