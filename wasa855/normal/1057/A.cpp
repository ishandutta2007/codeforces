#include<bits/stdc++.h>
using namespace std;
int fa[200005];
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&fa[i]);
    }
    stack<int> s;
    int t=n;
    while(t!=0)
    {
        s.push(t);
        t=fa[t];
    }
    while(!s.empty())
    {
        printf("%d ",s.top());
        s.pop();
    }
    return 0;
}
//fesydcoizdrg