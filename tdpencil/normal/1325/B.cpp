#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector
#define si(a) int(a.size())
#define len(ar) ar.size()

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        set<ll> y;
        ll a;
        cin >> a;
        for(int i =0;i< a;i++){
            ll b;
            cin >> b;
            y.insert(b);
        }
        cout << si(y) << '\n';
    }
        



}