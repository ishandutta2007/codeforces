#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    bool c=1;
    long long int n,m;
    cin>>n>>m;
    long long int a[m];
    for(long long int i=0;i<m;i++)
    {
        cin>>a[i];
        if(a[i]==1 || a[i]==n)
        {
            c=0;
        }
    }
    sort(a,a+m);
    for(long long int i=1;i<m-1;i++)
    {
        if(a[i]==a[i-1]+1 && a[i+1]==a[i]+1)
        {
            c=0;
            break;
        }
    }
    if(c==1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}