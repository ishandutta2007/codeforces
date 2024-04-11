#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int h1,a1,c1,h2,a2;
    cin>>h1>>a1>>c1>>h2>>a2;
    vector<char> v;
    int counter=0;
    while(h2>0)
    {
        if(h2<=a1)
        {
            h2=0;
            v.push_back('s');
        }
        else
        {
        if(h1>a2)
        {
            h2=h2-a1;
            h1=h1-a2;
            v.push_back('s');
        }
        else
        {
            h1+=c1-a2;
            v.push_back('h');
        }
        }
        counter++;
    }
    cout<<counter<<endl;
    for(vector<char>::iterator it = v.begin();it!=v.end();it++)
    {
        if((*it) == 's')
        {
            cout<<"STRIKE"<<endl;
        }
        else
        {
            cout<<"HEAL"<<endl;
        }
    }
}