#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;

const int N = (int)1e5;
typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

struct Bugs 
{
    int complex, ind;
    Bugs () {}
    Bugs (int a, int b) : complex(a), ind(b) {}
};

struct Item
{
    int cool, cntS, ind;
    Item () {}
    Item (int a, int b, int c) : cool(a), cntS(b), ind(c) {}
    bool operator < (const Item &a) const
    {
        if (cntS != a.cntS)
            return cntS > a.cntS;

        return ind < a.ind;
    }
};

int p[N], cntS[N];
Bugs bug[N];
Item people[N];
int numStud[N];
int ans[N];
priority_queue <Item> setPeople;
               
bool cmpBug(const Bugs &a, const Bugs &b)
{
    if (a.complex != b.complex)
        return a.complex < b.complex;
    return a.ind < b.ind;
}

bool cmpPeople(const Item &a, const Item &b)
{
    if (a.cool != b.cool)
        return a.cool < b.cool;
    return a.ind < b.ind;
}

ll getSum(int A, int B, int t)
{                                     
    while (!setPeople.empty())
    {
        setPeople.pop();        
    }
    fill(numStud, numStud + B, -1);
    ll curS = 0;
    int curPt = A - 1;
    for (int i = B - 1; i >= 0; i -= t)
    {
        while (curPt >= 0 && people[curPt].cool >= bug[i].complex)
        {
            setPeople.push(people[curPt]);
            curPt--;
        }
        if (setPeople.empty())
            return (ll)1e15;
        Item curMin = setPeople.top();     
        numStud[i] = curMin.ind;
        curS += curMin.cntS;
        setPeople.pop();                    
    }
    return curS;
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int A, B, s;
    scanf("%d%d%d", &A, &B, &s);
    for (int i = 0; i < B; i++)
    {
        int val;
        scanf("%d", &val);
        bug[i] = Bugs(val, i);
    }
    for (int i = 0; i < A; i++)
        scanf("%d", &p[i]);

    for (int i = 0; i < A; i++)
        scanf("%d", &cntS[i]);

    for (int i = 0; i < A; i++)
        people[i] = Item(p[i], cntS[i], i);

    sort(bug, bug + B, cmpBug);
    sort(people, people + A, cmpPeople);    

    int l = 0, r = B + 1; 
    while (r - l > 1)
    {                                 
        int m = (l + r) / 2;
        if (getSum(A, B, m) <= (ll)s)
            r = m;
        else 
            l = m;
    }
    if (r == B + 1)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    getSum(A, B, r);
    int lst = -1;
    for (int i = B - 1; i >= 0; i--)
    {
        if (numStud[i] == -1)
            ans[bug[i].ind] = lst;
        else
        {
            lst = numStud[i];                   
            ans[bug[i].ind] = lst;
        }
    }

    for (int i = 0; i < B; i++)
        printf("%d ", ans[i] + 1);

    return 0;
}