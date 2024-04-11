#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, l, r, dis;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++){
        if (s[i] == 'G'){
            l = i;
        }
        if (s[i] == 'T'){
            r = i;
        }
    }
    dis = abs(r - l);
    if (dis % k != 0){
        cout << "NO";
        return 0;
    }
    if (l > r){
        k = -k;
    }
    for (int i = l + k; i != r; i += k){
        if (s[i] == '#'){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}