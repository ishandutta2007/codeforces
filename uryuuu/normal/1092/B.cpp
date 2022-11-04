#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int a[200];
int main()
{
    int t,s=0;
    cin>>t;
    for(int i=0;i<t;i++)
        cin>>a[i];
    sort(a,a+t);
    for(int i=0;i<t;i+=2)
        s+=(a[i+1]-a[i]);
    cout<<s<<endl;
    return 0;
}