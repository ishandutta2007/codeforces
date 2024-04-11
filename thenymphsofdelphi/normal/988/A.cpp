#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    bool ck[200];
    for (int i = 0; i < 200; i++) ck[i] = false;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ck[a[i]] = true;
    }
    int cnt = 0;
    for (int i = 0; i < 200; i++) if (ck[i]) cnt++;
    if (cnt >= k){
        cout << "YES" << endl;
        cnt = 0;
        for (int i = 0; i < n; i++){
            if (ck[a[i]] && cnt < k){
                cnt++;
                cout << i + 1 << " ";
                ck[a[i]] = false;
            }
        }
        return 0;
    } 
    cout << "NO";
}