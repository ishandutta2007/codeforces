#include<bits/stdc++.h>

using namespace std;

const int inf=2000000001;

int main()
{
    int n,k,S,T;
    scanf("%i%i%i%i",&n,&k,&S,&T);
    pair<int,int> a[n+2];
    for(int i=0;i<n;i++)
        scanf("%i%i",&a[i].second,&a[i].first);
    a[n]=make_pair(inf,inf);
    a[n+1]=make_pair(0,inf);
    n+=2;
    sort(a,a+n);
    int g[k+2];
    for(int i=0;i<k;i++)
        scanf("%i",&g[i]);
    g[k]=0;
    g[k+1]=S;
    k+=2;
    sort(g,g+k);
    int l=0,r=n-1;
    while ((r-l)>1)
    {
        int m=(l+r)/2,t=0,f=a[m].first;
        for(int i=1;i<k;i++)
        {
            int s=g[i]-g[i-1];
            if(s>f)
            {
                t=inf;
                break;
            }
            if(s*2<=f)
                t+=s;
            else
                t+=3*s-f;
        }
        if(t<=T)
            r=m;
        else
            l=m;
    }
    int m=inf,f=a[r].first;
    for(int i=0;i<n;i++)
        if(a[i].first>=f)
            m=min(m,a[i].second);
    if(m==inf)
        m=-1;
    printf("%i\n",m);
}