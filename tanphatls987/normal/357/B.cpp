#include <iostream>

using namespace std;
int main()
{
    short int a[100001]={0};
    long int x,y,z,n,m,i;
    cin>>n>>m;
    for (i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        if (a[x]>0){a[y]=(a[x]+1)%3;a[z]=(a[x]-1)%3;if (!a[y]) a[y]=3;if(!a[z])a[z]=3;}
        else {if (a[y]>0){a[x]=(a[y]+1)%3;a[z]=(a[y]-1)%3;if (!a[x]) a[x]=3;if(!a[z]) a[z]=3;}
        else {if (a[z]>0){a[y]=(a[z]+1)%3;a[x]=(a[z]-1)%3;if (!a[y]) a[y]=3;if(!a[x]) a[x]=3;}
        else {a[x]=1;a[y]=2;a[z]=3;}}}
    }
    for(i=1;i<=n;i++) cout<<a[i]<<" ";
}