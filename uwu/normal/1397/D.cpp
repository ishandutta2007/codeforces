#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

bool solve(){
    multiset<int> s;
    int n; cin >> n;
    for (int i=1,a;i<=n;++i) cin >> a, s.insert(a);
    int c1,c;
    while (true){
        if (s.empty()) return 0;
        c1=*(--s.end());
        s.erase(s.lower_bound(c1));

        if (s.empty()) return 1;
        c=*(--s.end());
        s.erase(s.lower_bound(c));
        if (c!=1) s.insert(c-1);
        if (c1!=1) s.insert(c1-1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cout << (solve()?"T":"HL") << '\n';
    }
}