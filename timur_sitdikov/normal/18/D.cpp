#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

const int d=2010;
char m[5005][d], ans[d], cur[2][d];
int col[d], n, v[5001], v1[d];

void add(char *c1, char *c2, char *c)
{
    int i; char t=0;
    for(i=0; i<d; i++)
    {
        c[i]=c1[i]+c2[i]+t;
        if (c[i]>=10) {c[i]-=10; t=1;}
        else t=0;
    }
}

void cpy(char *c1, char *c2)
{for(int i=0; i<d; i++) c1[i]=c2[i];}

void calc()
{
    cur[0][0]=1;
    for(int i=0; i<d; i++)
    {
        if (m[n][i])
            add(ans, cur[0], ans);
        cpy(cur[1], cur[0]);
        add(cur[0], cur[1], cur[0]);
    }
}

int cmp1(char *c1, char *c2)
{
    for(int i=d-1; i>=0; i--) 
        if (c1[i]<c2[i]) return -1;
        else if (c1[i]>c2[i]) return 1;
    return 0;
}



int main()
{   
 
    int i, j, a;
    char s[10];
    scanf("%d", &n);
    for(i=0; i<n; i++) col[i]=0;
    for(i=1; i<=n; i++)
    {
        scanf("%s %d", &s, &a);
        if (s[0]=='s' && col[a]) 
        {
            m[col[a]-1][a]=1;
            if (cmp1(m[i-1], m[col[a]-1])==-1)
            {
                cpy(m[i],m[col[a]-1]);
                m[col[a]-1][a]=0;
                v1[a]=i;
                for(j=col[a]+1; j<i; j++) 
                    if (v[j] && v1[v[j]]>=col[a]+1) 
                    {m[i][v[j]]=0; v1[v[j]]=0;}
                for(j=0; j<=a; j++) 
                    col[j]=0;
            }
            else 
            {
                cpy(m[i],m[i-1]);
                m[col[a]-1][a]=0;
            }
        }
        else
        {
            if (s[0]=='w') {col[a]=i; v[i]=a;}
            cpy(m[i],m[i-1]);
        }
    }
    calc();
    for(i=d-1; i>=0 && !ans[i]; i--);
    if (i==-1) {printf("0\n"); return 0;}
    for(; i>=0; i--) putchar(ans[i]+'0');
    putchar('\n');
}