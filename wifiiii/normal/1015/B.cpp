#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

int chk(string s, string t) {
    sort(al(s));
    sort(al(t));
    return s == t;
}
int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if(!chk(s, t)) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    for(int i=0;i<t.size();++i) {
        auto it = find(s.begin()+i, s.end(), t[i]);
        assert(it != s.end());
        int pos = it - s.begin();
        for(int j=pos-1;j>=i;--j) {
            swap(s[j],s[j+1]);
            ans.push_back(j+1);
        }
        assert(s[i] == t[i]);
    }
    cout<<ans.size()<<endl;
    for(int i:ans) cout<<i<<" ";cout<<endl;
}