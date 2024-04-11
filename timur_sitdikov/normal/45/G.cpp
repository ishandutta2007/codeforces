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

const int maxn=18500000;
//char p[maxn+5];
int col[10000];

/*void erat()
{
    int i, j;
    p[0]=p[1]=1;
    for(i=2; i*i<=maxn; i++)
        if (!p[i])
            for(j=i*i; j<=maxn; j+=i)
                p[j]=1;
}*/

int p(int v)
{
    int i;
    for(i=2; i*i<=v; i++)
        if (!(v%i))
            return 1;
    return 0;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, v, sum, d=0, t;
    //erat();
    cin >> n;
    for(t=0; t<=d; t++)
    {
        for(i=1; i<=n; i++)
            col[i]=0;
        v=n*(n+1)/2;
        if (!p(v))
        {
            for(i=1; i<=n; i++)
                printf("1 ");
            putchar('\n');
            continue;
        }
        if (v&1)
        {
            if (!p(v-2))
            {
                printf("1 2 ");
                for(i=3; i<=n; i++)
                    printf("1 ");
                putchar('\n');
                continue;
            }
            col[3]=3;
            v-=3;
        }
        for(i=3; ;i+=2)
            if (!p(i) && !p(v-i))
            {
                sum=0;
                for(j=n; sum+j<i; j--)
                {
                    col[j]=1;
                    sum+=j;
                }
                if (i-sum==3)
                {
                    col[1]=col[2]=1;
                }
                else col[i-sum]=1;
                break;
            }
        for(i=1; i<=n; i++)
            if (!col[i])
                col[i]=2;
        for(i=1; i<=n; i++)
            printf("%d ", col[i]);
        putchar('\n');
    }
    

}