#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 5e5+5;
int N, i, j, x, y, arr[MN], lz[3*MN], cur[MN]; ll ans;
pii st[3*MN]; vi pos[MN];

void build(int i,int s,int e){
	if(s^e){
		build(2*i,s,(s+e)/2);
		build(2*i+1,(s+e)/2+1,e);
		st[i].F = min(st[2*i].F,st[2*i+1].F);
		st[i].S = 0;
		if(st[i].F==st[2*i].F) st[i].S += st[2*i].S;
		if(st[i].F==st[2*i+1].F) st[i].S += st[2*i+1].S;
	}
	else st[i] = {0, 1};
}

inline void upd_lz(int i,int s,int e){
	if(lz[i]){
		st[i].F += lz[i];
		if(s^e) lz[2*i]+=lz[i], lz[2*i+1]+=lz[i];
		lz[i] = 0;
	}
}

void upd(int i,int s,int e,int ss,int se,int val){
	upd_lz(i,s,e);
	if(s>=ss&&e<=se) lz[i]=val, upd_lz(i,s,e);
	else{
		if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,val), upd_lz(2*i,s,(s+e)/2);
		else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,val), upd_lz(2*i+1,(s+e)/2+1,e);
		else upd(2*i,s,(s+e)/2,ss,se,val), upd(2*i+1,(s+e)/2+1,e,ss,se,val);
		st[i].F = min(st[2*i].F,st[2*i+1].F);
		st[i].S = 0;
		if(st[i].F==st[2*i].F) st[i].S += st[2*i].S;
		if(st[i].F==st[2*i+1].F) st[i].S += st[2*i+1].S;
	}
}

pii qu(int i,int s,int e,int ss,int se){
	upd_lz(i,s,e);
	if(s>=ss&&e<=se) return st[i];
	else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
	else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
	else{
		pii l = qu(2*i,s,(s+e)/2,ss,se), r = qu(2*i+1,(s+e)/2+1,e,ss,se);
		pii res(0,0);
		res.F = min(l.F,r.F);
		if(res.F==l.F) res.S += l.S;
		if(res.F==r.F) res.S += r.S;
		return res;
	}
}

inline void add(int x,int p,int c){
    int lst;
    if(p+2<(int)pos[x].size()) lst = pos[x][p+2]-1;
    else lst = N;
    upd(1,1,N,pos[x][p],lst,c);
    if(p+3<(int)pos[x].size()){
        upd(1,1,N,pos[x][p+3],N,c);
    }
}

int main(){
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&arr[i]);
		pos[arr[i]].pb(i);
	}
	build(1,1,N);
	for(i=1;i<=N;i++){
		if(pos[i].empty()) continue;
		add(i,0,1);
	}
	for(i=1;i<=N;i++){
		pii go = qu(1,1,N,i,N);
		if(go.F==0) ans += go.S;
		int hm = arr[i];
		add(hm,cur[hm],-1);
		cur[hm]++;
		if(cur[hm]<(int)pos[hm].size()) add(hm,cur[hm],1);
	}
	printf("%lld\n",ans);
	return 0;
}