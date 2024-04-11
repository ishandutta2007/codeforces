#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int n;
bool arr[51][51];
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n;
        char a;
        for (int i=1;i<=n;++i){
            for (int k=1;k<=n;++k){
                cin >> a;
                arr[i][k]=a-'0';
            }
        }
        bool yes=1;
        for (int i=1;i<n;++i){
            for (int k=1;k<n;++k){
                if (arr[i][k]) yes&=arr[i+1][k]|arr[i][k+1];
            }
        }
        if (yes) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
}