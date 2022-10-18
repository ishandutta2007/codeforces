#include <iostream>
using namespace std;

int main(){
    int n, count = 0, i, a, b, c;
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a >> b >> c;
        if ((a + b + c) >= 2) count++;
    }
    cout << count;
}