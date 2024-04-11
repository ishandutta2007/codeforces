#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ll long long
using namespace std;


int k[300005];
int c[300005];

void solve(){
    int n, m;
    cin >> n >> m;
    ff(i,1,n)cin >> k[i];
    ff(i,1,m)cin >> c[i];
    ll sum = 0;
    ff(i,1,n)sum += c[k[i]];

    multiset<int> setara;
    ff(i,1,m)setara.insert(c[i]);

    int ord[n];
    ff(i,0,n-1)ord[i] = i + 1;
    sort(ord, ord + n, [&](int i, int j){
        return k[i] > k[j];
    });
    ff(j,0,n-1){
        int i = ord[j];
        auto it = setara.begin();
        if(*it < c[k[i]]){
            sum -= c[k[i]];
            sum += *it;
            setara.erase(it);
        }
    }
    cout << sum << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--)solve();
    return 0;
}