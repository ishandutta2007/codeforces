#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, cnt[8];
long long x;
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
void modify(int x)
{
    switch (x)
    {
    case 4:
        cnt[2] += 2;
        break;
    case 6:
        cnt[2]++;
        cnt[3]++;
        break;
    case 8:
        cnt[2] += 3;
        break;
    case 9:
        cnt[3] += 2;
        break;
    default:
        cnt[x]++;
        break;
    }
}
void del(int x, int y)
{
    switch (x)
    {
    case 7:
        cnt[7] -= y;
        cnt[5] -= y;
        cnt[3] -= 2 * y;
        cnt[2] -= 4 * y;
        break;
    case 5:
        cnt[5] -= y;
        cnt[3] -= y;
        cnt[2] -= 3 * y;
        break;
    case 3:
        cnt[3] -= y;
        cnt[2] -= y;
        break;
    default:
        cnt[2] -= y;
        break;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> x;
    while (x)
    {
        for (int i = x % 10; i >= 2; i--)
        {
            modify(i);
        }
        x /= 10;
    }
    for (int i = 1; i <= cnt[7]; i++)
    {
        cout << 7;
    }
    del(7, cnt[7]);
    for (int i = 1; i <= cnt[5]; i++)
    {
        cout << 5;
    }
    del(5, cnt[5]);
    for (int i = 1; i <= cnt[3]; i++)
    {
        cout << 3;
    }
    del(3, cnt[3]);
    for (int i = 1; i <= cnt[2]; i++)
    {
        cout << 2;
    }
    del(2, cnt[2]);
    return 0;
}