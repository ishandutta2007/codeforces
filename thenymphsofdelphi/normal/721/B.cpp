#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, cnt = 0, cnteq = 0;
    cin >> n >> k;
    string a[n], s;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> s;
    int sl = s.length();
    sort(a, a + n);
    for (int i = 0; i < n; i++){
        if (a[i].length() < sl){
            cnt++;
        }
        else if (a[i].length() == sl && a[i] != s){
            cnteq++;
        }
    }
    int mn = cnt + 1 + (cnt / k) * 5;
    int mx = cnt + cnteq + 1 + ((cnt + cnteq) / k) * 5;
    cout << mn << " " << mx;
}