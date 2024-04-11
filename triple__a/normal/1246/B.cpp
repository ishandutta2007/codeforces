#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=100007; 
int n,k,val[maxn],ans=0,pw[17];
vector<int> p;
vector<pair<int,int> >vec;
bool vis[maxn];

void get_prime(){
	for (int i=2;i<maxn;++i){
		if (!vis[i]){
			p.push_back(i);
			for (int j=2;i*j<maxn;++j){
				vis[i*j]=1;
			}
		}
	}
}

inline bool ck(int u){
	int ans=1;
	for (int i=1;i<=k;++i){
		ans=ans*u;
		if (ans>maxn*maxn) return 0;
	}
	return 1;
}

inline void decomp(int u){
	for (auto c:p){
		if (u==1) break;
		if (u%c==0){
			int tmp=0;
			while (u%c==0){
				tmp++, u/=c;
			}
			vec.push_back({c,k*tmp});
		}
	}
}

inline int power(int u,int v){
	int ans=1;
	for (int i=1;i<=v;++i){
		ans*=u;
	}
	return ans;
}

int calc(){
	int ans=1;
	for (int i=0;i<vec.size();++i){
		ans=ans*power(vec[i].first,pw[i]);
	}
	return ans;
}

void dfs(int t,int dep){
	if (dep==vec.size()){
		int v=calc();
		if (v>=maxn||t/v>=maxn||v*v>t) return;
		if (v*v==t) ans+=val[v]*(val[v]-1)/2;
		else ans+=val[v]*val[t/v];
		return;
	}
	for (int u=0;u<=vec[dep].second;++u){
		pw[dep]=u;
		dfs(t,dep+1);
	}
}
#undef int
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	get_prime();
	cin>>n>>k;
	for (int i=0;i<n;++i){
		int u;
		cin>>u;
		val[u]++;
	}
	for (int i=1;ck(i);++i){
		vec.clear();
		decomp(i);
		dfs(power(i,k),0);
	}
	cout<<ans<<endl;
	return 0;
}