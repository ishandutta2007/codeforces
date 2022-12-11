#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = (int)3e4;
char a[N], b[N];
char zStr[N];
int z[N];
int ind = 0;

void calcZ()
{
    int l = 0, r = 0;
    z[0] = 0;
    for (int i = 1; i < ind; i++)
    {
        z[i] = 0;
        if (i < r)
            z[i] = min(z[i - l], r - i + 1);
        while (zStr[i + z[i]] == zStr[z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            l = i;
        }
    }
    
}

int main()
{
//  freopen ("input.txt", "r", stdin);
//  freopen ("output.txt", "w", stdout); 
    
    int ans = (int)1e9;
    scanf("%s\n%s", a, b);
    int n = strlen(a), m = strlen(b);

    for (int i = 0; i < n; i++)
    {
        ind = 0;
        for (int s = i; s < n; s++)
            zStr[ind++] = a[s];
        zStr[ind++] = '#';
        int f1 = ind;
        for (int s = 0; s < n; s++)
            zStr[ind++] = a[s];
        int s1 = ind;
        zStr[ind++] = '#';
        int f2 = ind;
        for (int s = 0; s < m; s++)
            zStr[ind++] = b[s];
        int s2 = ind;
        zStr[ind++] = 0;
        calcZ();
        int fstM1 = -1, scndM1 = -1;
        for (int s = f1; s < s1; s++)
        {
            if (z[s] > fstM1)
            {
                scndM1 = fstM1;
                fstM1 = z[s];
            }
            else if (z[s] > scndM1)
                scndM1 = z[s];
        }

        int fstM2 = -1, scndM2 = -1;
        for (int s = f2; s < s2; s++)
        {
            if (z[s] > fstM2)
            {
                scndM2 = fstM2;
                fstM2 = z[s];
            }
            else if (z[s] > scndM2)
                scndM2 = z[s];
        }

        scndM2++;
        scndM1++;

        if (fstM1 < scndM1 || fstM2 < scndM2)
            continue;
//      cout << i << endl;
//      cout << fstM1 << ":" << scndM1 << endl;
//      cout << fstM2 << ":" << scndM2 << endl;
             
        for (int len = 1; len <= n; len++)
        {
            if (len >= scndM1 && len <= fstM1 && len >= scndM2 && len <= fstM2)
            {
                ans = min(ans, len);
                break;
            }
        }

    }
    if (ans == (int)1e9)
        cout << -1;
    else
        cout << ans;

    return 0;
}