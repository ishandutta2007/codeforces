#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <map>
#include <string>
using namespace std;

int cmp(const void *c1, const void *c2)
{return *(int*)c1-*(int*)c2;}

long long get_hash(char *c, int l)
{
    int i; long long ans=0;
    for(i=0; i<l; i++)
        ans=ans*1003+(long long)(c[i]-'a'+1);
    return ans;
}

int m2[1000];
map<long long, int> mp;

int main()
{   
  
    int m1[1000], i, j, n1, n2, l, top=0, ans;
    long long tmp;
    char c[35];
    scanf("%d %d", &n1, &n2);
    for(i=0; i<n1; i++)
        scanf("%d", &m1[i]);
    qsort(m1, n1, sizeof(int), cmp);
    for(i=0; i<n2; i++)
    {
        scanf("%s", &c);
        l=strlen(c);
        tmp=get_hash(c, l);
        if (mp.find(tmp)!=mp.end())
        {m2[mp[tmp]]++;}
        else 
        {
            mp[tmp]=top;
            m2[top]=1;
            top++;
        }
    }
    qsort(m2, top, sizeof(int), cmp);
    for(ans=i=0, j=top-1; j>=0; j--, i++)
        ans+=m1[i]*m2[j];
    printf("%d ", ans);
    ans=0;
    for(i=n1-1, j=top-1; j>=0; j--, i--)
        ans+=m1[i]*m2[j];
    printf("%d", ans);
}