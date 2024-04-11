#include <iostream>
using namespace std;
typedef long long ll;
ll n,k,i,j;
ll Abs(ll x)
{
    if (x < 0) return -x;
    return x;
}
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (Abs(i-n/2)+Abs(j-n/2) <= n/2)
                cout << "D";
            else
                cout << "*";
        cout << endl;
    }
    return 0;
}