#include <iostream>
#define int long long
using namespace std;

int n;

main(){
    cin >> n;
    cout << n / 2 - (n * (n % 2));
}