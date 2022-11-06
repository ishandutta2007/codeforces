#include <iostream>
using namespace std;

long long int a, b, n, counter;

int main() {
    cin >> a >> b >> n;
    a += (n - a % n) % n;
    b += (n - b % n) % n;
    cout << a * b / n / n;
}