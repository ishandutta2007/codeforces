#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=100+10;
const int inf=0x3f3f3f3f;

bool check(int a)
{
    int arr[5];
    arr[0]=a%10;
    arr[1]=a/10%10;
    arr[2]=a/100%10;
    arr[3]=a/1000%10;
    int sum=0;
    for(int i=0;i<4;i++)sum+=arr[i];
    if(sum%4==0)return true;
    return false;
}

int main()
{
    int a;
    cin>>a;
    for(int i=a;;i++)
    {
        if(check(i))
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}