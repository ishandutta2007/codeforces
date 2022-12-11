#include<bits/stdc++.h>
using namespace std;
vector<int> ans[2];
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int sum=0,n=0;
    while(sum<=a+b)
        sum+=++n;
    --n;
    for(int i=n;i>=1;--i)
    {
        if(i<=a)
        {
            ans[0].push_back(i);
            a-=i;
        }
        else
            ans[1].push_back(i);
    }
    for(int i=0;i<=1;++i)
    {
        printf("%d\n",int(ans[i].size()));
        for(int j=0;j<int(ans[i].size());++j)
            printf("%d%c",ans[i][j],j+1<int(ans[i].size())?' ':'\n');
        if(ans[i].empty())
            puts("");
    }
    return 0;
}