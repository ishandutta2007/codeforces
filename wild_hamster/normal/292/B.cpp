#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int main(int argc, const char * argv[])
{
    int n,m;
    cin>>n>>m;
    int a[100100];
    int x1,y1;
    for (int i=1;i<=n;i++) a[i]=0;
    for(int i=0;i<m;i++)
    {
        cin>>x1>>y1;
        a[x1]++;
        a[y1]++;
    }
    sort(a+1,a+n+1);
    bool ring=true;// 2 2 2 2 2
    bool bus=true;//1 1 2 2 2 2 2
    bool star=false;//1 1 1 1 1 1 1 3
    if(a[n]==n-1)star=true;
    if((a[1]!=1) || (a[2]!=1))bus=false;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=2)ring=false;
        if(i!=n)
            if(a[i]!=1)star=false;
        if(i<3)continue;
        if(a[i]!=2)bus=false;
    }
    if(bus){cout<<"bus topology";return 0;}
    if(ring)
    {cout<<"ring topology";return 0;}
    
    if(star){cout<<"star topology";return 0;}
    cout<<"unknown topology";
    return 0;
}