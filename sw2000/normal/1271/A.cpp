#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=3e3+10;
const ll mod=1e9+7;

int main()
{
//    freopen("in.txt","r",stdin);
    int arr[6];
    for(int i=0;i<6;i++)
        cin>>arr[i];
    int a=arr[0];
    int b=min(arr[1],arr[2]);
    int c=arr[3];
    int e=arr[4];
    int f=arr[5];
    if(a+b<=c)
    {
        cout<<arr[4]*a+arr[5]*b;
    }
    else
    {
        if(e<f)
        {
            cout<<min(b,c)*f+max(0,c-b)*e;
        }
        else
        {
            cout<<min(a,c)*e+max(0,c-a)*f;
        }
    }
    return 0;
}