#include<iostream>
using namespace std;

int main()
{
    int a[9];
    for(int i=0;i<9;i++)
    {
        cin>>a[i];
    }
    a[4] = a[0]+a[2]-a[7];
    a[8] = a[0]+a[1]-a[5];
    int x;
    x = (a[1]+a[2]-a[4]-a[8])/2;
    a[0]+=x;
    a[4]+=x;
    a[8]+=x;
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl<<a[3]<<" "<<a[4]<<" "<<a[5]<<endl<<a[6]<<" "<<a[7]<<" "<<a[8];
}