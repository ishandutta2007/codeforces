#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <stack>
#include <set>
#include <list>
using namespace std;
//8739

const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 1000000010;
const long long MAXLL = 1000000000000000000;

template <typename T>
inline T MIN(T lef, T ri)
{
    return (lef < ri ? lef : ri);
}

template <typename T>
inline T MAX(T lef, T ri)
{
    return (lef > ri ? lef : ri);
}

template <typename T>
inline T MOD(T val)
{
    return (val > 0 ? val : -val);
}

#pragma comment(linker, "/STACK:167772160")

int main(){
    ios_base::sync_with_stdio(0);
    int n, res[100001], r[100001];
    cin >> n;
    if (n == 4)
    {
        cout << "YES\n1\n3\n2\n4";
        return 0;
    }
    for(int i(2); i * i <= n; ++i)
    if(!(n % i))
    {
        cout << "NO";
        return 0;
    }
    res[1] = 1;
    res[2] = 2;
    res[n] = n;
    r[1] = 1;
    for (int i = 2; i < n; ++i)
        r[i] = (n - (n / i) * r[n % i] % n) % n;
    for(int i(3); i < n; ++i)
        res[i] = r[i - 1] + 1;
    cout << "YES\n";
    for(int i(1); i <= n; ++i) 
        cout << res[i] << '\n';
    return 0;
}