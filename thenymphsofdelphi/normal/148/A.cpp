#include<iostream>
using namespace std;

int main(){
    int a, b, c, d, n, cnt, i;
    cin >> a >> b >> c >> d >> n;
    cnt = n;
    for (i = 1; i <= n; i++){
        if (i % a != 0 && i % b != 0 && i % c != 0 && i % d != 0){
            cnt--;
        }
    }
    cout << cnt;
}