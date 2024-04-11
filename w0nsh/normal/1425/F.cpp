#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

#define sz(s) (int)s.size()
#define pb push_back
#define all(s) s.begin(), s.end()
#define f first
#define s second
#define FOR(i, s) for(int i = 0; i < s; i++)

typedef long long ll;

const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const ll BIG_INF = 1e18;
const int T = (1<<19);

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define vvi vector<vector<int> >

template<class T> inline T gcd(T a, T b) { while (b)swap(a %= b, b); return abs(a); }

void solve(){
    int n;
    cin >> n;

    cout << "? 1 3" << endl;
    int a;
    cin >> a;

    cout << "? 2 3" << endl;
    int b;
    cin >> b;

    cout << "? 1 2" << endl;
    int c;
    cin >> c;

    vi tab(n + 1);
    tab[3] = a - c;
    tab[1] = a - b;
    tab[2] = a - tab[1] - tab[3];

    for(int i = 4; i <= n; i++){
        cout << "? " << i - 1 << ' ' << i << endl;
        int temp;
        cin >> temp;
        tab[i] = temp - tab[i - 1];
    }

    cout << "! ";
    for(int i = 1; i <= n; i++)
        cout << tab[i] << ' ';
    cout << endl;
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }
}