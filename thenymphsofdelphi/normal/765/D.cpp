#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n;
int a[N];
int b[N];
int c[N];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int idx = 1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    bool ck = 0;
    for (int i = 1; i <= n; i++){
        if (a[a[i]] != a[i]){
            ck = 1;
            break;
        }
    }
    if (ck){
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++){
        if (a[i] == i){
            c[idx] = i;
            b[i] = idx;
            idx++;
        }
    }
    for (int i = 1; i <= n; i++){
        if (a[i] != i){
            b[i] = b[a[i]];
        }
    }
    idx--;
    cout << idx << endl;
    for (int i = 1; i <= n; i++){
        cout << b[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= idx; i++){
        cout << c[i] << ' ';
    }
    cout << endl;
}