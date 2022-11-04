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
#define ll long long
#define N 500005
#define mod 1000000007
ll inf=1e18;
using namespace std;
int a,b[105];
int main()
{
    memset(b,0,sizeof(b));
    int n,q=0,w=0,e=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    sort(b,b+n);
    int nn=unique(b,b+n)-b;
    if(nn>3)
    {
        cout<<-1<<endl;
        return 0;
    }
    int s;
    if(b[1]==b[0]||b[1]==0)
    {
        s=0;
    }
    else if(b[2]==b[1]||b[2]==b[0]||b[2]==0)
    {
        if((b[1]-b[0])%2==0)
            s=(b[1]-b[0])/2;
        else
            s=b[1]-b[0];
    }
    else
    {
        if(b[2]+b[0]==2*b[1])
            s=b[1]-b[0];
        else
            s=-1;
    }
    cout<<s<<endl;
    return 0;
}