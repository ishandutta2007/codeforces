#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct wpn{char name[20]; int v1, v2, v3, type, size;} wp[105];
struct par{char name[20]; int v;} pr[4][1005];
int m[105][1005], top[105], n, tp[4], sum[4][1005];

int cmp(const void *c1, const void *c2)
{return strcmp(((wpn*)c1)->name, ((wpn*)c2)->name);}

int cmp1(const void *c1, const void *c2)
{return ((par*)c2)->v-((par*)c1)->v;}

int bin_search(char *nm)
{
    int i, p, q, tmp;
    for(p=0, q=n-1; p<=q; )
    {
        i=(p+q)/2;
        tmp=strcmp(wp[i].name, nm);
        if (!tmp) return i;
        if (tmp<0) p=i+1;
        else q=i-1;
    }
    return -1;
}

int main()
{
    int k, i, j, tmp, ind, max[4], maxi[4], s=0, cur, max_num[4], i1, j1, tp2[4];
    char c[20], c1[20], nm[1005][20];
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s %s %d %d %d %d", &wp[i].name, &c, &wp[i].v1, &wp[i].v2, &wp[i].v3, &tmp);
        if (c[0]=='w') wp[i].type=1;
        if (c[0]=='a') wp[i].type=2;
        if (c[0]=='o') wp[i].type=3;
        wp[i].size=tmp;
        s+=tmp;
    }
    qsort(wp, n, sizeof(wpn), cmp);
    scanf("%d", &k);
    if (k==s)
    {
        for(i=0; i<k; i++)
        {
            scanf("%s %s %d %s", &nm[i], &c, &tmp, &c1);
            ind=bin_search(c1);
            m[ind][top[ind]++]=i;
            if (c[0]=='g') wp[ind].v1+=tmp;
            if (c[0]=='s') wp[ind].v2+=tmp;
            if (c[0]=='p') wp[ind].v3+=tmp;
        }
        for(i=1; i<4; i++) max[i]=-1;
        for(i=0; i<n; i++)
        {
            if (wp[i].type==1)
            {if (max[1]<wp[i].v1) {max[1]=wp[i].v1; maxi[1]=i;}}
            if (wp[i].type==2)
            {if (max[2]<wp[i].v2) {max[2]=wp[i].v2; maxi[2]=i;}}
            if (wp[i].type==3)
            {if (max[3]<wp[i].v3) {max[3]=wp[i].v3; maxi[3]=i;}}
        }
        for(i=1; i<4; i++)
        {
            printf("%s %d ", wp[maxi[i]].name, top[maxi[i]]);
            for(j=0; j<top[maxi[i]]; j++) printf("%s ", nm[m[maxi[i]][j]]);
            putchar('\n');
        }
        return 0;
    }
    for(i=0; i<k; i++)
    {
        scanf("%s %s %d %s", &nm[i], &c, &tmp, &c1);
        if (c[0]=='g') {strcpy(pr[1][tp[1]].name, nm[i]); pr[1][tp[1]++].v=tmp;}
        if (c[0]=='s') {strcpy(pr[2][tp[2]].name, nm[i]); pr[2][tp[2]++].v=tmp;}
        if (c[0]=='p') {strcpy(pr[3][tp[3]].name, nm[i]); pr[3][tp[3]++].v=tmp;}
    }
    for(j=1; j<4; j++) 
    {
        qsort(pr[j], tp[j], sizeof(par), cmp1);
        sum[j][0]=0;
        for(i=1; i<=tp[j]; i++) sum[j][i]=sum[j][i-1]+pr[j][i-1].v;
    }
    for(i=1; i<4; i++) max[i]=-1;
    for(i=0; i<n; i++)
    {
        if (wp[i].type==1)
        {
            tmp=(wp[i].size>tp[1]? tp[1]: wp[i].size);
            cur=wp[i].v1+sum[1][tmp];
            if (cur>max[1]) {max[1]=cur; maxi[1]=i;}
        }
        if (wp[i].type==2)
        {
            tmp=(wp[i].size>tp[2]? tp[2]: wp[i].size);
            cur=wp[i].v2+sum[2][tmp];
            if (cur>max[2]) {max[2]=cur; maxi[2]=i;}
        }
        if (wp[i].type==3)
        {
            tmp=(wp[i].size>tp[3]? tp[3]: wp[i].size);
            cur=wp[i].v3+sum[3][tmp];
            if (cur>max[3]) {max[3]=cur; maxi[3]=i;}
        }
    }
    for(i=1; i<4; i++)
    {max_num[i]=wp[maxi[i]].size>=tp[i]? tp[i]: wp[maxi[i]].size; tp2[i]=max_num[i];}
    for(i=1; i<4; i++)
        for(j=0; j<max_num[i]; j++)
            m[i][top[i]++]=i*10000+j;
    for(i=1; i<4; i++)
        if (max_num[i]<wp[maxi[i]].size)
        {
            for(j=1; j<4; j++)
                for(i1=tp2[j]; i1<tp[j] && max_num[i]<wp[maxi[i]].size; i1++) {m[i][top[i]++]=10000*j+i1; max_num[i]++; tp2[j]++;}
        }
    for(i=1; i<4; i++)
    {
        printf("%s %d ", wp[maxi[i]].name, max_num[i]);
        for(j=0; j<max_num[i]; j++) printf("%s ", pr[m[i][j]/10000][m[i][j]%10000].name);
        putchar('\n');
    }
}