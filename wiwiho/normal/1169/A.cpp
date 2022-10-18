#include <bits/stdc++.h>

using namespace std;

//#define TEST

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;

    bool ans = false;
    for(int t = 1; ; t++){
        a++;
        if(a > n){
            a = 1;
        }
        b--;
        if(b < 1){
            b = n;
        }
        if(a == b){
            ans = true;
            break;
        }
        if(a == x){
            break;
        }
        if(b == y){
            break;
        }
    }

    cout << (ans ? "YES" : "NO") << "\n";
    
    return 0;
}