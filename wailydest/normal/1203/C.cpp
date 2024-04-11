#include <iostream>
#include <cmath>
using namespace std;

long long GCD(long long a, long long b);
int divisors_amount(long long n);

int main()
{
    int n;
    long long num;
    cin >> n;
    
    long long gcd;
    cin >> gcd;
    gcd = abs(gcd);
    while (--n) {
        cin >> num;
        gcd = GCD(gcd, abs(num));
    }
    cout << divisors_amount(gcd);
    
    return 0;
}

inline long long GCD(long long a, long long b)
{
    while (a && b) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a ? a : b;
}
int divisors_amount(long long n)
{
    if (n == 1) return 1;
    int amount = 1;
    for (int i = 2; i < sqrt(n); ++i) if (!(n % i)) ++amount;
    amount *= 2;
    if (sqrt(n) == (int)sqrt(n)) ++amount;
    return amount;
}