// It's time to PLAY.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

const int N = 2e6 + 7;

int now = 0;
struct Node
{
    int child[2], cnt[2];
} Trie[N << 3];

void Update(int num, int val)
{
    int ptr = 0;
    for (int i = 30; i >= 0; --i)
    {
        int bit = (num >> i) & 1;
        if (!Trie[ptr].child[bit])
        {
            Trie[ptr].child[bit] = ++now;
        }
        Trie[ptr].cnt[bit] += val;
        ptr = Trie[ptr].child[bit];
    }
}

int Get(int num)
{
    int ptr = 0, res = 0;
    for (int i = 30; i >= 0; --i)
    {
        int bit = (num >> i) & 1;
        if (!bit)
        {
            if (Trie[ptr].cnt[1])
            {
                res ^= (1 << i);
                ptr = Trie[ptr].child[1];
            }
            else
            {
                ptr = Trie[ptr].child[0];
            }
        }
        else
        {
            if (Trie[ptr].cnt[0])
            {
                res ^= (1 << i);
                ptr = Trie[ptr].child[0];
            }
            else
            {
                ptr = Trie[ptr].child[1];
            }
        }
    }
    return res;
}

void PLAY()
{
    int q;
    cin >> q;
    Update(0, 1);
    while (q--)
    {
        char t;
        int num;
        cin >> t >> num;
        if (t == '+')
        {
            Update(num, 1);
        }
        else if (t == '-')
        {
            Update(num, -1);
        }
        else
        {
            cout << Get(num) << endl;
        }
    }
}

signed main()
{
    fastio;
#ifdef EXILE
    freopen("input.txt", "r", stdin);
#else

#endif
    time_t ts = clock();
    PLAY();
    time_t tf = clock();
    cerr << "\n\nTime elapsed: " << tf - ts << "ms";
    return 0;
}