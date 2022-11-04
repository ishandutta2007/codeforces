#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
int inf=0x3f3f3f3f;
using namespace std;
int main()
{
    int a1,b1,a2,b2,mid,aa,bb,a3,b3;
    scanf("%d:%d",&a1,&b1);
    scanf("%d:%d",&a2,&b2);
    aa=a1*60+b1;
    bb=a2*60+b2;
    mid=(bb+aa)/2;
    a3=mid/60;
    b3=mid%60;
    if(a3<10)
        cout<<"0";
    cout<<a3<<":";
    if(b3<10)
        cout<<"0";
    cout<<b3<<endl;
    return 0;
}