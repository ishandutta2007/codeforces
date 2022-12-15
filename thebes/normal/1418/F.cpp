#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 2e5+5;
int N, M, i, j; pii st[4*MN];
ll L, R; vi vec[MN];
struct hmm{int x, y, a, b;}ans[4*MN];
vector<pii> go, up;

void build(int i,int s,int e){
	if(s^e){
		build(2*i,s,(s+e)/2);
		build(2*i+1,(s+e)/2+1,e);
		st[i].F = min(st[2*i].F,st[2*i+1].F);
		st[i].S = (st[2*i].F<st[2*i+1].F)?st[2*i].S:st[2*i+1].S;
	}
	else st[i] = {(vec[s].size())?vec[s].back():1<<30,s};
}

void upd(int i,int s,int e,int ind){
	if(s^e){
		if((s+e)/2<ind) upd(2*i+1,(s+e)/2+1,e,ind);
		else upd(2*i,s,(s+e)/2,ind);
		st[i].F = min(st[2*i].F,st[2*i+1].F);
		st[i].S = (st[2*i].F<st[2*i+1].F)?st[2*i].S:st[2*i+1].S;
	}
	else st[i] = {(vec[s].size())?vec[s].back():1<<30,s};
}

pii qu(int i,int s,int e,int ss,int se){
	if(s>=ss&&e<=se) return st[i];
	else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
	else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
	else{
		pii l = qu(2*i,s,(s+e)/2,ss,se), r = qu(2*i+1,(s+e)/2+1,e,ss,se), res;
		res.F = min(l.F, r.F);
		res.S = (l.F<r.F)?l.S:r.S;
		return res;
	}
}

int main(){
	scanf("%d%d%lld%lld",&N,&M,&L,&R);
	memset(ans,-1,sizeof(ans));
	for(i=1;i<=N;i++){
		for(j=i;j<=N;j+=i)
			go.pb({i,j});
	}
	for(i=2;i<=M;i++){
		for(j=i;j<=M;j+=i){
			vec[j].pb(i);
			up.pb({i,j});
		}
	}
	for(i=1;i<=M;i++)
		sort(vec[i].begin(),vec[i].end(),[](int x,int y){return x>y;});
	sort(go.begin(),go.end(),[](pii i,pii j){return i.F<j.F;});
	sort(up.begin(),up.end(),[](pii i,pii j){return i.F<j.F;});
	build(1,1,M);
	for(i=j=0;i<(int)go.size();i++){
		while(j<(int)up.size()&&up[j].F<=go[i].F){
			vec[up[j].S].pop_back();
			upd(1,1,M,up[j].S); j++;
		}
		ll l = ceil(L/(long double)go[i].S), r = min((ll)M,(ll)(R/(long double)go[i].S));
		if(l<=r){
			pii res = qu(1,1,M,l,r);
			if(1LL*res.F*go[i].S/go[i].F<=N){
				ans[go[i].S] = {go[i].S,res.S,go[i].S/go[i].F*res.F,res.S/res.F*go[i].F};
			}
		}
	}
	for(i=1;i<=N;i++){
		if(ans[i].a==-1) printf("-1\n");
		else printf("%d %d %d %d\n",ans[i].x,ans[i].y,ans[i].a,ans[i].b);
	}
	return 0;
}