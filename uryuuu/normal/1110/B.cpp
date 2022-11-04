#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
int inf=0x3f3f3f3f;
using namespace std;
int cha[100100];
int main()
{
    int n,m,k;
    while(cin>>n>>m>>k)
    {
        int x,y,b,sum=0;
        cin>>b;
        x=b;
        for(int i=0;i<n-1;i++)
        {
            cin>>b;
            y=b;
            cha[i]=y-x;
            x=y;
        }
        sort(cha,cha+n-1);
        for(int i=0;i<n-k;i++)
            sum+=cha[i];
        sum+=k;
        cout<<sum<<endl;
    }
    return 0;
}