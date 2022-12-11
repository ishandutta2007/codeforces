#include <cstdio>
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
using namespace std;
using namespace chrono;

#ifdef ONLINE_JUDGE
int get_tc() { int n; scanf("%d",&n); return n; }
int get_length() { int n; scanf("%d",&n); return n; }
int get_q(int i) { printf("? %d\n", i); fflush(stdout); int x; scanf("%d",&x); return x; }
void answer(vector<int> vt) { printf("!"); for (int t : vt) printf(" %d", t); printf("\n"); fflush(stdout); }
#else
vector<vector<int>> tc = {
    {4,2,1,3},
    {1,3,4,2},
};
vector<int> q;
int tp = -1;
int get_tc() { return tc.size(); }
int get_length()
{
    ++tp;
    q.clear();
    for (int i = 0; i < tc[tp].size(); i++) q.push_back(i + 1);
    return tc[tp].size();
}
int get_q(int i)
{
    int ret = q[i - 1];
    vector<int> nq(q.size());
    for (int j = 0; j < q.size(); j++)
    {
        nq[j] = q[tc[tp][j] - 1];
    }
    q = nq;
    return ret;
}
void answer(vector<int> vt)
{
    if (tc[tp] == vt)
    {
        printf("CORRECT\n");
    }
    else
    {
        printf("WRONG\n");
    }
}
#endif

int main()
{
    int T = get_tc();
    while (T--)
    {
        int n = get_length();
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            if (ans[i]) continue;

            vector<int> vt{ get_q(i + 1) };
            for (;;)
            {
                vt.push_back(get_q(i + 1));
                if (vt.back() == vt[0]) break;
            }

            for (int j = 1; j < vt.size(); j++)
            {
                ans[vt[j - 1] - 1] = vt[j];
            }
        }

        answer(ans);
    }
}