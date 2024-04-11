#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

map<char,int> m;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        string uwu; cin >> uwu;
        m.clear();
        for (int i=0;i<uwu.size();++i) m[uwu[i]]++;
        char ans;
        if (m['R']>=m['S'] && m['R']>=m['P']) ans='P';
        if (m['P']>=m['S'] && m['P']>=m['R']) ans='S';
        if (m['S']>=m['R'] && m['S']>=m['P']) ans='R';
        for (int i=0;i<uwu.size();++i) cout << ans;
        cout << '\n';
    }
}