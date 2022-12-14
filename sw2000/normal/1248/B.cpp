#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int main()
{
    int n,arr[maxn];
    ll a=0,b=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        a+=arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n/2;i++)
    {
        b+=arr[i];
        a-=arr[i];
    }
    cout<<a*a+b*b;
    return 0;
}