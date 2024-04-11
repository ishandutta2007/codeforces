#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a[3], count = 0, i, j, temp, nt;
    cin >> n >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    for (i = 0; i <= n / a[0]; i++){
        nt = n - i * a[0];
        for (j = 0; j <= nt / a[1]; j++){
            if ((nt - j * a[1]) % a[2] == 0){
                temp = i + j + (nt - j * a[1]) / a[2];
                count = max(count, temp);
            }
        }
    }
    cout << count;
}