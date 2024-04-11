#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int MN = 2e5+5;
int N, Q, i, t, x, y, ds[MN]; pii st[3*MN];
vector<int> vec[MN];
int fnd(int x){return ds[x]=x==ds[x]?x:fnd(ds[x]);}

void upd(int i,int s,int e,int ind,int val){
	if(s^e){
		if((s+e)/2<ind) upd(2*i+1,(s+e)/2+1,e,ind,val);
		else upd(2*i,s,(s+e)/2,ind,val);
		st[i].F=min(st[2*i].F,st[2*i+1].F);
		st[i].S=max(st[2*i].S,st[2*i+1].S);
	}
	else st[i]=make_pair(val,val);
}

pii qu(int i,int s,int e,int ss,int se){
	if(s>=ss&&e<=se) return st[i];
	else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
	else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
	else{
		pii l=qu(2*i,s,(s+e)/2,ss,se), r=qu(2*i+1,(s+e)/2+1,e,ss,se);
		return make_pair(min(l.F,r.F),max(l.S,r.S));
	}
}

inline void mrg(int x,int y){
	x=fnd(x), y=fnd(y);
	if(x^y){
		if(vec[x].size()<vec[y].size()) swap(x,y);
		ds[y] = x;
		for(auto v : vec[y]){
			upd(1,1,N,v,fnd(v));
			vec[x].push_back(v);
		}
		vec[y].clear();
	}
}

int main(){
	scanf("%d%d",&N,&Q);
	for(i=1;i<=N;i++){
		ds[i]=i;
		vec[i].push_back(i);
		upd(1,1,N,i,i);
	}
	for(;Q;Q--){
		scanf("%d%d%d",&t,&x,&y);
		if(t==3) printf("%s\n",fnd(x)==fnd(y)?"YES":"NO");
		else if(t==1) mrg(x,y);
		else if(t==2){
			pii hm = qu(1,1,N,x,y);
			while(hm.F^hm.S){
				mrg(hm.F,hm.S);
				hm = qu(1,1,N,x,y);
			}
		}
	}
	return 0;
}