#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m, a;
    cin >> n >> m >> a;
    cout << ((n-1)/a+1)*((m-1)/a+1);
    return 0;
}