#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=200005;
int n,S[N],a[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) S[i]=0;
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) ++S[max(1,i-a[i]+1)],--S[i+1];
	For(i,1,n) S[i]+=S[i-1];
	For(i,1,n) printf("%d ",S[i]==0?0:1);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}