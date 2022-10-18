#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, cnt = 0;
    cin >> n >> m;
    int a[n], b[m], c[m];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    for (int j = 0; j < m; j++){
        cin >> b[j];
        cnt += b[j];
    }
    for (int i = cnt - 1; i < n; i++){
        memset(c, 0, sizeof(c));
        for (int j = i - cnt + 1; j <= i; j++){
            c[a[j]]++;
        }
        bool ck = 1;
        for (int j = 0; j < m; j++){
            if (b[j] != c[j]){
                ck = 0;
                break;
            }
        }
        if (ck){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}