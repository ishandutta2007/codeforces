#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n);
        map<int,int> odd1, odd2;
        for (int i=0;i<n;++i){
            cin >> a[i];
            if (i%2) odd1[a[i]]++;
        }
        sort(a.begin(),a.end());
        for (int i=0;i<n;++i){
            if (i%2) odd2[a[i]]++;
        }
        cout << (odd1==odd2?"YES":"NO") << '\n';
    }
}