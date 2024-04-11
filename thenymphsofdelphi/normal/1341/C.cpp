#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N], b[N];

int main(){
int t; cin >> t;
while (t--){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[a[i]] = i;
    }
    int idx = 1, mn = n;
    bool ck = 1;
    while (idx <= n){
        int x = b[idx], new_mn = x - 1;
        while (x <= mn){
            // cout << x << ' ' << idx << ' ' << b[idx] << endl;
            if (b[idx] != x){
                ck = 0;
                break;
            }
            x++;
            idx++;
        }
        if (!ck){
            break;
        }
        mn = new_mn;
    }
    if (ck){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
}