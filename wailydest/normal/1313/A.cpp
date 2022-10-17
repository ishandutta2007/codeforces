#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    int a, b, c;
    int amount;
    while (t--)
    {
        amount = 0;
        cin >> a >> b >> c;
        if (a < b) swap(a, b);
        if (c > b) swap(b, c);
        if (a < b) swap(a, b);
        if (a > 0) ++ amount; --a;
        if (b > 0) ++ amount; --b;
        if (c > 0) ++ amount; --c;
        if (a > 0 && b > 0) ++ amount; --a; --b;
        if (a > 0 && c > 0) ++ amount; --a; --c;
        if (b > 0 && c > 0) ++ amount; --b; --c;
        if (a > 0 && b > 0 && c > 0) ++ amount;
        cout << amount << '\n';
    }
}