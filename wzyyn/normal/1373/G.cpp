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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=600005;
int n,m,k,mx,vis[N];
int t[N*4],tg[N*4];
map<pii,int> mp;
set<int> S;

void build(int k,int l,int r){
	t[k]=r-1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		tg[k]+=v; t[k]+=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	t[k]=max(t[k*2],t[k*2+1])+tg[k];
}
int ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y)+tg[k];
	if (x>mid) return ask(k*2+1,mid+1,r,mid+1,y)+tg[k];
	return max(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y))+tg[k];
}
void erase(int x){
	change(1,1,mx,1,x,-1);
	if (!--vis[x]) S.erase(x);
}
void insert(int x){
	change(1,1,mx,1,x,1);
	if (!vis[x]++) S.insert(x);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	mx=2*n+k;
	For(i,1,mx) vis[i]=0;
	build(1,1,mx);
	++vis[n]; S.insert(n);
	while (k--){
		int x,y;
		scanf("%d%d",&x,&y);
		if (mp[pii(x,y)]) erase(abs(m-x)+y);
		else insert(abs(m-x)+y);
		mp[pii(x,y)]^=1;
		if (!S.size()) puts("0");
		else printf("%d\n",max(0,ask(1,1,mx,1,*S.rbegin())-n));
	}
}