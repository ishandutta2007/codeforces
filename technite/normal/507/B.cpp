#include<bits/stdc++.h>
using namespace std;
int main()
{
    float r,x,y,x1,y1;
    cin>>r>>x>>y>>x1>>y1;
    double p=pow((x-x1),2);
    double q=pow((y-y1),2);
    cout<<ceil(sqrt(p+q)/2/r);
    
}