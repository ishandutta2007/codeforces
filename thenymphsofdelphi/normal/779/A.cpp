#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], b[n], cnt[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i] - 1]++;
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
        cnt[b[i] - 1]--;
    }
    int sum = 0;
    for (int i = 0; i < 5; i++){
        if (cnt[i] % 2 == 1 || cnt[i] % 2 == -1){
            cout << -1;
            return 0;
        }
        else{
            sum += abs(cnt[i]);
        }
    }
    cout << sum / 4;
}