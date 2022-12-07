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
const int tab[]={1,
				 10,
				 100,
				 1000,
				 10000,
				 100000};
ll f[1000005];
int k,v[15];
void insert(int v,int c){
	v*=3;
	int e=3*(k-1);
	For(i,0,22){
		int s=min(1<<i,e); e-=s;
		ll V=1ll*v*s,C=1ll*c*s;
		if (V<=999999)
			Rep(j,999999,V) f[j]=max(f[j],f[j-V]+C);
	}
}
int main(){
	scanf("%d",&k);
	For(i,0,5) scanf("%d",&v[i]);
	For(i,0,5) For(j,0,999999)
		if (j/tab[i]%10%3==0)
			f[j]+=1ll*(j/tab[i]%10/3)*v[i];
	For(i,0,5)
		insert(tab[i],v[i]);
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int x;
		scanf("%d",&x);
		printf("%lld\n",f[x]);
	}
}