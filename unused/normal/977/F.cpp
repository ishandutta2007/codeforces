#include <bits/stdc++.h>
using namespace std;

int bck[200005];
int len[200005];
map<int, int> idx;

int main()
{
    int n;
    scanf("%d",&n);

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d",&x);
        auto itr = idx.find(x - 1);
        if (itr == idx.end()) bck[i] = 0;
        else bck[i] = itr->second;
        idx[x] = i;
        len[i] = 1 + len[bck[i]];
        if (len[ans] < len[i]) ans = i;
    }

    printf("%d\n", len[ans]);

    vector<int> vt;
    while (ans)
    {
        vt.push_back(ans);
        ans = bck[ans];
    }

    for (int i = vt.size() - 1; i >= 0; i--) printf("%d ", vt[i]);
    printf("\n");
}