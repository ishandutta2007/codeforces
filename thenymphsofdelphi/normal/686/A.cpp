#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, x, m, cnt = 0;
    char d;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> d >> x;
        if (d == '+'){
            m += x;
        }
        else{
            if (m < x){
                cnt++;
            }
            else{
                m -= x;
            }
        }
    }
    cout << m << " " << cnt;
}