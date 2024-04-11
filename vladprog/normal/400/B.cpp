#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    set<int> ans;
    for(int i=1;i<=n;i++)
    {
        scanf("%*c");
        int g,s;
        for(int i=1;i<=m;i++)
        {
            char c;
            scanf("%c",&c);
            if(c=='G')g=i;
            if(c=='S')s=i;
        }
        ans.insert((s>g)?(s-g):m);
    }
    printf("%d\n",ans.count(m)?-1:ans.size());
}