
 #include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 1; i < n; i++){
        if (a[i] + a[i - 1] < k){
            sum += k - a[i] - a[i - 1];
            a[i] += k - a[i] - a[i - 1];
        }
    }
    cout << sum << endl;
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}