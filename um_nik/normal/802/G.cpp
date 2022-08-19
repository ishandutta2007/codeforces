#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    int n = s.length();
    string p = "heidi";
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        if (q < 5 && s[i] == p[q])
            q++;
    }
    if (q == 5)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}