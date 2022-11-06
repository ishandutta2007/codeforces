#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char c[100005];
char ex[26];
struct pr{int v,num;} v[26];

int cmp(const void *c1, const void *c2)
{return ((pr*)c2)->v-((pr*)c1)->v;}

int main()
{
    int i, l, k, s, res;
    scanf("%s %d", &c, &k);
    l=strlen(c);
    for(i=0; i<l; i++) v[c[i]-'a'].v++;
    for(i=0; i<26; i++) v[i].num=i;
    qsort(v, 26, sizeof(pr), cmp);
    for(s=i=0; s<l-k; i++) s+=v[i].v;
    res=i;
    printf("%d\n", res);
    for(i=0; i<res; i++) ex[v[i].num]=1;
    for(i=0; i<l; i++)
        if (ex[c[i]-'a']) putchar(c[i]);

}