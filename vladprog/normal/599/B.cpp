#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    multimap<int,int> f;
    for(int i=1;i<=n;i++)
    {
        int c;
        scanf("%d",&c);
        f.insert(make_pair(c,i));
    }
    int a[m],ans=0;
    for(int i=0;i<m;i++)
    {
        int c;
        scanf("%d",&c);
        switch(f.count(c))
        {
            case 0:return printf("Impossible\n"), 0;
            case 1:a[i]=f.find(c)->second;break;
            default:ans=1;
        }
    }
    if(ans)return printf("Ambiguity\n"), 0;
    printf("Possible\n");
    for(int i=0;i<m;i++)
        printf("%d ",a[i]);
}