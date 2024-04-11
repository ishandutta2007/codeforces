#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 1e6+5;
int n;
vector<int> adj[2*MX];
vector<int> s[2*MX];
int c[2*MX];
int num[2*MX];
vector<int> print[MX];
void dfs(int curr) {
    for(int next : adj[curr]) {
        if(c[next]==-1) {
            c[next] = 1-c[curr];
            dfs(next);
        }
    }
}
int main() {
    cin >> n;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if(n%2==0) {
        cout << "First" << "\n";
        cout << flush;
        int ans[2*n+1];
        int v = 0;
        ++v;
        for(int i=0;i<n-2;i+=2) {
            ans[i+1] = v, ans[i+2] = v;
            ++v;
        }
        ans[n-1] = v, ans[2*n-1] = v;
        ++v;
        ans[n] = v, ans[2*n] = v;
        ++v;
        for(int i=n;i<2*n-2;i+=2) {
            ans[i+1] = v, ans[i+2] = v;
            ++v;
        }
        for(int i=1;i<=2*n;i++)
            cout << ans[i] << " ";
        cout << "\n";
        cout << flush;
        int x; cin >> x;
    }
    else {
        cout << "Second" << "\n";
        cout << flush;
        for(int i=0;i<2*n;i++) {
            int x; cin >> x;
            s[x].push_back(i+1);
            num[i+1] = x;
        }
        for(int i=1;i<=n;i++) {
            adj[s[i][0]].push_back(s[i][1]);
            adj[s[i][1]].push_back(s[i][0]);
        }
        for(int i=1;i<=n;i++) {
            adj[i].push_back(i+n);
            adj[i+n].push_back(i);
        }
        memset(c,-1,sizeof(c));
        for(int i=1;i<=2*MX;i++) {
            if(c[i]==-1) {
                c[i] = 0;
                dfs(i);
            }
        }
        ll sum = 0;
        bool one = 1;
        for(int i=1;i<=2*MX;i++) {
            if(c[i]==1) sum+=i;
        }
        if(sum%(2*n)!=0) one = 0;
        for(int i=1;i<=2*n;i++) {
            if(one) {
                if(c[i]==1) print[num[i]].push_back(i);
            }
            else {
                if(c[i]==0) print[num[i]].push_back(i);
            }
        }
        for(int i=1;i<=n;i++) {
            cout << print[i][0] << " ";
        }
        cout << flush;
        int x; cin >> x;
        return 0;
    }
}