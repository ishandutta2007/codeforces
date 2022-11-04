#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
int inf=0x3f3f3f3f;
using namespace std;
int main()
{
    int b,k,a;
    while(cin>>b>>k)
    {
    int bb[10];
    bb[1]=b%2;
    bb[2]=bb[1]*bb[1];
    bb[3]=bb[1]*bb[1]*bb[1];
    bb[0]=bb[3]*bb[1];
    int sum=0;
    for(int i=k-1;i>=1;i--)
    {
        cin>>a;
        sum+=((a%2)*bb[i%4]);
    }
        cin>>a;
        sum+=(a%2);
    if(sum%2)
        cout<<"odd"<<endl;
    else
        cout<<"even"<<endl;
    }
    return 0;
}