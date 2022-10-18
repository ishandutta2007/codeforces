#include<bits/stdc++.h>
using namespace std;
int x,y;
int main()
{
    cin>>x>>y;
    if(x==y)
    {
        cout<<"=";
    }
    else if(x==2&&y==4)
    {
        cout<<"=";
    }
    else if(x==4&&y==2)
    {
        cout<<"=";
    }
    else if(x==2&&y==3)
    {
        cout<<"<";
    }
    else if(x==3&&y==2)
    {
        cout<<">";
    }
    else if(x==1&&y!=1)
    {
        cout<<"<";
    }
    else if(x!=1&&y==1)
    {
        cout<<">";
    }
    else if(x<y)
    {
        cout<<">";
    }
    else
    {
        cout<<"<";
    }
    return 0;
}