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
const int N=1000005;
int n,a[N],f[N];
int tab[N];
void init(){
	For(i,1,N-1) f[i]=i;
	For(i,2,1000)
		For(j,1,(N-1)/i/i)
			for (;f[j*i*i]%(i*i)==0;f[j*i*i]/=i*i);
}
void solve(){
	scanf("%d",&n);
	int re0=0,re1=0;
	For(i,1,n){
		scanf("%d",&a[i]);
		re0=max(re0,++tab[f[a[i]]]);
	}
	For(i,1,n)
		if (f[a[i]]!=1&&tab[f[a[i]]]%2==0)
			tab[1]+=tab[f[a[i]]],tab[f[a[i]]]=0;
	re1=max(re0,tab[1]);
	For(i,1,n) tab[f[a[i]]]=0;
	tab[1]=0;
	int Q;
	scanf("%d",&Q);
	while (Q--){
		ll v;
		scanf("%lld",&v);
		printf("%d\n",v==0?re0:re1);
	}
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}