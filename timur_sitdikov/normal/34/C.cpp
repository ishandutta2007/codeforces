#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back

int m[1005], a, i, j, f;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    char c;
    while(1)
    {
        scanf("%d", &a);
        m[a]=1;
        c=getchar();
        if (c!=',')
            break;
    }
    f=0;
    for(i=j=0; i<=1000; )
    {
        j=i;
        if (!m[i])
        {
            i++;
            continue;
        }
        if (!m[i+1])
        {
            if (f)
                cout << ",";
            f=1;
            cout << i ;
            i++;
            continue;
        }
        while(m[i+1])
            i++;
        if (f)
            cout << ",";
        f=1;
        cout << j << "-" << i;
        i++;
    }
}