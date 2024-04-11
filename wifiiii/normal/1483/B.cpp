#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
const int maxn = 100005;
int par[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
vector<int> solve(vector<int> a) {
    int n=a.size();
    vector<int> vis(n);
    queue<pair<int,int>> q;
    for(int i=0;i<n;++i) {
        if(gcd(a[i],a[(i+1)%n])==1) q.push({i,(i+1)%n});
    }
    for(int i=0;i<=n;++i) par[i]=i;
    vector<int> ans;
    while(!q.empty()) {
        auto cur=q.front();q.pop();
        if(vis[cur.first]) continue;
        ans.push_back(cur.second);
        vis[cur.second]=1;
        assert(par[cur.second]==cur.second);
        int nxt=find((cur.second+1)%n);
        par[cur.second]=nxt;
        if(gcd(a[cur.first], a[nxt])==1) q.push({cur.first,nxt});
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n),vis(n);
        for(int i=0;i<n;++i) cin>>a[i];
        vector<int> ans=solve(a);
        cout<<ans.size()<<" ";
        for(int i:ans) cout<<i+1<<" ";cout<<'\n';
    }
}