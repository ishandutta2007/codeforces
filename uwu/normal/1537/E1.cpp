#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5001;

vector<string> v;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    for (int i=1;i<=n;++i){
        string tmp;
        for (int j=0;j<k;++j) tmp+=s[j%i];
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    cout << v[0] << '\n';
}