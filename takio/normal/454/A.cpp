#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int num = min((i * 2 - 1), 2 * n - i * 2 + 1);
        for (int j = 1; j <= (n - num) / 2; j++) cout << '*';
        for (int j = 1; j <= num; j++) cout << 'D';
        for (int j = 1; j <= (n - num) / 2; j++) cout << '*';
        cout << endl;
    }
}