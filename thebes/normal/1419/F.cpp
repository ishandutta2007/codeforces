#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 1005;
int N, i, j, x, y, lo, hi, mid, ds[MN], vs[MN], sz[MN], rx[MN], ry[MN], ccnt;
pii pos[MN]; map<int,int> X, Y;
vi ex[MN], ey[MN]; vector<pii> elem[6*MN*MN];
int fnd(int x){return ds[x]=x==ds[x]?x:fnd(ds[x]);}
inline void mrg(int x,int y){
	x = fnd(x), y = fnd(y);
	if(x^y) ds[x] = y, sz[y] += sz[x];
}

int main(){
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d%d",&x,&y);
		pos[i] = {x, y};
		X[x] = Y[y] = 0;
	}
	int cnt = 0;
	for(auto it=X.begin();it!=X.end();it++)
		it->second = ++cnt, rx[cnt] = it->first;
	cnt = 0;
	for(auto it=Y.begin();it!=Y.end();it++)
		it->second = ++cnt, ry[cnt] = it->first;
	for(i=1;i<=N;i++){
		ex[X[pos[i].F]].pb(i);
		ey[Y[pos[i].S]].pb(i);
	}
	for(i=1;i<=(int)X.size();i++){
		sort(ex[i].begin(),ex[i].end(),[](int i,int j){return pos[i].S<pos[j].S;});
	}
	for(i=1;i<=(int)Y.size();i++){
		sort(ey[i].begin(),ey[i].end(),[](int i,int j){return pos[i].F<pos[j].F;});
	}
	for(i=1;i<=(int)X.size();i++){
		for(j=1;j<=(int)Y.size();j++){
			lo = 0, hi = (int)ex[i].size();
			while(lo<hi){
				mid = (lo+hi)>>1;
				if(pos[ex[i][mid]].S>=ry[j]) hi=mid;
				else lo=mid+1;
			}
			++ccnt;
			if(lo!=ex[i].size()) elem[ccnt].pb({pos[ex[i][lo]].S-ry[j],ex[i][lo]});
			if(lo) elem[ccnt].pb({ry[j]-pos[ex[i][lo-1]].S,ex[i][lo-1]});
			lo = 0, hi = (int)ey[j].size();
			while(lo<hi){
				mid = (lo+hi)>>1;
				if(pos[ey[j][mid]].F>=rx[i]) hi=mid;
				else lo=mid+1;
			}
			if(lo!=ey[j].size()) elem[ccnt].pb({pos[ey[j][lo]].F-rx[i],ey[j][lo]});
			if(lo) elem[ccnt].pb({rx[i]-pos[ey[j][lo-1]].F,ey[j][lo-1]});
		}
	}
	for(i=1;i<=(int)X.size();i++){
        for(j=0;j+1<(int)ex[i].size();j++){
            int px = (1LL*pos[ex[i][j]].S+pos[ex[i][j+1]].S)>>1;
            ++ccnt;
            elem[ccnt].pb({pos[ex[i][j+1]].S-px,ex[i][j+1]});
            elem[ccnt].pb({px-pos[ex[i][j]].S,ex[i][j]});
        }
	}
	for(i=1;i<=(int)Y.size();i++){
        for(j=0;j+1<(int)ey[i].size();j++){
            int py = (1LL*pos[ey[i][j+1]].F+pos[ey[i][j]].F)>>1;
            ++ccnt;
            elem[ccnt].pb({pos[ey[i][j+1]].F-py,ey[i][j+1]});
            elem[ccnt].pb({py-pos[ey[i][j]].F,ey[i][j]});
        }
	}
	lo = 0, hi = 2e9+5;
	int tot = 0;
	while(lo<hi){
		mid = (1LL*lo+hi)>>1;
		for(i=1;i<=N;i++)
			ds[i] = i, sz[i] = 1;
		for(i=1;i<=(int)X.size();i++){
			for(j=0;j+1<(int)ex[i].size();j++){
				if(pos[ex[i][j+1]].S-pos[ex[i][j]].S<=mid) mrg(ex[i][j+1],ex[i][j]);
			}
		}
		for(i=1;i<=(int)Y.size();i++){
			for(j=0;j+1<(int)ey[i].size();j++){
				if(pos[ey[i][j+1]].F-pos[ey[i][j]].F<=mid) mrg(ey[i][j+1],ey[i][j]);
			}
		}
		for(i=1;i<=N;i++) fnd(i);
		int fl = 0;
		for(i=1;i<=ccnt;i++){
            tot = 0;
            for(auto v : elem[i]){
                if(v.F<=mid&&!vs[ds[v.S]]){
                    vs[ds[v.S]]=1;
                    tot += sz[ds[v.S]];
                }
            }
            for(auto v : elem[i]){
                vs[ds[v.S]] = 0;
            }
            if(tot==N){
                fl = 1;
                break;
            }
		}
		if(fl) hi=mid;
		else lo=mid+1;
	}
	if(lo>2e9) printf("-1\n");
	else printf("%d\n",lo);
	return 0;
}