#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
int n, Xor[100001], lst[100001], a[100001];
int ask(std::__cxx11::string s, int x, int y)
{
    cout << s << ' ' << x << ' ' << y << endl;
    int ans;
    cin >> ans;
    return ans;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        Xor[i] = ask("XOR", 1, i);
    }
    bool f = false;
    int pos = -1;
    for (int i = 2; i <= n; i++)
    {
        if (lst[Xor[i]])
        {
            pos = i;
            f = true;
            break;
        }
        lst[Xor[i]] = i;
    }
    if (f)
    {
        a[pos] = ask("AND", lst[Xor[pos]], pos);
        a[1] = a[pos] ^ Xor[pos];
    }
    else
    {
        int b = -1, c = -1;
        for (int i = 3; i <= n; i++)
        {
            if ((Xor[2] ^ Xor[i]) == n - 1)
            {
                b = 2;
                c = i;
                break;
            }
        }
        if (b == -1)
        {
            for (int i = 4; i <= n; i++)
            {
                if ((Xor[3] ^ Xor[i]) == n - 1)
                {
                    b = 3;
                    c = i;
                    break;
                }
            }
        }
        int xorab = Xor[b], xorac = Xor[c], xorbc = Xor[b] ^ Xor[c], andab = ask("AND", 1, b), andac = ask("AND", 1, c), andbc = 0;
        a[1] = (xorab + 2 * andab + xorac + 2 * andac - xorbc - 2 * andbc) >> 1;
    }
    cout << "! " << a[1] << ' ';
    for (int i = 2; i <= n; i++)
    {
        cout << (a[1] ^ Xor[i]) << ' ';
    }
    cout.flush();
    return 0;
}