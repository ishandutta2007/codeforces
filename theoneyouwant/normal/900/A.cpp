#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,y,pl=0,pr=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(x>0)
        {
            pr++;
        }
        else if(x<0)
        {
            pl++;
        }
    }
    if(pl>=n-1 || pr>=n-1)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    
}