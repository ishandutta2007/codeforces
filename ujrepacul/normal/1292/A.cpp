#include <bits/stdc++.h>
using namespace std;
int fv[100005][2];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,i,j=0,m,cnt=0;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        --a;
        if(fv[b][a]==1)
            cnt-=(fv[b-1][1-a]+fv[b][1-a]+fv[b+1][1-a]);
        if(fv[b][a]==0)
            cnt+=(fv[b-1][1-a]+fv[b][1-a]+fv[b+1][1-a]);
        fv[b][a]=1-fv[b][a];
        if(cnt==0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}