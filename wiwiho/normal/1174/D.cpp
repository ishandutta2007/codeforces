#include <bits/stdc++.h>

#define lsort(a) sort(a.begin(), a.end())
#define gsort(a) sort(a.rbegin(), a.rend())

//#define TEST

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> s;
    set<ll> b;
    b.insert(0);
    s.push_back(0);

    for(ll i = 1; i < (1 << n); i++){

        if(i == x){
            continue;
        }

        if(b.find(i ^ x) == b.end()){
            b.insert(i);
            s.push_back(i);
        }

    }

    cout << (s.size() - 1) << "\n";
    for(int i = 1; i < s.size(); i++){
        cout << (s[i] ^ s[i - 1]) << " ";
    }
    cout << "\n";
    
    return 0;
}