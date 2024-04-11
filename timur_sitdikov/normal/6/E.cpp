#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *c1, const void *c2)
{return 0;}

int m[101005], i, j, k, n, cmin, cmax, maxi, max, stack[101005][2], top;
int mn[350], mx[350], d;

void sqrt_dec()
{
    int i, j;
    d=(n+299)/300;
    for(i=n; i<300*d; i++) m[i]=0;
    for(i=j=0; i<d; i++)
        for(mn[i]=mx[i]=m[j]; j<(i+1)*300; j++)
        {
            if (m[j]>mx[i]) mx[i]=m[j];
            if (m[j]<mn[i] && m[j]) mn[i]=m[j];
        }
}

int find_min(int s, int f)
{
    if (s>=n) return -1;
    int i, tm1, tm2, s1, f1, ans;
    tm1=(s+299)/300*300; s1=tm1/300; f1=f/300;  tm2=f1*300;
    if (tm1>tm2)
    {for(ans=m[s], i=s; i<=f; i++) if (m[i] && m[i]<ans) ans=m[i]; return ans;}
    for(ans=m[s], i=s; i<tm1; i++) if (m[i] && m[i]<ans) ans=m[i];
    for(i=s1; i<f1; i++) if (mn[i]<ans) ans=mn[i];
    for(i=tm2; i<=f; i++) if (m[i] && m[i]<ans) ans=m[i];
    return ans;
}
int find_max(int s, int f)
{
    if (s>=n) return -1;
    int i, tm1, tm2, s1, f1, ans;
    tm1=(s+299)/300*300; s1=tm1/300; f1=f/300;  tm2=f1*300;
    if (tm1>tm2)
    {for(ans=m[s], i=s; i<=f; i++) if (m[i]>ans) ans=m[i]; return ans;}
    for(ans=m[s], i=s; i<tm1; i++) if (m[i]>ans) ans=m[i];
    for(i=s1; i<f1; i++) if (mx[i]>ans) ans=mx[i];
    for(i=tm2; i<=f; i++) if (m[i]>ans) ans=m[i];
    return ans;
}

int main()
{   

    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++) scanf("%d", &m[i]);
    sqrt_dec();
    stack[0][0]=0; stack[0][0]=0; top=1;
    for(i=maxi=0, cmin=cmax=m[0], max=0, j=1; i<n && j<n; )
    {
        if (j<i) {cmin=cmax=m[i]; j=i;}
        if (m[j]<cmin && cmax-m[j]>k) cmin=m[j];
        if (m[j]>cmax && m[j]-cmin>k) cmax=m[j];
        if (cmax-cmin>k)
        {
            if (m[i]==cmax) cmax=find_max(i+1, j);
            if (m[i]==cmin) cmin=find_min(i+1, j); 
            i++; continue;
        }
        if (m[j]<cmin && cmax-m[j]<=k) cmin=m[j]; 
        if (m[j]>cmax && m[j]-cmin<=k) cmax=m[j];   
        if (j-i>max)
        {max=j-i; stack[0][0]=i; stack[0][1]=j; top=1;}
        else if (j-i==max)
        {stack[top][0]=i; stack[top][1]=j; top++;}
        j++;
    }
    printf("%d %d\n", max+1, top);
    for(i=0; i<top; i++)
        printf("%d %d\n", stack[i][0]+1, stack[i][1]+1);    
}