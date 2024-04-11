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

const int B=256;
const int N=100005;
int n,Q,a[N],jmp[N];
int tg[N],be[N],rem[N];
int L[N],R[N];
void build(int k){
	For(i,L[k],R[k]) jmp[i]=(a[i]<L[k]?i:jmp[a[i]]);
}
void pushdown(int k){
	For(i,L[k],R[k]) a[i]=max(0,a[i]-tg[k]);
	tg[k]=0;
}
void chg(int l,int r){
	int v;
	scanf("%d",&v);
	int bl=be[l],br=be[r];
	if (bl==br){
		pushdown(bl);
		For(i,l,r) a[i]=max(0,a[i]-v);
		build(bl);
	}
	else{
		pushdown(bl);
		pushdown(br);
		For(i,l,R[bl]) a[i]=max(0,a[i]-v);
		For(i,L[br],r) a[i]=max(0,a[i]-v);
		build(bl);
		build(br);
		
		For(i,bl+1,br-1){
			tg[i]=min(tg[i]+v,n+5);
			if ((rem[i]-=v)>0){
				pushdown(i);
				build(i);
			} 
			else rem[i]=0;
		}
	}
}
int qry(int x,int y){
	for (;x!=y;){
		if (x<y) swap(x,y);
		//cout<<"finder "<<x<<' '<<y<<endl;
		if (y<=0) return 1;
		if (rem[be[x]]){
			if (jmp[x]==jmp[y]){
				for (;x!=y;){
					if (x<y) swap(x,y);
					x=max(a[x]-tg[be[x]],0);
				}
				return max(x,1);
			}
			x=jmp[x];
			x=a[x]-tg[be[x]];
		}
		
		else x=a[x]-tg[be[x]];
	}
	return max(x,1);
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,2,n) scanf("%d",&a[i]);
	For(i,1,n) be[i]=(i-1)/B+1;
	For(i,1,be[n]){
		L[i]=(i-1)*B+1;
		R[i]=min(i*B,n);
		rem[i]=B;
		build(i);
	}
	while (Q--){
		int tp,l,r;
		scanf("%d%d%d",&tp,&l,&r);
		if (tp==1) chg(l,r);
		else printf("%d\n",qry(l,r));
	}
}