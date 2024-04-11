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
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 200100;
int n, m;
int a[N];
bool inv;
bool used[N];
unordered_set<int> setik;

int add(int x, int y)
{
    x += y;
    if (x >= m) return x - m;
    return x;
}
int sub(int x, int y)
{
    x -= y;
    if (x < 0) return x + m;
    return x;
}
int mult(int x, int y)
{
    return ((ll)x * y) % m;
}
int bin_pow(int x, int p)
{
    if (p == 0) return 1;
    if (p == 2 || (p & 1)) return mult(x, bin_pow(x, p - 1));
    return bin_pow(bin_pow(x, p / 2), 2);
}
int rev(int x)
{
    return bin_pow(x, m - 2);
}

void printAns(int x, int d)
{
    if (inv)
    {
        x = add(x, mult(d, n));
    }
    printf("%d %d\n", x, d);
    exit(0);
}

void Fail()
{
    printf("-1\n");
    exit(0);
}

void solveOdd()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum = add(sum, a[i]);
    sum = mult(sum, rev(n));
    for (int i = 0; i < n; i++)
        a[i] = sub(a[i], sum);
    sort(a, a + n);
    if (a[0] != 0)
        Fail();
    for (int i = 1; i < (n + 1) / 2; i++)
    {
        if (add(a[i], a[n - i]) != 0)
            Fail();
    }
    for (int i = 0; i < n; i++)
        setik.insert(a[i]);
    for (int i = 1; i < (n + 1) / 2; i++)
    {
        int d = a[i];
        int x = 0;
        bool ok = true;
        for (int j = 0; ok && j < n / 2; j++)
        {
            x = add(x, d);
            ok &= setik.count(x) > 0;
        }
        if (ok)
        {
            x = sub(0, mult(d, n / 2));
            x = add(x, sum);
            printAns(x, d);
        }
    }
    Fail();
}

void solveEven()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum = add(sum, a[i]);
    sum = mult(sum, rev(n));
    for (int i = 0; i < n; i++)
        a[i] = sub(a[i], sum);
    sort(a, a + n);
    for (int i = 0; i < n / 2; i++)
    {
        if (add(a[i], a[n - 1 - i]) != 0)
            Fail();
    }
    for (int i = 0; i < n; i++)
        setik.insert(a[i]);
    for (int i = 0; i < n / 2; i++)
    {
        int d = add(a[i], a[i]);
        int x = sub(0, a[i]);
        bool ok = true;
        for (int j = 0; ok && j < n / 2; j++)
        {
            x = add(x, d);
            ok &= setik.count(x) > 0;
        }
        if (ok)
        {
            x = sub(a[i], mult(d, n / 2));
            x = add(x, sum);
            printAns(x, d);
        }
    }
    Fail();
}

int main()
{
    //freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if (n > m) throw;
    if (n == m)
    {
        printf("0 1\n");
        return 0;
    }
    if (n > m - n)
    {
        for (int i = 0; i < n; i++)
            used[a[i]] = 1;
        n = 0;
        for (int i = 0; i < m; i++)
            if (!used[i])
                a[n++] = i;
        inv = true;
    }
    if (n == 1)
        printAns(a[0], 1);
    if (n == 2)
        printAns(a[0], sub(a[1], a[0]));
    if (n & 1)
        solveOdd();
    else
        solveEven();

    return 0;
}