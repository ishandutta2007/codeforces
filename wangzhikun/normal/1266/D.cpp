#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int n,m,u,v,d,bal[100010];
__gnu_pbds::gp_hash_table<int,ll> L[100010];
ll sgn(ll x){
	if(x>0)return 1;
	else return -1;
}
signed main() {
	read(n);read(m);
	for(int i=0;i<m;i++){
		read(u);read(v);read(d);
		L[u][v]+=d;
		L[v][u]-=d;
	}
	for(int i=1;i<=n;i++){
		vector< pii > V;
		vector< pii > M;
		for(auto ct:L[i]){
			if(ct.second == 0)continue;
			M.push_back(ct);
		}
		for(auto ech:M){
			//cout<<ech.first<<' '<<ech.second<<endl;
			pii ct = ech;
			if(ct.second == 0)continue;
			if(!V.size() || sgn(V[V.size()-1].second) == sgn(ct.second)){
				V.push_back(ct);
				continue;
			}
			while(abs(ct.second)>0 && V.size()){
				pii cc = V[V.size()-1];
				V.pop_back();
				ll cm = min(abs(ct.second),abs(cc.second));
				ll cv = cm*sgn(cc.second);
				L[i][cc.first] -=cv;
				L[cc.first][i] +=cv;
				L[cc.first][ct.first] -=cv;
				L[ct.first][cc.first] +=cv;
				ct.second+=cv;
				cc.second-=cv;
				if(cc.second!=0){
					V.push_back(cc);
				}
			}
			L[i][ct.first] = ct.second;
			L[ct.first][i] = -ct.second;
			if(ct.second!=0)V.push_back(ct);
		}
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		for(auto ct:L[i]){
			if(ct.second>0)cnt++;
		}
	}
	cout<<cnt<<'\n';
	
	for(int i=1;i<=n;i++){
		for(auto ct:L[i]){
			if(ct.second>0)cout<<i<<' '<<ct.first<<' '<<ct.second<<'\n';
		}
	}
	return 0;
}