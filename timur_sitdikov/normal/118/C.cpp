#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int m[10], m1[10][10], ans[10], pos[10], stack[10][20000], top[10];
char  c1[10][20000];

int main()
{   
  
    char c[20000];
    int l, i, j, j1, j2, n, k, f, max=1000000000, maxi=-1, i1, i2, i0;
    scanf("%d %d %s", &n, &k, &c);
    l=strlen(c);
    for(i=0; i<l; i++)
    {
        m[c[i]-'0']++;
        stack[c[i]-'0'][top[c[i]-'0']++]=i;
    }
    for(pos[0]=0, i=1; i<10; i++) pos[i]=pos[i-1]+m[i];
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++) m1[i][j]=m[j];
        for(j=0; j<l; j++) c1[i][j]=c[j];
        for(j=1, f=top[i]; j<10; j++)
        {
            if (i+j<10)
                for(i1=0; f<k &&  i1<top[i+j]; i1++)
                {
                    ans[i]+=j;
                    c1[i][stack[i+j][i1]]=i+'0';
                    f++;
                }
            if (i-j>=0)
                for(i1=top[i-j]-1; f<k &&  i1>=0; i1--)
                {
                    ans[i]+=j;
                    c1[i][stack[i-j][i1]]=i+'0';
                    f++;
                }
        }
    }
    for(i=0; i<10; i++)
    {
        if (ans[i]<max) {max=ans[i]; maxi=i;}
        else if (ans[i]==max)
        {
            if (strcmp(c1[i], c1[maxi])<0) {max=ans[i]; maxi=i;} 
        }
    }
    printf("%d\n%s", max, c1[maxi]);
}