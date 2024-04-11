#include <stdio.h>
#include <stdlib.h>

struct pr{int num, v, fl;} pp[200005], pp2[200005];
int s[100005], f[100005], n, m, top;
long long num_f[200005], v[200005];

int cmp(const void *c1, const void *c2)
{return ((pr*)c1)->v-((pr*)c2)->v;}

int max(int a, int b) {return a>b? a: b;}

int main()
{
    int i, j, a, b, f1;
    long long d=1000000007, tmp;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        pp[2*i].v=a; pp[2*i+1].v=b;
        pp[2*i].fl=0; pp[2*i+1].fl=1; 
        pp[2*i].num=pp[2*i+1].num=i;
    }
    qsort(pp, 2*m, sizeof(pr), cmp);
    if (pp[0].v>0) {printf("0"); return 0;}
    if (pp[2*m-1].v<n) {printf("0"); return 0;}
    for(i=0; i<2*m; i++) pp2[i]=pp[i];
    for(i=1; i<2*m; i++)
        if (pp[i].v==pp[i-1].v) pp2[i].v=pp2[i-1].v;
        else pp2[i].v=pp2[i-1].v+1;
    top=pp2[2*m-1].v+1;
    for(i=0; i<2*m; i++)
        if (pp2[i].fl) f[pp2[i].num]=pp2[i].v;
        else s[pp2[i].num]=pp2[i].v;
    for(i=0; i<m; i++)
        num_f[f[i]]++;
    j=1; v[0]=1;
    for(i=0; i<2*m; i++)
        if (pp2[i].fl) 
        {
            for(; j<pp2[i].v; j++) v[j]=(v[j]+v[j-1])%d;
            if (s[pp2[i].num]-1<0) tmp=0;
            else tmp=v[s[pp2[i].num]-1];
            v[pp2[i].v]=(d+v[pp2[i].v]+v[pp2[i].v-1]-tmp)%d;
        }
    printf("%lld", v[top-1]);
}