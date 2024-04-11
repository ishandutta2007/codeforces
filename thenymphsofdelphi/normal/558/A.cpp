#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second

signed main(){
    int n, sum = 0, p, q;
    cin >> n;
    vector <pair <int, int> > pos, neg;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if (x < 0){
            neg.pb(mp(-x, y));
        }
        else{
            pos.pb(mp(x, y));
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    p = pos.size();
    q = neg.size();
    int idx = 0;
    while (1){
        if (idx == p){
            if (idx == q){
                break;
            }
            sum += neg[idx].se;
            break;
        }
        if (idx == q){
            sum += pos[idx].se;
            break;
        }
        sum += pos[idx].se;
        sum += neg[idx].se;
        idx++;
    }
    cout << sum;
}