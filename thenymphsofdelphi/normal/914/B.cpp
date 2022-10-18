#include <bits/stdc++.h>
using namespace std;

int cnt[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(cnt, 0, sizeof(cnt));
    int n, x;
    cin >> n;
    while (n--){
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= 1e5; i++){
        if (cnt[i] % 2 == 1){
            cout << "Conan";
            return 0;
        }
    }
    cout << "Agasa";
}