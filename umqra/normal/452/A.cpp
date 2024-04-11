#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
using namespace std;

const int INF = (int)1e9;
typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const string p[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};


int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    for (int i = 0; i < 8; i++)
    {
        string q = p[i];
        if (q.length() == str.length())
        {
            bool ok = true;
            for (int s = 0; s < (int)str.length(); s++)
            {
                if (str[s] != '.' && str[s] != q[s])
                    ok = false;
            }
            if (ok)
                cout << q;
        }
    }
    return 0;
}