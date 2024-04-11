#include <iostream>
int x,y;
using namespace std;
int remake()
{
    if (x==y){if (x>0) y=-x+1;else y=-x;return 0;}
    if ((x==-y)&&(x<0)) {x=y;return 0;}  
    if ((y==-x+1)&&(x>0)) {x=y;return 0;}
    if (x<=y)
    {   
        if ((x<0)&&(y<-x)) y=-x;
        else x=y;
    }
    else
    {
        if((x>0)&&(-y+1<x)) y=-x+1;
        else x=y;
    }
}
int main()
{
    int ans;
    cin>>x>>y;
    remake();
    ans=0;
    if (x<=0) ans-=2*x;else ans+=2*x-1;
    if (y<=0) ans+=(-2*y+1);else ans+=2*y;
    cout<<(ans-1);
}