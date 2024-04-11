#include <bits/stdc++.h>
using namespace std;

int query_num;

struct trie
{
  int here = 0;
  int query_num = 0;
  trie *nxt[5] {};
};

trie head;

void insert_trie(trie &now, const char *p)
{
  if (*p == 0) { now.here++; return; }

  int idx = *p - 'a';
  if (now.nxt[idx] == nullptr) now.nxt[idx] = new trie;
  insert_trie(*now.nxt[idx], p + 1);
}

int main()
{
  int n, m;
  scanf("%d%d",&n,&m);
  for (int i = 0; i < n; i++)
  {
    char str[111];
    scanf("%s", str);

    insert_trie(head, str);
  }

  for (int i = 1; i <= m; i++)
  {
    char str[111];
    scanf("%s", str);

    queue<pair<trie *, int>> que;
    que.emplace(&head, 0);

    int ans = 0;

    while (que.empty() == false)
    {
      trie *now; int idx;
      tie(now, idx) = que.front();
      que.pop();

      if (str[idx] == 0)
      {
        if (now->here && now->query_num != i)
        {
          now->query_num = i;
          ans += now->here;
        }
        continue;
      }

      if (str[idx] == '?')
      {
        que.emplace(now, idx + 1);

        for (int j = 0; j < 5; j++)
        {
          if (now->nxt[j]) que.emplace(now->nxt[j], idx + 1);
        }
      }
      else
      {
        if (now->nxt[str[idx] - 'a']) que.emplace(now->nxt[str[idx] - 'a'], idx + 1);
      }
    }

    printf("%d\n", ans);
  }
}