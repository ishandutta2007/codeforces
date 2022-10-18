#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    int m,n;
    cin>>m>>n;
    int maxn=0,minn=0,t;
    int now=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&t);
        now+=t;
        maxn=max(maxn,now);
        minn=min(minn,now);
    }
    if(minn+n-maxn+1<=0)
    {
        cout<<"0\n";
        return 0;
    }
    cout<<minn+n-maxn+1<<endl;
    return 0;
}