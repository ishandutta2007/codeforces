#include<bits/stdc++.h>
#define fi first
#define se second
#define EB emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=1005,INF=0X3F3F3F3F;
int n,m[N];
vector<int>G[N];
bitset<N>a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&m[i]);
		rep(j,1,m[i]){
			int x;scanf("%d",&x);
			a[i].set(x);
		}
	}
	int f=0;
	bitset<N>good;
	vector<pair<int,int> >ans;
	set<pair<int,int> >S;
	auto ae=[&](int k1,int k2){
		if(S.count(minmax(k1,k2)))return;
		S.insert(minmax(k1,k2));
		G[k1].EB(k2);
		G[k2].EB(k1);
		ans.EB(k1,k2);
	};
	rep(i,1,n)rep(j,1,n){
		bitset<N>cur(a[i]&a[j]);
		if(cur.count()==2){
			++f;
			int k1=cur._Find_first();
			int k2=cur._Find_next(k1);
			good.set(k1),good.set(k2);
			ae(k1,k2);
		}
	}
	if(!f){
		rep(i,2,n)printf("%d %d\n",1,i);
		exit(0);
	}
	if(f==1){
		int k1,k2;
		tie(k1,k2)=ans.back();
		printf("%d %d\n",k1,k2);
		bitset<N>cur;
		rep(i,1,n)if(m[i]<n){
			cur=a[i];
		}
		rep(i,1,n){
			if(i==k1||i==k2)continue;
			if(cur.test(i))printf("%d %d\n",k1,i);
			else printf("%d %d\n",k2,i);
		}
		exit(0);
	}
	rep(i,1,n){
		if(G[i].empty()){
			bitset<N>cur;
			int num=INF;
			rep(j,1,n){
				if(a[j].test(i)&&m[j]<num){
					cur=a[j];
					num=m[j];
				}
			}
			rep(j,1,n){
				if(G[j].empty()){
					cur.reset(j);
				}
			}
			bitset<N>tmp;
			rep(j,1,n){
				if(i!=j){
					tmp.reset();
					for(auto it:G[j]){
						if(!G[it].empty()){
							tmp.set(it);
						}
					}
					if(!G[j].empty()){
						tmp.set(j);
					}
					if(cur==tmp){
						ae(i,j);
						break;
					}
				}
			}
		}
	}
	for(auto x:ans){
		int k1,k2;
		tie(k1,k2)=x;
		printf("%d %d\n",k1,k2);
	}
	assert(SZ(ans)==n-1);
	return 0;
}