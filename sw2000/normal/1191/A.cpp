#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;

int main()
{
    int a;
    cin>>a;
    if(a%4==0)
    {
        cout<<"1 A"<<endl;
    }
    if(a%4==1)
    {
        cout<<"0 A"<<endl;
    }
    if(a%4==2)
    {
        cout<<"1 B"<<endl;
    }
    if(a%4==3)
    {
        cout<<"2 A"<<endl;
    }
    return 0;
}