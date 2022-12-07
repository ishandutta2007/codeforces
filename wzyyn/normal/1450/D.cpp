#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
using namespace std;

const int N=300005;
int n,c[N],a[N],re[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) c[i]=0;
	For(i,1,n) scanf("%d",&a[i]),++c[a[i]];
	For(i,1,n) re[i]=0;
	if (c[1]) re[n]=1;
	re[1]=1;
	For(i,1,n) if (c[i]!=1) re[1]=0;
	int l=1,r=n;
	For(i,1,n){
		if (c[i]==0) break;
		re[n-i+1]=1;
		if (a[l]==i) ++l;
		else if (a[r]==i) --r;
		else break;
		if ((--c[i])!=0) break;
	}
	For(i,1,n) printf("%d",re[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}