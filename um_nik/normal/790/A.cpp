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

const int N = 100;
int n, k;
int a[N];
bool used[N];

string getName(int x)
{
    string s = "";
    s += 'A' + x / 26;
    s += 'a' + x % 26;
    return s;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < k - 1; i++)
        a[i] = i;
    for (int i = k - 1; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "NO")
        {
            a[i] = a[i - k + 1];
            continue;
        }
        for (int j = 0; j <= k; j++)
            used[j] = 0;
        for (int j = 1; j < k; j++)
            used[a[i - j]] = 1;
        a[i] = 0;
        while(used[a[i]]) a[i]++;
    }
    for (int i = 0; i < n; i++)
        cout << getName(a[i]) << " ";
    cout << endl;

    return 0;
}