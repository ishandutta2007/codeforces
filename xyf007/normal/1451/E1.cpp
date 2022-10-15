#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
int n, a[100001], tmp1, tmp2, tmp3, tmp4, tmp5;
int gb(int x, int i)
{
    return (x >> i) & 1;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    cout << "XOR 1 2" << endl;
    cin >> tmp1;
    cout << "XOR 2 3" << endl;
    cin >> tmp2;
    cout << "AND 1 2" << endl;
    cin >> tmp3;
    cout << "AND 1 3" << endl;
    cin >> tmp4;
    cout << "AND 2 3" << endl;
    cin >> tmp5;
    for (int i = 0; i < 16; i++)
    {
        for (int A = 0; A <= 1; A++)
        {
            for (int B = 0; B <= 1; B++)
            {
                for (int C = 0; C <= 1; C++)
                {
                    if ((A ^ B) == gb(tmp1, i) && (B ^ C) == gb(tmp2, i) && (B & A) == gb(tmp3, i) && (C & A) == gb(tmp4, i) && (B & C) == gb(tmp5, i))
                    {
                        a[1] |= A << i;
                        a[2] |= B << i;
                        a[3] |= C << i;
                        break;
                    }
                }
            }
        }
    }
    int x;
    for (int i = 4; i <= n; i++)
    {
        cout << "XOR 1 " << i << endl;
        cin >> x;
        a[i] = x ^ a[1];
    }
    cout << "! ";
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}