#include <bits/stdc++.h>
using namespace std;

int dat[200005];
long long ans;

struct trie
{
	trie* l, *r;
};

trie buf[6000005];
int tp;

trie* newtrie()
{
    buf[tp].l = buf[tp].r = nullptr;
    return &buf[tp++];
}

void recur(int l, int r)
{
  if (l >= r) return;

  int bit = 31 - __builtin_clz(dat[l] ^ dat[r]);

  int mid = l + 1;
  while ((dat[mid] & (1 << bit)) == 0)
    ++mid;

  // [l, mid - 1], [mid, r]
  trie head{};
  tp = 0;

  for (int i = l; i < mid; i++)
  {
    trie* now = &head;
    for (int j = bit - 1; j >= 0; j--)
    {
      if (dat[i] & (1 << j))
      {
        if (!now->r) now->r = newtrie();
        now = now->r;
      }
      else
      {
        if (!now->l) now->l = newtrie();
        now = now->l;
      }
    }
  }

  int mincost = INT_MAX;

  for (int i = mid; i <= r; i++)
  {
    int cost = 1 << bit;
    trie* now = &head;
    for (int j = bit - 1; j >= 0; j--)
    {
      if (dat[i] & (1 << j))
      {
        if (now->r) now = now->r;
        else
        {
          cost += 1 << j;
          now = now->l;
        }
      }
      else
      {
        if (now->l) now = now->l;
        else
        {
          cost += 1 << j;
          now = now->r;
        }
      }
    }

    mincost = min(mincost, cost);
  }

  ans += mincost;
  recur(l, mid - 1);
  recur(mid, r);
}

int main()
{
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d",&dat[i]);
  }

  sort(dat, dat + n);
  n = unique(dat, dat + n) - dat;
  recur(0, n - 1);
  printf("%lld\n", ans);
}