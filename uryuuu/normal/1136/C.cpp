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
int a[505][505];
int b[505][505];
map<int,int>v[1010];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            v[i+j][a[i][j]]++;
        }
    }
    int f=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&b[i][j]);
            if(v[i+j][b[i][j]]<=0)
            {
                f=1;
            }
            v[i+j][b[i][j]]--;
        }
    }
    if(f==0)
    cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}