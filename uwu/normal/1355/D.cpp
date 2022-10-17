#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,s; cin >> n >> s;
    if (n>s/2){
        cout << "no" << '\n';
        return 0;
    }
    cout << "yes" << '\n';
    for (int i=1;i<=n-1;++i){
        cout << 1 << " ";
    }
    cout << s-n+1 << '\n';
    cout << s/2 << '\n';
}