#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = 10000;
int a[N];
int t[N];
int listI[N];
int ind;

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    int cntA = 0, cntB = 0;
    for (int i = 0; i < 2 * n; i++)
        scanf("%d", &a[i]);
                    
    for (int i = 10; i < 100; i++)
    {
        int cnt = 0;
        for (int s = 0; s < 2 * n; s++)
        {
            if (a[s] == i)
                cnt++;
        }
        if (cnt > 1)
        {
            cnt = 2;
            for (int s = 0; s < 2 * n; s++)
            {         
                if (a[s] == i)
                {   
                    if (cnt == 1)
                        t[s] = 1;
                    else if (cnt == 2)
                        t[s] = 2;
                    cnt--;
                }
            }
        }
        else if (cnt == 1)
            listI[ind++] = i;
    }
                         
    for (int i = 0; i < ind; i++)
    {
        int cur = (i % 2 == 0 ? 1 : 2);
        for (int s = 0; s < 2 * n; s++)
        {
            if (a[s] == listI[i])
            {
                t[s] = cur;
            }
        }
    }          

    for (int i = 0; i < 2 * n; i++)
    {                           
        if (t[i] == 1)
            cntA++;
        else if (t[i] == 2)
            cntB++;
    }             

    
    for (int s = 0; s < 2 * n; s++)
    {
        if (t[s] == 0)
        {
            if (cntA < cntB)
            {
                t[s] = 1;
                cntA++;
            }
            else
            {
                t[s] = 2;
                cntB++;
            }
        }
    }

    int tA = 0, tB = 0;
    for (int i = 10; i < 100; i++)
    {
        bool hA = false, hB = false;
        for (int s = 0; s < 2 * n; s++)
        {
            if (t[s] == 1 && a[s] == i)
                hA = true;
            if (t[s] == 2 && a[s] == i)
                hB = true;
        }
        if (hA)
            tA++;
        if (hB)
            tB++;
    }
    
    cout << tA * tB << endl;
    for (int i = 0; i < 2 * n; i++)
        cout << t[i] << ' ';

    return 0;
}