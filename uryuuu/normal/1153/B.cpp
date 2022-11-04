#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
int a[105],b[105],c[105][105];
int main()
{
    int n,m,h;
    cin>>n>>m>>h;
    for(int i=0;i<m;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    int d;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>d;
            if(d)
                c[i][j]=min(b[i],a[j]);
        }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<c[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}