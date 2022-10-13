#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<int,int> cx;
map<int,int> cy;
map<int,vector<int>> queries;
vector<pair<int,int>> order;
int seg[500000];
int n;
void upd(int i,int v){
    seg[i+=n] = v;
    while(i>1){
        i/=2;
        seg[i] = seg[2*i]+seg[2*i+1];
    }
}
int query(int l,int r){
    l+=n; r+=n;
    int res = 0;
    while(l<r){
        if(l%2) res+=seg[l++];
        if(r%2) res+=seg[--r];
        l/=2; r/=2;
    }
    return res;
}
int main(){
    cin >> n;
    set<int> xp;
    set<int> yp;
    for(int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        xp.insert(x);
        yp.insert(y);
        order.push_back({x,y});
    }
    int v = 0;
    for(auto &it : xp) cx[it] = v++;
    v=0;
    for(auto &it : yp) cy[it] = v++;
    for(int i=0;i<n;i++){
        order[i].first = cx[order[i].first];
        order[i].second = cy[order[i].second];
        queries[order[i].second].push_back(order[i].first);
    }
    for(auto &it : queries)
        sort(it.second.begin(),it.second.end());
    int l = 0;
    ll ans = 0;
    for(int curr=n-1;curr>=0;curr--){
        l = 0;
        for(int x : queries[curr]){
            int s = query(l,x);
            upd(x,1);
            ans-=s*1LL*(s+1)/2;
            l = x+1;
        }
        int s = query(l,n);
        ans-=s*1LL*(s+1)/2;
        int a = query(0,n);
        ans+=a*1LL*(a+1)/2;
    }
    cout << ans << endl;
    
}