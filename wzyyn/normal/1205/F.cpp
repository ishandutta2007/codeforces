#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=105;
bool f[N][5555];
int S[N],n,nd,ans[N];
void init(){
	For(i,1,N-1) S[i]=i*(i+1)/2;
	f[0][0]=1;
	For(i,1,N-1) f[i][S[i]]=1;
	For(i,4,N-1) f[i][i+1]=1;
	For(i,1,N-1) For(j,i,S[i]) if (f[i][j]){
		For(k,2,N-i) f[i+k-1][j+S[k]-1]=1;
		For(k,4,N-i) f[i+k-1][j+k]=1;
	}
}
/*
3 1 4 2 5
*/
void construct(int l,int r,int n,int k,int op){
	//printf("con %d %d %d %d\n",l,r,n,k);
	if (k==n*(n+1)/2){
		if (op==0) For(i,l,r) ans[i]=++nd;
		else Rep(i,r,l) ans[i]=++nd;
		return;
	}
	if (k==n){
		for (int i=l+1;i<=r;i+=2) ans[i]=++nd;
		for (int i=l;i<=r;i+=2) ans[i]=++nd;
		if (n%2==1) swap(ans[r],ans[r-2]);
		return;
	}
	For(i,2,n)
		if (k-S[i]+1>0)
			if (f[n-i+1][k-S[i]+1]){
				if (op==0){
					construct(l,r-i+1,n-i+1,k-S[i]+1,1);
					For(j,r-i+2,r) ans[j]=++nd;
				}
				else{
					construct(l+i-1,r,n-i+1,k-S[i]+1,0);
					Rep(j,l+i-2,l) ans[j]=++nd;
				}
				return;
			}
	For(i,4,n)
		if (k-i>0)
			if (f[n-i+1][k-i]){
				for (int j=r-i+2;j<=r;j+=2) ans[j]=++nd;
				construct(l,r-i+1,n-i+1,k-i,0);
				for (int j=r-i+3;j<=r;j+=2) ans[j]=++nd;
				if (n&1) swap(ans[r-2],ans[r]);
				return;
			}
}
void solve(){
	int n,k; nd=0;
	scanf("%d%d",&n,&k);
	if (!f[n][k]) return puts("NO"),void(0);
	construct(1,n,n,k,0);
	puts("YES");
	For(i,1,n) printf("%d ",ans[i]);
	puts("");
}
int main(){
	init();
	int Q;
	scanf("%d",&Q);
	while (Q--) solve();
}