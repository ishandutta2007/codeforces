#include<bits/stdc++.h>

#define mp make_pair

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    pair<int,int> p[100001];
    for(int i=0;i<=100000;i++)
        p[i]=mp(0,0);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        if(p[a].first==-1)
            continue;
        if(p[a].first==0)
            p[a].first=i;
        else if(p[a].second==0)
            p[a]=mp(i,i-p[a].first);
        else if(p[a].second!=(i-p[a].first))
            p[a].first=-1;
        else
            p[a].first=i;
    }
    int k=0;
    for(int i=1;i<=100000;i++)
        if(p[i].first>0)
            k++;
    printf("%d\n",k);
    for(int i=1;i<=100000;i++)
        if(p[i].first>0)
            printf("%d %d\n",i,p[i].second);
}