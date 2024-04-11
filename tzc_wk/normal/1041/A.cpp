#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

const int maxx=1e3+10;
int a[maxx];
int n;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    ll sum=0;
    for(int i=1;i<n;i++)
    {
        sum+=(a[i]-a[i-1]-1);
    }
    cout<<sum<<endl;
}