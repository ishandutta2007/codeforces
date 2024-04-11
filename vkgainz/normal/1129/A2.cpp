#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
int n;
int dist(int st, int en) {
    if(en-st<0) return en-st+n;
    return en-st;
}
int main(){
    cin >> n;
    int m; cin >> m;
    vector<int> pos[n];
    for(int i=0;i<m;i++) {
        int a,b; cin >> a >> b;
        pos[--a].push_back(--b);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<pos[i].size();j++) {
            pos[i][j] = dist(i, pos[i][j]);
        }
        sort(pos[i].begin(),pos[i].end());
    }
    vector<int> ans(n);
    for(int s=0;s<n;s++) {
        int mx = 0;
        for(int i=0;i<n;i++) {
            if(pos[i].size()>0) {
                int x = pos[i][0];
                int y = pos[i].size()-1;
                mx = max(mx,n*(y)+x+dist(s,i));
            }
        }
        ans[s] = mx;
    }
    for(int i=0;i<n;i++) cout << ans[i] << endl;
}