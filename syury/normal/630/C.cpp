#include<iostream>

using namespace std;

int main(){
    int n; long long ans = 1ll;
    cin >> n;
    ans <<= (n + 1);
    cout << ans - 2 << endl;
    return 0;
}