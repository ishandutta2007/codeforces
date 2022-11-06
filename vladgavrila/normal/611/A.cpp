#include <cstdio>
#include <iostream>

using namespace std;

int x;
string s;

int main()
{
    cin>>x;
    cin>>s;
    cin>>s;

    if(s[0]=='w')
    {
        if(x==1)
            cout<<52<<"\n";
        if(x==2)
            cout<<52<<"\n";
        if(x==3)
            cout<<52<<"\n";
        if(x==4)
            cout<<52<<"\n";
        if(x==5)
            cout<<53<<"\n";
        if(x==6)
            cout<<53<<"\n";
        if(x==7)
            cout<<52<<"\n";
    }
    else
    {
        if(x==31)
            cout<<7<<"\n";
        if(x==30)
            cout<<11<<"\n";
        if(x<=29)
            cout<<12<<"\n";
    }
    return 0;
}