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
#define y1 fdhjksa
using namespace std;
const int N=500005;
int n,m,c,c0;
struct node{
	int t,S,v;
}q[N];
set<pii> S;
bool cmp(node x,node y){
	return x.t<y.t;
}
void solve(){
	scanf("%d%d%d%d",&n,&m,&c,&c0);
	For(i,1,n) scanf("%d%d%d",&q[i].t,&q[i].S,&q[i].v);
	q[++n]=(node){m,0,0};
	q[++n]=(node){0,c0,0};
	sort(q+1,q+n+1,cmp);
	int sum=0;
	ll ans=0;
	S.clear();
	For(i,1,n-1){
		set<pii>::iterator it;
		it=S.lower_bound(pii(q[i].v,0));
		if (it==S.end()||it->fi!=q[i].v)
			S.insert(pii(q[i].v,q[i].S));
		else{
			int v=it->se;
			S.erase(it);
			S.insert(pii(q[i].v,v+q[i].S));
		}
		sum+=q[i].S;
		for (;sum>c;){
			pii tmp=*(--S.end());
			S.erase(tmp);
			int v=min(sum-c,tmp.se);
			sum-=v; tmp.se-=v;
			if (tmp.se) S.insert(tmp);
		}
		int dif=q[i+1].t-q[i].t;
		if (dif>sum){
			puts("-1");
			return;
		}
		for (;dif;){
			pii tmp=*S.begin();
			S.erase(tmp);
			int v=min(dif,tmp.se);
			sum-=v; dif-=v;
			tmp.se-=v; ans+=1ll*tmp.fi*v;
			if (tmp.se) S.insert(tmp);
		}
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}