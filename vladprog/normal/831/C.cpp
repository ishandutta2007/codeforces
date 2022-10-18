#include<bits/stdc++.h>

using namespace std;

int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    int a[k];
    for(int i=0;i<k;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<k;i++)
        a[i]+=a[i-1];
    int b[n];
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    set<int> s;
    for(int j=0;j<k;j++)
        s.insert(-a[j]+b[0]);
    for(int i=1;i<n;i++)
    {
        set<int> t;
        for(int j=0;j<k;j++)
            t.insert(-a[j]+b[i]);
        set<int> e;
        for(set<int>::iterator i=s.begin();i!=s.end();i++)
            if(!t.count(*i))
                e.insert(*i);
        for(set<int>::iterator i=e.begin();i!=e.end();i++)
            s.erase(*i);
    }
    printf("%d\n",s.size());
    /*for(set<int>::iterator i=s.begin();i!=s.end();i++)
        printf("%d ",*i);*/
}