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
const int N=300005;
int n,a[N],cc[N*2];
ll ans;
//r-mx==l-mn
vector<int> vals;
void cepaj(int x,int y){
	if (x>=0){
		vals.PB(x);
		cc[x]+=y;
	}
}
void upsolve(vector<int> L,vector<int> R){
	vector<int> mn(1,1e9),mx(1,-1e9);
	for (auto x:R){
		mn.PB(min(mn.back(),x));
		mx.PB(max(mx.back(),x));
	}
	int cmn=1e9,cmx=-1e9,l=1,r=0;
	For(i,0,L.size()-1){
		cmn=min(cmn,L[i]);
		cmx=max(cmx,L[i]);
		int csz=cmx-cmn-i;
		if (csz>0&&csz<mn.size()&&cmn<=mn[csz]&&mx[csz]<=cmx) ans++;
		while (l<mx.size()&&mx[l]<=cmx) cepaj(mx[l]-l,-1),l++;
		while (r<mx.size()-1&&mn[r+1]>=cmn) cepaj(mx[r+1]-r-1,1),r++;
		if (l>r) continue;
		ans+=cc[cmn+i];
	}
	for (auto x:vals) cc[x]=0;
	vals.clear();
}
void solve(int l,int r){
	if (l==r){
		ans++;
		return;
	}
	int m=(l+r)/2;
	solve(l,m);
	solve(m+1,r);
	vector<int> L,R;
	Rep(i,m,l) L.PB(a[i]);
	For(i,m+1,r) R.PB(a[i]);
	upsolve(L,R);
	upsolve(R,L);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int r,c;
		scanf("%d%d",&r,&c);
		--r,--c;
		a[r]=c;
	}
	solve(0,n-1);
	printf("%lld",ans);
}