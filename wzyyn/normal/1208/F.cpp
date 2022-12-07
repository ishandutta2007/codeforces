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
const int MX=(1<<21);
int n,ans,b[MX];
pii a[MX];
void insert(int p,int v){
	if (v>a[p].fi) swap(a[p].fi,v);
	if (v>a[p].se) swap(a[p].se,v);
}
int main(){
	scanf("%d",&n);
	For(i,0,MX-1) a[i].fi=a[i].se=0;
	For(i,1,n){
		scanf("%d",&b[i]);
		insert(b[i],i);
	}
	For(i,0,20) For(j,0,MX-1)
		if (j&(1<<i)){
			insert(j^(1<<i),a[j].fi);
			insert(j^(1<<i),a[j].se);
		}
	For(i,1,n-2){
		int opp=MX-1-b[i];
		int now=0;
		Rep(j,20,0) if (opp&(1<<j))
			if (a[now|(1<<j)].se>i)
				now|=1<<j;
		ans=max(ans,b[i]|now);
	}
	printf("%d\n",ans);
}