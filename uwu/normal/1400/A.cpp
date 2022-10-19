#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        int cnt0=0,cnt1=0;
        for (char x:s){
            if (x=='0') cnt0++;
            if (x=='1') cnt1++;
        }
        if (cnt0>cnt1){
            for (int i=1;i<=n;++i){
                cout << "0";
            }
        }
        else{
            for (int i=1;i<=n;++i){
                cout << "1";
            }
        }
        cout << '\n';
    }
}