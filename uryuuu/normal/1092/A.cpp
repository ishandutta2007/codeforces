#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n/k;i++)
    {
        for(int j=0;j<k;j++)
            cout<<(char)('a'+j);
    }
    for(int i=0;i<n%k;i++)
        cout<<(char)('a'+i);
        cout<<endl;
    }
    return 0;
}