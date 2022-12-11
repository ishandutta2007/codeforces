#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[N],deg[N];
long long s[N];
int main(){
    int t;
	ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i],a[i]-=b[i];
        vector<vector<int>>ope(n+1);
		vector<pair<int,int>>p(m+1);
        for(int i=1;i<=m;i++){
            deg[i]=2;
			auto &[l,r]=p[i];
			cin>>l>>r;
			ope[l-1].push_back(i);
			ope[r].push_back(i);
		}
        for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
        set<int>st;
        queue<int>q;
        for(int i=0;i<=n;i++){
            if(!s[i])q.push(i);
            else st.insert(i);
        }
        while(q.size()){
			int x=q.front();q.pop();
			for(int i:ope[x]){
                if(!--deg[i]){
                    auto [l,r]=p[i];
                    auto lt=st.lower_bound(l),rt=st.upper_bound(r);
                    for (auto it=lt;it!=rt;++it)q.push(*it);
                    st.erase(lt,rt);
                }
            }
        }
		cout<<(st.size()?"NO\n":"YES\n");
    }
    return  0;
}