#include<iostream>
using namespace std;
int a[110];
int main()
{
    int t,i,s=0;
    cin>>t;
    for(i=0;i<t;i++)
        cin>>a[i];
    for(i=1;i<(t-1);i++)
    {
        if(a[i-1]==a[i+1]&&a[i-1]==1&&a[i]==0)
        {
            a[i+1]=0;
            s++;
            }
    }
    cout<<s<<endl;
    return 0;
}