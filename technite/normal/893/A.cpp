#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3]={1,1,0};
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        x--;
        if(a[x]==0)
        {
            cout<<"NO"<<'\n';
            return 0;
        }
        for(int i=0;i<3;i++)
        {
            if(a[i]==0) a[i]=1;
            else a[i]=0;
        }
        a[x]=1;
    }
    cout<<"YES"<<'\n';
}