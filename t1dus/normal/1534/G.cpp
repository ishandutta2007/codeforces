#include<bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back

int n;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<pii> v;
    REP(i,n){
        int x,y; cin >> x >> y;
        v.pb({x+y,x-y});
    }
    sort(v.begin(),v.end());
    int ans = 0;
    priority_queue<int,vector<int>,less<int> > lft;
    priority_queue<int,vector<int>,greater<int> > rgt;
    lft.push(0);
    rgt.push(0);
    for(auto i:v){
        int shift = i.F;
        int lftborder = lft.top()-shift;
        int rgtborder = rgt.top()+shift;
        if(i.S < lftborder){
            lft.push(i.S+shift);
            lft.push(i.S+shift);
            lft.pop();
            rgt.push(lftborder-shift);
            ans += abs(i.S-lftborder);
        }
        else if(i.S > rgtborder){
            rgt.push(i.S-shift);
            rgt.push(i.S-shift);
            rgt.pop();
            lft.push(rgtborder+shift);
            ans += abs(i.S-rgtborder);
        }
        else{
            lft.push(i.S+shift);
            rgt.push(i.S-shift);
        }
    }
    ans /= 2;
    cout << ans << "\n";
}