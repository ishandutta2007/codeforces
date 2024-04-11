#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
    ll i,x,n,k,s,y,rez;
int main()
{
    rez = -1;
    cin >> n;
    rez = 0;
    for (i = 0; i < n; i++)
    {
        cin >> k;
        rez = max(rez,k);
    }
    cout << rez << endl;
    return 0;
}