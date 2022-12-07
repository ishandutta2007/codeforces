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
int a[100005];
int b[100005];
void solve(){
	int A,B,n;
	int x,y,mx=0,flg=0;
	scanf("%d%d%d",&A,&B,&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	For(i,1,n){
		int rnd=(b[i]+A-1)/A; mx=max(mx,a[i]);
		if (B-1ll*rnd*a[i]+mx<=0) flg=1;
		B-=1ll*rnd*a[i];
	}
	puts(!flg?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}