#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

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
        int c0=0,c1=0; 
        for (char x:uwu){
            c0+=x=='0';
            c1+=x=='1';
        }
        cout << (min(c0,c1)%2==1?"DA":"NET") << '\n';
    }
}