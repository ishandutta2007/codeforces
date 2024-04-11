#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;
int n,m,q;
long long ans=0;
vector<int> out[maxn];
long long din[maxn],dout[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		if (u>v) swap(u,v);
		out[u].push_back(v);
		dout[u]++,din[v]++;
	}
	for (int i=1;i<=n;++i){
		ans+=din[i]*dout[i];
	}
	cout<<ans<<endl;
	cin>>q;
	while(q--){
		int k;
		cin>>k;
		for (auto c:out[k]){
			out[c].push_back(k);
			ans-=din[c]*dout[c];
			din[c]--,dout[c]++;
			ans+=din[c]*dout[c];
		}
		ans-=din[k]*dout[k];
		dout[k]=0,din[k]+=out[k].size();
		ans+=din[k]*dout[k];
		out[k].clear();
		cout<<ans<<endl;
	}
	return 0;
}