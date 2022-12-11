#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define X first
#define Y second
#define mp make_pair

const int N = (int)2e5 + 100;

pii p[N];
bool used[N];
int permBrut[N];
pii myArr[N];
pii p2[N];
vector <int> start[N];
vector <int> end[N];
vector <int> fAns[N];

int wtf[N];

int sUsed[N];

int startNum[N];
pii ans[N];
int indAns = 0;

int findNum(pii a, int n)
{
    int l = -1, r = n;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (p[m] < a)
            l = m;
        else if (p[m] > a)
            r = m;
        else
            return m;
    }
    return -1;
}

bool check(int n)
{
    int ind = 0;
    for (int i = 0; i < n; i++)
    {                                                      
        int a = permBrut[i];
        int b = permBrut[(i + 1) % n];
        int c = permBrut[(i + 2) % n];
        myArr[ind++] = mp(min(a, b), max(a, b));
        myArr[ind++] = mp(min(a, c), max(a, c));
    }
    sort(myArr, myArr + ind);
    for (int i = 0; i < 2 * n; i++)
        if (myArr[i] != p[i])
            return false;
    return true;
}

bool brut(int n, int pos = 0)
{
    if (pos == n)
    {                    
        if (check(n))
        {               
            for (int i = 0; i < n; i++)
                printf("%d ", permBrut[i]);
            return true;
        }
        return false;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            permBrut[pos] = i;
            if (brut(n, pos + 1))
                return true;
            used[i] = 0;
        }
    }
    return false;
}

void fail()
{
    cout << -1;
    exit(0);
}

void solve(int ind, int n)
{                 
    pii t1, t2;
    int a = p[ind].X;
    int b = p[ind].Y;
    int cnt = 0;
    for (int i = 0; i < (int)start[a].size(); i++)
    {
        int c = start[a][i];         
        if (c < b)
        {
            for (int s = 0; s < (int)start[c].size(); s++)
            {
                if (start[c][s] == b)
                {
                    cnt++;
                    t1 = mp(a, c);
                    t2 = mp(c, b);                             
                }
            }
        }
        else
        {
            for (int s = 0; s < (int)start[b].size(); s++)
            {
                if (start[b][s] == c)
                {
                    cnt++;
                    t1 = mp(a, c);
                    t2 = mp(b, c);                             
                }
            }
        }
    }
    for (int i = 0; i < (int)end[a].size(); i++)
    {
        int c = end[a][i];
        for (int s = 0; s < (int)start[c].size(); s++)
        {
            if (start[c][s] == b)
            {
                cnt++;
                t1 = mp(c, a);
                t2 = mp(c, b);                                  
            }
        }
    }                   
    if (cnt == 1)         
    {
        int ind1 = findNum(t1, n);
        int ind2 = findNum(t2, n);     
        if (sUsed[ind1] == 2 || sUsed[ind2] == 2)
            return;
        sUsed[ind1]++; 
        sUsed[ind2]++;
        ans[indAns++] = t1;
        ans[indAns++] = t2;

        fAns[t1.X].push_back(t1.Y);
        fAns[t2.X].push_back(t2.Y);
        fAns[t1.Y].push_back(t1.X);
        fAns[t2.Y].push_back(t2.X);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
    {
        int a, b;    
        scanf("%d%d", &a, &b);

        wtf[a]++;
        wtf[b]++;
        p[i] = mp(min(a, b), max(a, b)); 
        start[p[i].X].push_back(p[i].Y);
        end[p[i].Y].push_back(p[i].X);
    }
                        

    for (int i = 1; i <= n; i++)
        if (wtf[i] != 4)
            fail();


    sort(p, p + 2 * n);                      

    if (n <= 9)
    {
        if (!brut(n))
            cout << -1;
        return 0;
    }

    fill(startNum, startNum + 2 * n, (int)1e6);

    for (int i = 0; i < 2 * n; i++)
        solve(i, 2 * n); 
                   
    if (indAns != 2 * n)
        fail();

    int a = ans[0].X;
    int b = ans[0].Y;
        
    vector<int> ac;

    ac.push_back(a); 

    while ((int)ac.size() <= n)
    {
        int k;
        for (int i = 0; i < (int)fAns[b].size(); i++)
        {
            int c = fAns[b][i];
            if (c != a)
            {
                k = c;
                break;
            }
        }
        ac.push_back(b);
        if (k == ans[0].X || k == ans[0].Y)
            break;
        a = b;
        b = k;
    }

    if (ac.size() != n)
        cout << -1;
    else
        for (int i = 0; i < n; i++)
            cout << ac[i] << ' ';

    return 0;
}