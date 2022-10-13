#include<bits/stdc++.h>
using namespace std;
#define ll long long

pair<int,int> need[2001];
int main(){
    int n,m;
    cin >> n >> m;
    int a[n], b[n];
    for(int i=0;i<n;i++) cin >> a[i] >> b[i];
    int c[m], d[m];
    for(int i=0;i<m;i++) cin >> c[i] >> d[i];
    vector<pair<int,int>> events;
    multiset<int> y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(c[j]>=a[i] && d[j]>=b[i]){
                events.push_back({c[j]-a[i]+1,d[j]-b[i]+1});
                y.insert(d[j]-b[i]+1);
            }
        }
    }
    sort(events.begin(),events.end());
    int ans = 0;
    if(!y.empty()) ans = *y.rbegin();
    for(int i=0;i<events.size();i++){
        int x=  events[i].first;
        y.erase(y.lower_bound(events[i].second));
        if(y.empty()){
            ans = min(ans,x);
        }
        else{
            ans= min(ans,x+*y.rbegin());
        }
    }
    cout << ans << endl;
    
}