#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <map>
using namespace std;

long long p=101;

long long get_hash(char *c)
{
    int i, l=strlen(c); long long v=0;
    for(i=0; i<l; i++) v=v*p+(c[i]-'a'+1);
    return v;
}

int main()
{   
    char c[33];
    int i, n;
    long long v;
    map <long long, int> mp;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s", &c);
        v=get_hash(c);
        if (mp.find(v)==mp.end())
        {
            mp[v]=1; printf("OK\n"); continue;
        }
        printf("%s%d\n", c, mp[v]); mp[v]++; continue;
    }
}