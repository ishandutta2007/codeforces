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
const int N=300005;
int n,a[N],b[N],t[N];
pii v1[N],v2[N];
void change(int x,int v){
	for (;x;x-=x&(-x)) t[x]=min(t[x],v);
}
int ask(int x){
	int ans=1<<30;
	for (;x<=n;x+=x&(-x)) ans=min(ans,t[x]);
	return ans;
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) t[i]=0;
	For(i,1,n) scanf("%d",&v1[i].fi),v1[i].se=i;
	For(i,1,n) scanf("%d",&v2[i].fi),v2[i].se=i;
	sort(v1+1,v1+n+1);
	sort(v2+1,v2+n+1);
	For(i,1,n) if (v1[i].fi!=v2[i].fi)
		return puts("NO"),void(0);
	For(i,1,n){
		a[v1[i].se]=i;
		b[v1[i].se]=v2[i].se;
	}
	For(i,1,n) t[i]=1<<30;
	Rep(i,n,1){
		if (ask(a[i])<b[i])
			return puts("NO"),void(0);
		change(a[i],b[i]);
	}
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
v1<v2 a[v1]<a[v2] b[v1]>b[v2]
*/