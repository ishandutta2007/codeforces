#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[12], k, cnt = 0, s = 0, sum = 0;
    cin >> k;
    for (int i = 0; i < 12; i++){
        cin >> a[i];
        sum += a[i];
    }
    if (sum < k){
        cout<< "-1";
        return 0;
    }
    sort(a, a + 12);
    int j = 11;
    while (s < k && cnt <= 12){
        cnt++;
        s += a[j];
        j--;
    }
    cout << cnt;
}