#include <iostream>
#include <cstdio>
using namespace std;

const int N = 200;

int q[N];
int a[N];
int z1[N];
int z2[N];
int p[N];
int n;

bool check1()
{
    for (int i = 0; i < n; i++)
        if (z1[i] != a[i])
            return false;
    return true;
}

bool check2()
{
    for (int i = 0; i < n; i++)
        if (z2[i] != a[i])
            return false;
    return true;
}

void first(int k)  
{
    for (int i = 0; i < n; i++)
        z1[i] = i;
    for (int i = 0; i < k; i++)
    {
        for (int s = 0; s < n; s++)
            p[s] = z1[q[s]];
        for (int s = 0; s < n; s++)
            z1[s] = p[s];
    }
}

void second(int k)
{
    for (int i = 0; i < n; i++)
        z2[i] = i;
    for (int i = 0; i < k; i++)
    {
        for (int s = 0; s < n; s++)
            p[q[s]] = z2[s];
        for (int s = 0; s < n; s++)
            z2[s] = p[s];
    }
}

bool checkz()
{
    for (int i = 0; i < n; i++)
        if (z1[i] != z2[i])
            return false;
    return true;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int k;
    scanf("%d%d", &n, &k);  

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
        q[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i]--;
    }

    bool h = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != i)
            h = true;
    }               
    if (!h)
    {
        puts("NO");
        return 0;
    }
   
    for (int i = 1; i <= k; i++)
    {
        if ((k - i) % 2 != 0)
            continue;
        first(i);   
        second(i);

        bool h = true;
        if (i == 1 && k != 1)
        {
            if (checkz())
                h = false;
        }

        if (check1())
        {
            puts((h ? "YES" : "NO"));
            return 0;
        }           
        if (check2())
        {
            puts((h ? "YES" : "NO"));
            return 0;
        }
    }

    puts("NO");
    return 0;
}