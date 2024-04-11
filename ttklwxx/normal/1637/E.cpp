#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,t,a[300500];
ll res;
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		map<int,int> mp;
		map<int,vector<int> >mp2;
		map<pair<int,int>,bool> sb;
		for(i=1;i<=n;i++){cin>>a[i];mp[a[i]]++;}
		for(auto [i,j]:mp)mp2[j].push_back(i);
		for(auto &[i,j]:mp2)sort(j.begin(),j.end()),reverse(j.begin(),j.end());
		for(i=1;i<=m;i++){cin>>j>>k;sb[{j,k}]=1;}ll ans=0ll;
		for(auto [i,v1]:mp2)for(auto [j,v2]:mp2){
			if(j>i)break;
			for(auto x:v1)for(auto y:v2){
				if(x==y||sb.count(make_pair(min(x,y),max(x,y))))continue;
				ans=max(ans,1ll*(1ll*x+1ll*y)*(i+j));break;
			}
		}
		cout<<ans<<"\n";
	}
}