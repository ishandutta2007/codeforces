#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

#define left asduasfkjask
#define right aasjfaksbnuuu

typedef long long ll;
const int mod = (int)1e9 + 7;

const int N = (int)4e5;
char sSt[3][N];
char str[N];
int val[N];
int ind = 0;

int arr[N], nArr[N];
int color[N];
int nC[N];
int pos[N];
int cnt[N];
int lcp[N];
int revP[N];
int cntBit[3][N];
int st[N];
int topSt;
int left[N], right[N];
int ans[N];
vector <int> listPos[N];
int minLen = 0;

int add(int a, int b)
{
    a += b;
    if (a < 0)
        return a + mod;
    if (a < mod)
        return a;
    return a - mod;
}

int mult(int a, int b)
{
    ll c = (ll)a * b;
    return c % mod;
}

void createStr()
{
    minLen = N;
    for (int i = 0; i < 3; i++)
    {
        int l = strlen(sSt[i]);
        minLen = min(minLen, l);
        for (int s = 0; s < l; s++)
        {
            str[ind++] = sSt[i][s];
            val[ind - 1] = i;
        }
        str[ind++] = 'a' - i - 1;
        val[ind - 1] = -1;
    }
    str[ind] = 0;
}

void build()
{
    for (int i = 0; i < ind; i++)
    {
        color[i] = str[i];
        cnt[color[i]]++;
    }
    pos[0] = 0;
    for (int i = 1; i < N; i++)
        pos[i] = pos[i - 1] + cnt[i - 1];
    for (int i = 0; i < ind; i++)
        arr[pos[color[i]]++] = i;
    int sh = 1;
    while (sh <= ind)
    {
        fill(cnt, cnt + N, 0);
        for (int i = 0; i < ind; i++)
            cnt[color[i]]++;
        pos[0] = 0;
        for (int i = 1; i < N; i++)
            pos[i] = pos[i - 1] + cnt[i - 1];
        for (int i = 0; i < ind; i++)
        {
            int x = arr[i] - sh;
            if (x < 0)
                x += ind;
            nArr[pos[color[x]]++] = x;
        }
        nC[nArr[0]] = 0;
        for (int i = 1; i < ind; i++)
        {
            if (color[nArr[i - 1]] == color[nArr[i]] && color[(nArr[i - 1] + sh) % ind] == color[(nArr[i] + sh) % ind])
                nC[nArr[i]] = nC[nArr[i - 1]];
            else
                nC[nArr[i]] = nC[nArr[i - 1]] + 1;
        }
        for (int i = 0; i < ind; i++)
        {
            arr[i] = nArr[i];
            color[i] = nC[i];
        }
        sh *= 2;
    }
}

void calcLcp()
{
    for (int i = 0; i < ind; i++)
        revP[arr[i]] = i;
    int v = 0;
    for (int i = 0; i < ind; i++)
    {
        int x = revP[i];
        if (x == ind - 1)
        {
            lcp[x] = 0;
            v = 0;
            continue;
        }
        while (1)
        {
            if (str[arr[x] + v] != str[arr[x + 1] + v])
                break;
            v++;
        }
        lcp[x] = v;
        v = max(v - 1, 0);
    }
}

int getCnt(int t, int l, int r)
{
    return cntBit[t][r] - (l == 0 ? 0 : cntBit[t][l - 1]);
}

int main()
{
    for (int i = 0; i < 3; i++)
        scanf("%s", sSt[i]);
    createStr();
    build();
    calcLcp();
//  for (int i = 0; i < ind; i++)
//  {
//      for (int s = arr[i]; s < ind; s++)
//          putchar(str[s]);
//      cout << " " << lcp[i];
//      puts("");
//  }
    
    for (int i = 0; i < ind; i++)
    {
        if (val[arr[i]] != -1)
            cntBit[val[arr[i]]][i] = 1;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int s = 1; s < ind; s++)
            cntBit[i][s] += cntBit[i][s - 1];
    }
    
    
    topSt = 0;
    for (int i = 0; i < ind; i++)
    {
        while (topSt > 0 && lcp[st[topSt - 1]] >= lcp[i])
            topSt--;
        left[i] = (topSt == 0 ? 0 : st[topSt - 1] + 1);
        st[topSt++] = i;
    }
    
    topSt = 0;
    for (int i = ind - 1; i >= 0; i--)
    {
        while (topSt > 0 && lcp[st[topSt - 1]] >= lcp[i])
            topSt--;
        right[i] = (topSt == 0 ? ind - 1 : st[topSt - 1]);
        st[topSt++] = i;
    }
    
    for (int i = 0; i < ind - 1; i++)
    {
        listPos[lcp[i]].push_back(i);
    }
    int lst = 1;
    for (int i = 1; i <= minLen; i++)
    {
        if (listPos[i].size() == 0)
            continue;
        int l = -1, r = -1;
        int val = 0;
        for (int s = 0; s < (int)listPos[i].size(); s++)
        {
            int p = listPos[i][s];
            if (p > r)
            {
                l = left[p];
                r = right[p];
                int curC = 1;
                for (int q = 0; q < 3; q++)
                    curC = mult(curC, getCnt(q, l, r));
//              val = add(val, curC);
                int bMin = max((l == 0 ? 0 : lcp[l - 1]), lcp[r]);
                ans[i] = add(ans[i], curC);
                ans[bMin] = add(ans[bMin], -curC);
            }
        }
//      for (int s = lst; s <= i; s++)
//          ans[s] = val;
//      lst = i + 1;
    }
    for (int i = minLen; i >= 0; i--)
        ans[i] = add(ans[i], ans[i + 1]);
    for (int i = 1; i <= minLen; i++)
        printf("%d ", ans[i]);
    
    return 0;
}