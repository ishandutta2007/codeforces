#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        string uwu; cin >> uwu;
        bool flag=true;
        for (int i=1;i<uwu.size();++i){
            if (uwu[i]!=uwu[i-1]){
                flag=false;
                break;
            }
        }
        if (flag) cout << uwu << '\n';
        else{
            for (int i=0;i<uwu.size();++i){
                cout << "10";
            }
            cout << '\n';
        }
        
    }
}