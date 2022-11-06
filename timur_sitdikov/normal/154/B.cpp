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
using namespace std;

char c[100005], col[100005];
int p[50000], ind[100005], top, del[100], topd, prv[100005], d=100005;

void fact(int v)
{
    topd=0;
    int i;
    for(i=2; i*i<=v; i++)
        if (!(v%i))
        {
            del[topd++]=i;
            while(!(v%i)) v/=i;
        }
    if (v>1) del[topd++]=v;
}

void erat()
{
    int i, j;
    for(i=2; i*i<=d; i++)
        if (!c[i])
            for(j=i*i; j<=d; j+=i)
                c[j]=1;
    for(i=2; i<=d; i++)
        if (!c[i])
            p[top++]=i;
    for(i=0; i<top; i++)
        ind[p[i]]=i;
}

int main()
{   
    int i, j, k, a, n, m, f, flag=0;
    char c[3];
    erat();
    scanf("%d %d", &n, &m);
    for(i=0; i<m; )
    {
        scanf("%s %d", &c, &a);
        fact(a);
        if (a==1)
        {
            if (c[0]=='+')
            {
                if (!flag) printf("Success\n");
                else printf("Already on\n");
                flag=1;
                goto ll;
            }
            else
            {
                if (flag) printf("Success\n");
                else printf("Already off\n");
                flag=0;
                goto ll;
            }
        }
        if (c[0]=='+')
        {
            f=0;
            for(j=0; j<topd; j++)
                if (!col[del[j]] || prv[del[j]]!=a)
                {
                    f=1; break;
                }
            if (!f) {printf("Already on\n"); goto ll;}
            for(j=0; j<topd; j++)
                if (col[del[j]])
                {
                    printf("Conflict with %d\n", prv[del[j]]);
                    goto ll;
                }
            printf("Success\n");
            for(j=0; j<topd; j++)
            {
                col[del[j]]=1;
                prv[del[j]]=a;
            }
        }
        else
        {
            f=0;
            for(j=0; j<topd; j++)
                if (!col[del[j]] || prv[del[j]]!=a)
                {
                    f=1; break;
                }
            if (f)
            {printf("Already off\n");goto ll;}
            printf("Success\n");
            for(j=0; j<topd; j++)
            {
                col[del[j]]=0;
                prv[del[j]]=0;
            }
        }
ll: i++;
    }
    
}