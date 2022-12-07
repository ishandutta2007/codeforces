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
int n,x,S[25];
ll pr[25][25],f[(1<<20)];
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&x); --x;
		For(j,0,19) if (x!=j) pr[j][x]+=S[j];
		++S[x];
	}
	//printf("%d\n",pr[2][3]);
	memset(f,60,sizeof(f));
	f[0]=0;
	For(i,0,(1<<20)-1)
		For(j,0,19) if (!(i&(1<<j))){
			ll s=f[i];
			For(k,0,19) if (i&(1<<k))
				s+=pr[j][k];
			f[i|(1<<j)]=min(f[i|(1<<j)],s);
		}
	printf("%lld\n",f[(1<<20)-1]);
}