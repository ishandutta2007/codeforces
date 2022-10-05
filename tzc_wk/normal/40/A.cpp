#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    double dist=sqrt(x*x*1.0+y*y*1.0);
    int k=(int)dist;
    if(dist==k)
    {
        cout<<"black";
        return 0;
    }
    if(x>0&&y>0||x<0&&y<0)
    {
        if(k&1)
            cout<<"white";
        else
            cout<<"black";
    }
    else
    {
        if(k&1)
            cout<<"black";
        else
            cout<<"white";
    }
    return 0;
}