#include<iostream>
#include<set>
using namespace std;

int main()
{
    int n,xo,yo,x,y;
    cin>>n>>xo>>yo;
    set<double>s;
    bool c=0;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(x!=xo)
        {
            s.insert(1.0*(y-yo)/(x-xo));
        }
        else
        {
            c=1;
        }
    }
    if(c==1)
    {
        cout<<s.size()+1;
    }
    else
    {
        cout<<s.size();
    }
}