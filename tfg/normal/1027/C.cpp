#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define ld long double
#define vll vector<ll>
#define mll vector<vll>
#define pb push_back
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound
#define bpc __builtin_popcount
#define gcd __gcd
#define all(ds) (ds).begin(), (ds).end()
#define inf 0x3f3f3f3f
const ld PI = acos(-1.0L);
const ld eps = 0.000001L;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(0) << fixed;
    
    ll t;
    cin >> t;
    
    ll n;
    vll vec;
    while(t--){
        cin >> n;
        vec.clear(); vec.resize(n);
        
        for(int i = 0 ; i < n ; i++) cin >> vec[i];
        sort(all(vec));
        
        vll stick;
        for(int i = 1 ; i < n ; i++){
            if(vec[i] == vec[i-1]){
                stick.pb(vec[i]);
                i++;
            }
        }
        
        ld mini = -1;
        ld x, y, val;
        ld ansx, ansy;
        for(int i = 1 ; i < stick.size() ; i++){
            x = stick[i-1]; y = stick[i];
            val = (x/y + y/x);
            if(mini == -1 || mini > val){
                mini = val;
                ansx = x;
                ansy = y;
            }
        }
        
        cout << ansx << " " << ansx << " " << ansy << " " << ansy << endl;
    }
    //
    return 0;
}