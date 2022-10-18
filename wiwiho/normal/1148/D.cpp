#include <bits/stdc++.h>

#define iter(a) a.begin(), a.end()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(iter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

//#define TEST

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

#define MAX 1000000000

bool compgr(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b){
    return less<pair<int, int>>()(a.second, b.second);
}

bool comple(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b){
    return greater<pair<int, int>>()(a.second, b.second);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> g;
    vector<pair<int, pair<int, int>>> l;

    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        if(a > b){
            g.push_back(mp(i, mp(a, b)));
        }
        else{
            l.push_back(mp(i, mp(a, b)));
        }
    }

    if(g.size() > l.size()){
        sort(iter(g), compgr);
        cout << g.size() << "\n";
        for(int i = 0; i < g.size(); i++){
            if(i != 0){
                cout << " ";
            }
            cout << g[i].first;
        }
        cout << "\n";
    }
    else{
        sort(iter(l), comple);
        cout << l.size() << "\n";
        for(int i = 0; i < l.size(); i++){
            if(i != 0){
                cout << " ";
            }
            cout << l[i].first;
        }
        cout << "\n";
    }
    
    return 0;
}