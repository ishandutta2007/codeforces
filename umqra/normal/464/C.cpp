#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const ll mod = (ll)1e9 + 7;

ll add(ll a, ll b)
{
    a = (a + b) % mod;
    if (a < 0)
        return a + mod;
    return a;
}

ll mult(ll a, ll b)
{
    ll c = a * b;
    return c % mod;
}

struct Item
{
    ll val;
    ll len;
    Item () {}
    Item (ll a, ll b) : val(a), len(b) {}
};

const int N = (int)1e5 + 10;

string to[N];
bool used[N];
int fstQ[N][10];
Item digit[10];
Item locDigit[10];
Item dpDigit[N];
int x[N];
int q;

ll myPow(ll a, ll k)
{
    if (k == 0)
        return 1;
    if (k & 1)
        return mult(a, myPow(a, k - 1));
    else
    {
        ll t = myPow(a, k / 2);
        return mult(t, t);
    }
}

Item getDigit(int numQ)
{
    if (used[numQ])
        return dpDigit[numQ];
    used[numQ] = 1;
    for (int i = 0; i < 10; i++)
    {
        int id = fstQ[numQ + 1][i];
    //  cout << "NUMBER:" << i << endl;
    //  cout << numQ << ":" << id << "!" << endl;
        if (id == q)
            locDigit[i] = Item(i, 1); 
        else
            locDigit[i] = getDigit(id);
    }
    int len = (int)to[numQ].length();
    ll p = 0;
    ll res = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        int d = to[numQ][i] - '0';
        res = add(res, mult(locDigit[d].val, myPow(10, p)));
        p = (p + locDigit[d].len) % (mod - 1);
    }
    dpDigit[numQ] = Item(res, p);
    return dpDigit[numQ];
}

int main()
{
    string str;
    cin >> str;
    scanf("%d", &q);
    char c;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &x[i]);
        cin >> c >> c;
        getline(cin, to[i]);
    }

    for (int i = 0; i < 10; i++)
        fstQ[q][i] = q;
    for (int i = q - 1; i >= 0; i--)
    {
        for (int s = 0; s < 10; s++)
            fstQ[i][s] = fstQ[i + 1][s];
        fstQ[i][x[i]] = i;
    }

    for (int i = 0; i < 10; i++)
    {
        int id = fstQ[0][i];
//      cout << i << ":" << id << endl;
        if (id == q)
            digit[i] = Item(i, 1);
        else
            digit[i] = getDigit(id);
    }
    int len = (int)str.length();
    ll res = 0;
    ll p = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        int d = str[i] - '0';
        res = add(res, mult(digit[d].val, myPow(10, p)));
        p = (p + digit[d].len) % (mod - 1);
    }
    cout << res;
    
    return 0;
}