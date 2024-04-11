#include<bits/stdc++.h>
using namespace std;

int n, ans;

int main(){
    cin >> n;
    while (n--){
        int x; cin >> x; int t = 2, sum = 1;
        while (sum + t <= x){
            sum += t;
            t++;
        }
        t--;
        ans ^= t;
    }
    if (ans == 0) cout << "YES";
    else cout << "NO";
}