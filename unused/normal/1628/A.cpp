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

int a[200005];
int mex[200005];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }

        unordered_set<int> st;
        int last = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            st.insert(a[i]);
            while (st.count(last)) ++last;
            mex[i] = last;
        }

        vector<int> ans;
        int idx = 0;
        while (idx < n && mex[idx])
        {
            unordered_set<int> st2;
            int last2 = 0;
            int target = mex[idx];
            while (last2 < target)
            {
                st2.insert(a[idx++]);
                while (st2.count(last2)) ++last2;
            }

            ans.push_back(target);
        }
        while (idx < n)
        {
            ans.push_back(0);
            ++idx;
        }

        printf("%zd\n", ans.size());
        for (int t : ans) printf("%d ", t);
        printf("\n");
    }
}