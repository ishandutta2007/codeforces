#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    long int x,y,c,x1,y1,x2,y2;
    cin>>x>>y;
    c=abs(x)+abs(y);
    x1=0;x2=0;y1=0;y2=0;
    if (x<=0) {x1=-c;if (y<=0)y2=-c;else y2=c;}
    else {x2=c;if (y>=0) y1=c;else y1=-c;}
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2;
}