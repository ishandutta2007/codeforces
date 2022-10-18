#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    if (n == 1){
        cout << "YES\n" << a[0] << " 1";
        return 0;
    }
    set <int> S;
    for (int i = 0; i < n - 1; i++){
        if (abs(a[i + 1] - a[i]) != 1){
            S.insert(abs(a[i + 1] - a[i]));
        }
        if (a[i + 1] == a[i]){
            cout << "NO";
            return 0;
        }
    }
    if (S.size() > 1){
        cout << "NO";
    }
    else{
        if (S.empty()){
            cout << "YES\n" << "1 1000000000";
            return 0;
        }
        int y = *S.begin();
        for (int i = 0; i < n - 1; i++){
            if ((a[i + 1] - a[i] == 1 && a[i] % y == 0) || (a[i] - a[i + 1] == 1 && a[i + 1] % y == 0)){
				cout << "NO";
				return 0;
			}
        }
        cout << "YES\n" << 1000000000 << " " << y;
    }
    return 0;
}