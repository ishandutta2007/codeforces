#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

int a[1000];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }                   

    int pos = 0;
    while (sum > 0)
    {
        int e = (pos == 0 ? n - 1 : 0);
        while (1)
        {
            if (pos == e)
                break;                     
            if (a[pos] > 0)
            {
                sum--;            
                putchar('P');
                a[pos]--;
            }
            if (e - pos > 0)
            {
                putchar('R');
                pos++;
            }
            else
            {
                putchar('L');
                pos--;
            }    
         }              
    }
                                
    return 0;
}