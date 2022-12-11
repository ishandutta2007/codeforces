#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>
#include <random>
#include <limits>
#include <chrono>
#include <ctime>
#include <bitset>
#include <list>
#include <stack>
using namespace std;

string str[100005];

int main()
{
    int T;
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> str[i];

        bool yes = false;
        // case1: two == two or three == three
        unordered_set<string> st{str, str + n};
        for (int i = 0; i < n; i++)
        {
            auto str2 = str[i];
            reverse(str2.begin(), str2.end());
            if (st.count(str2))
            {
                yes = true;
                break;
            }
        }
        if (yes)
        {
            cout << "YES\n";
            continue;
        }

        st.clear();
        // case2: two, three
        for (int i = 0; i < n; i++)
        {
            if (str[i].size() == 2) st.insert(str[i]);
            else
            {
                string str2 = str[i].substr(1);
                reverse(str2.begin(), str2.end());
                if (st.count(str2))
                {
                    yes = true;
                    break;
                }
            }
        }
        if (yes)
        {
            cout << "YES\n";
            continue;
        }

        // case3: three, two
        st.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            string str2 = str[i];
            reverse(str2.begin(), str2.end());
            if (str2.size() == 2) st.insert(str2);
            else
            {
                string str3 = str2.substr(1);
                reverse(str3.begin(), str3.end());
                if (st.count(str3))
                {
                    yes = true;
                    break;
                }
            }
        }

        if (yes)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}