#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int r,x1,y1,x2,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    double dist;
    dist = sqrt( pow((x1-x2),2)+pow((y1-y2),2));
    int turns=0;
    while(dist>2*r)
    {
        turns+=1;
        dist-=2*r;
    }
    if(dist!=0)
    {
        turns+=1;
    }
    cout<<turns;
    return 0;
}