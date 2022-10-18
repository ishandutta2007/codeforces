#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 2000;

struct interval
{
    int l, r, id;
    
    friend inline bool operator<(const interval &lhs, const interval &rhs)
    {
        return lhs.r < rhs.r;
    }
};

int n;
interval a[MaxN];

int sol[MaxN];

inline bool check(int d)
{
    static int deadline[MaxN];
    static bool book[MaxN];
    for (int k = 0; k < n; k++)
        deadline[k] = n - 1, book[k] = false;
    for (int i = 0; i < n; i++)
    {
        static int cnt[MaxN];
        fill(cnt, cnt + n, 0);
        for (int k = 0; k < n; k++)
            if (!book[k])
                cnt[deadline[k]]++;
        if (cnt[i] > 1)
            return false;
        int r = n - 1;
        for (int k = i, s = 0; k < n; k++)
        {
            s += cnt[k];
            if (s == k - i + 1)
            {
                r = k;
                break;
            }
        }
        sol[i] = -1;
        for (int k = 0; k < n; k++)
            if (!book[k] && deadline[k] <= r)
            {
                sol[i] = k;
                break;
            }
        book[sol[i]] = true;
        for (int k = 0; k < n; k++)
            if (!book[k] && a[k].l <= a[sol[i]].r && i + d < deadline[k])
            {
                if (d == 0)
                    return false;
                deadline[k] = i + d;
            }
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    
    sort(a, a + n);
    
    int le = 0, ri = n;
    while (le != ri)
    {
        int mid = (le + ri) >> 1;
        if (!check(mid))
            le = mid + 1;
        else
            ri = mid;
    }
    check(le);
    
	for (int i = 0; i < n; i++)
		cout << a[sol[i]].id + 1 << " ";
	cout << endl;
    
    return 0;
}