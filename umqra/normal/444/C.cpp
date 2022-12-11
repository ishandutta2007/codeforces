#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 100;
const int SZ = 450;
const int CNT = N / SZ + 10;

int stBlock[CNT];
vector <int> rules[CNT];
int numBlock[N];
int color[N];
ll bright[N];
ll sumBright[CNT];
int n;
int ind = 0;

void init()
{
    for (int i = 0; i < n; i += SZ)
    {
        stBlock[ind++] = i;
        for (int s = i; s < min(n, i + SZ); s++)
        {
            numBlock[s] = ind - 1;
            color[s] = s + 1;
        }
    }
}

void applyRules(int numB)
{
    int l = stBlock[numB];
    int r = min(n - 1, l + SZ - 1);
    if (rules[numB].size() == 0)
        return;
    int fstC = rules[numB][0];
    for (int i = l; i <= r; i++)
        bright[i] += abs(color[i] - fstC);
    ll allAdd = 0;
    for (int i = 1; i < (int)rules[numB].size(); i++)
        allAdd += abs(rules[numB][i] - rules[numB][i - 1]);
    int lstColor = rules[numB][rules[numB].size() - 1];
    sumBright[numB] = 0;
    for (int i = l; i <= r; i++)
    {
        bright[i] += allAdd;
        sumBright[numB] += bright[i];
        color[i] = lstColor;
    }
    rules[numB].clear();
}

void simplePaint(int numB, int l, int r, int x)
{
//  cout << l << ":" << r << "  " << x << endl;
    for (int i = l; i <= r; i++)
    {
        bright[i] += abs(x - color[i]);
        sumBright[numB] += abs(x - color[i]);
        color[i] = x;
    }
}

void paint(int l, int r, int x)
{
    int a = numBlock[l];
    int b = numBlock[r];
//  cerr << a << ":" << b << endl;
    applyRules(a);
//  cerr << "A" << endl;
    applyRules(b);
//  cerr << "B" << endl;
    simplePaint(a, l, min(stBlock[a] + SZ - 1, r), x);
//  cerr << a << ":" << b << endl;
    if (a != b)
        simplePaint(b, stBlock[b], r, x);
    for (int i = a + 1; i < b; i++)
    {
        if (rules[i].size() == 0)
        {
            simplePaint(i, stBlock[i], min(stBlock[i] + SZ - 1, n - 1), x);
            rules[i].push_back(x);
        }
        else
        {
            int old = rules[i][rules[i].size() - 1];
            int st = stBlock[i];
            int en = min(stBlock[i] + SZ, n);
            sumBright[i] += (ll)(en - st) * (ll)abs(old - x);
            rules[i].push_back(x);
        }
    }
}

ll simpleCalc(int ind, int l, int r)
{
    ll res = 0;
    for (int i = l; i <= r; i++)
        res += bright[i];
    return res;
}

ll calcInt(int l, int r)
{
    int a = numBlock[l];
    int b = numBlock[r];
    applyRules(a);
    applyRules(b);
    ll res = simpleCalc(a, l, min(stBlock[a] + SZ - 1, r));
    if (a != b)
        res += simpleCalc(b, stBlock[b], r);
    for (int i = a + 1; i < b; i++)
        res += sumBright[i];
    return res;
}

int main()
{
    int m;
    scanf("%d%d", &n, &m);
    init();
    for (int i = 0; i < m; i++)
    {
        int type;
        scanf("%d", &type);
//      cerr << i << endl;
        if (type == 1)
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            l--, r--;
            paint(l, r, x);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l--, r--;
            printf("%I64d\n", calcInt(l, r));
        }
    }
    return 0;
}