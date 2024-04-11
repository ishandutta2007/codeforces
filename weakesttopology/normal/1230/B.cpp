#include "bits/stdc++.h"

using namespace std;

int main(int argc, char *argv[])
{
    int n, k; cin >> n >> k;

    string digit;

    char c; cin >> c;

    if (n == 1)
    {
        if (k >= 1)
        {
            cout << "0\n";
        }
        else
            cout << c << endl;
        return 0;
    }

    if (c != '1' && k > 0)
    {
        k -= 1;
        digit.push_back('1');
    }
    else
    {
        digit.push_back(c);
    }


    for (int i = 1; i < n; ++i)
    {
        char c; cin >> c;

        if (c != '0' && k > 0)
        {
            digit.push_back('0');
            k--;
        }
        else
            digit.push_back(c);
    }

    cout << digit << endl;

    return 0;
}