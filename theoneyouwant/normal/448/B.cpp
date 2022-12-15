#include<iostream>
#include<set>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    multiset<int> myset,myset2;
    for(int i=0;i<s.length();i++)
    {
        myset.insert(s[i]);
    }
    for(int i=0;i<t.length();i++)
    {
        myset2.insert(t[i]);
    }
    bool b=0;
    for(multiset<int>::iterator it = myset2.begin();it!=myset2.end();it++)
    {
        if(myset.count(*it)<myset2.count(*it))
        {
            b=1;
            break;
        }
    }
    if(b==1)
    {
        cout<<"need tree";
    }
    if(b==0)
    {
        if(myset.size()==myset2.size())
        {
            cout<<"array";
        }
        else
        {
            int j=0;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]!=t[j])
                {
                    
                }
                else
                {
                    j++;
                }
            }
            if(j==t.length())
            {
                cout<<"automaton";
            }
            else
            {
                cout<<"both";
            }
        }
    }
    
    return 0;
}