#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<stdio.h>
typedef long long ll;
using namespace std;
int x1,y1,x2,y2,x3,y3;
void path(int x1,int y1,int x2,int y2)
{
    for(int i=x1;i!=x2;)
    {
        cout<<i<<" "<<y1<<endl;
        i += x2-x1>0?1:-1;
    }
    for(int j=y1;j!=y2;)
    {
        cout<<x2<<" "<<j<<endl;
        j += y2-y1>0?1:-1;
    }
}

int incorner(int x1,int y1,int x2,int y2,int x3,int y3)
{
    if(((x3>=x1&&x3>=x2)||(x3<=x1&&x3<=x2)) && ((y3>=y1&&y3>=y2)||(y3<=y1&&y3<=y2)))
    {
        int px,py,bx,by;
        if(x3<=x1&&x3<=x2)
        {
            if(x1<=x2) px=x1,bx=x2,by=y1,py=y2;
            else bx=x1,px=x2,py=y1,by=y2;
        }
        else
        {
            if(x1>=x2) px=x1,bx=x2,by=y1,py=y2;
            else bx=x1,px=x2,py=y1,by=y2;
        }
        cout<<abs(x3-bx)+abs(y3-by)+1<<endl;
        path(x1,y1,px,py);
        path(x2,y2,px,py);
        path(x3,y3,px,py);
        cout<<px<<" "<<py<<endl;
        return 1;
    }
    else return 0;
}
int cover(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return ((x1<=x3&&x3<=x2)||(x2<=x3&&x3<=x1)) && ((y1<=y3&&y3<=y2)||(y2<=y3&&y3<=y1));
}

int main()
{
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if(cover(x1,y1,x2,y2,x3,y3))
    {
        cout<<abs(x1-x2)+abs(y1-y2)+1<<endl;
        path(x1,y1,x3,y3);
        path(x3,y3,x2,y2);
        cout<<x2<<" "<<y2<<endl;
    }
    else if(cover(x1,y1,x3,y3,x2,y2))
    {
        cout<<abs(x1-x3)+abs(y1-y3)+1<<endl;
        path(x1,y1,x2,y2);
        path(x2,y2,x3,y3);
        cout<<x3<<" "<<y3<<endl;
    }
    else if(cover(x2,y2,x3,y3,x1,y1))
    {
        cout<<abs(x2-x3)+abs(y2-y3)+1<<endl;
        path(x2,y2,x1,y1);
        path(x1,y1,x3,y3);
        cout<<x3<<" "<<y3<<endl;
    }
    else
    {
        if(incorner(x1,y1,x2,y2,x3,y3));
        else if(incorner(x2,y2,x3,y3,x1,y1));
        else if(incorner(x1,y1,x3,y3,x2,y2));
        else while(1);
    }
}