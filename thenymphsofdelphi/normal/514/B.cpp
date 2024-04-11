#include<bits/stdc++.h>
using namespace std;

const int N = 10010;

int n, x[N], y[N];
bool ck[N];

int main(){
    cin >> n;
    for (int i = 0; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (!ck[i]){
            ans++;
            ck[i] = 1;
            int xt = x[i] - x[0], yt = y[i] - y[0];
            for (int j = 1; j <= n; j++){
                if (xt * (y[j] - y[0]) == yt * (x[j] - x[0])){
                    ck[j] = 1;
                }
            }
        }
    }
    cout << ans;
}