#include<iostream>
using namespace std;

int main()

{
    string s;
    cin>>s;
    bool c=0;
    int counter1=0,counter2=0,counter3=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='4')
        {
            counter1++;
            c=1;
        }
        else if(s[i]=='7')
        {
            if(i!=0 && s[i-1]=='4')
            {
                counter3++;
            }
            counter2++;
            c=1;
        }
    }
    if(c==0)
    {
        cout<<"-1";
    }
    else if(counter1>=counter2)
    {
        cout<<"4";
    }
    else if(counter2>counter3)
    {
        cout<<"7";
    }
    else
    {
        cout<<"47";
    }
    return 0;
}