#include<bits/stdc++.h>

using namespace std;

bool ok(vector< vector<int> > a)
{
    if(a.size()%2)return false;
    for(int i=0;i<(a.size()>>1);i++)
        for(int j=0;j<a[0].size();j++)
            if(a[i][j]!=a[a.size()-1-i][j])
                return false;
    return true;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector< vector<int> > a(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    while(ok(a))
        a.resize(a.size()/2);
    printf("%d",a.size());
}