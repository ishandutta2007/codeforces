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
int n,k,la[305];
void solve(){
	scanf("%d%d",&n,&k);
	int mx=0,mn1=1e9,mn2=1e9;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		mx=max(mx,x);
		if (x<=mn1) mn2=mn1,mn1=x;
		else mn2=min(mn2,x);
	}
	puts(mn1+mn2<=k||mx<=k?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}