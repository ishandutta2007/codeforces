#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000;
int per[N], rper[N];
int h;
int n;
int a[N];
vector<int> ans[N];
bool used[N];
int q[N];
int topQ;

vector<int> query(int v)
{

    printf("? %d\n", v);
    fflush(stdout);
    vector<int> res;
    
    int k;
    scanf("%d", &k);
    if (k == 0) throw;
    while(k--)
    {
        int u;
        scanf("%d", &u);
        res.push_back(u);
    }
   
/*
    int pos = rper[v];
    if (pos != 1)
        res.push_back(per[pos / 2]);
    if (pos < (1 << (h - 1)))
    {
        res.push_back(per[2 * pos]);
        res.push_back(per[2 * pos + 1]);
    }
    random_shuffle(res.begin(), res.end());
  */  
    return res;
}

void answer(int v)
{
    printf("! %d\n", v);
    fflush(stdout);
  //  if (v != per[1]) throw;
    return;
}

void BFS(int v)
{
    topQ = 0;
    q[topQ++] = v;
    for (int k = 0; k < topQ; k++)
    {
        v = q[k];
        if (n == 16)
        {
    //        cout << "here" << endl;
    //        throw;
            answer(v);
            return;
        }
        a[n] = v;
        used[v] = 1;
        ans[n] = query(v);
        if ((int)ans[n].size() == 2)
        {
            answer(v);
            return;
        }
        for (int u : ans[n])
            if (!used[u])
                q[topQ++] = u;
        n++;
    }
    return;
}

void solve()
{
    scanf("%d", &h);
    if (h == 0) throw;
    for (int i = 0; i <= (1 << h); i++)
        used[i] = 0;
    for (int i = 0; i < 20; i++)
        ans[i].clear();
    n = 0;
    used[1] = 1;
    a[0] = 1;
    ans[0] = query(1);
    n = 1;
    if ((int)ans[0].size() == 2)
    {
        answer(1);
        return;
    }
    int v = 1;
    while(true)
    {
        int it = 0;
        int pos = 0;
        while(a[pos] != v) pos++;
        while(it < (int)ans[pos].size() && used[ans[pos][it]]) it++;
        if (it == (int)ans[pos].size()) break;
        int u = ans[pos][it];
        a[n] = u;
        ans[n] = query(u);
        if ((int)ans[n].size() == 2)
        {
            answer(u);
            return;
        }
        n++;
        used[u] = 1;
        v = u;
    }
    int oldN = n;
    v = 1;
    if ((int)ans[0].size() != 1)
    {
        while(true)
        {
            int it = 0;
            int pos = 0;
            while(a[pos] != v) pos++;
            while(it < (int)ans[pos].size() && used[ans[pos][it]]) it++;
            if (it == (int)ans[pos].size()) break;
            int u = ans[pos][it];
            a[n] = u;
            ans[n] = query(u);
            if ((int)ans[n].size() == 2)
            {
                answer(u);
                return;
            }
            n++;
            used[u] = 1;
            v = u;
        }
    }
    int curH = (n + 1) / 2;
    if (oldN >= curH)
        v = a[oldN - curH];
    else
        v = a[n - curH];
    while(h != 7 || curH < h - 3)
    {
        oldN = n;

        while(true)
        {
            int it = 0;
            int pos = 0;
            while (a[pos] != v) pos++;
            while(it < (int)ans[pos].size() && used[ans[pos][it]]) it++;
            if (it == (int)ans[pos].size()) break;
            int u = ans[pos][it];
            a[n] = u;
            ans[n] = query(u);
            if ((int)ans[n].size() == 2)
            {
                answer(u);
                return;
            }
            n++;
            used[u] = 1;
            v = u;
        }

        curH = (curH + n - oldN + 1) / 2;
        v = a[n - curH];
    }
    int pos = 0;
    while(a[pos] != v) pos++;
    int it = 0;
    while(it < (int)ans[pos].size() && used[ans[pos][it]]) it++;
    if (it == (int)ans[pos].size()) throw;
    v = ans[pos][it];
    BFS(v);
    return;
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int t;

    scanf("%d", &t);

    /*
    t = 500000;
    h = 7;
    for (int i = 1; i < (1 << h); i++)
        per[i] = i;
*/
    while(t--)
    {
  /*      
        random_shuffle(per + 1, per + (1 << h));
        for (int i = 1; i < (1 << h); i++)
            rper[per[i]] = i;
    */        
        solve();
    }

    return 0;
}