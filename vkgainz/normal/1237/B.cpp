#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n; cin >> n;
    int a[n]; for(int i=0;i<n;i++) cin >> a[i];
    int b[n];
    for(int i=0;i<n;i++) cin >> b[i];
    int ent[n];
    int exi[n];
    for(int i=0;i<n;i++)
        ent[--a[i]] = i;
    for(int i=0;i<n;i++)
        exi[--b[i]] = i;
    int r =0;
    vector<pair<int,int>> x;
    for(int i=0;i<n;i++)
        x.push_back(make_pair(ent[i],exi[i]));
    sort(x.begin(),x.end());
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(x[i].second<r)
            ++cnt;
        r = max(r,x[i].second);
    }
    cout << cnt << endl;
}