#include<iostream>
#include<map>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int prev=-1;
    map<char,int> m;
    m['0']=0;
    m['1']=1;
    m['2']=2;
    m['3']=3;
    m['4']=4;
    m['5']=5;
    m['6']=6;
    m['7']=7;
    m['8']=8;
    m['9']=9;
    
    for(int i=0;i<s.length();i++)
    {
        if(m[s[i]]%2==0 && m[s[i]]<m[s[s.length()-1]])
        {
            prev = i;
            break;
        }
        else if(m[s[i]]%2==0)
        {
            prev = i;
        }
    }
    if(prev==-1)
    {
        cout<<"-1";
    }
    else
    {
        int d;
        d = s[prev];
        s[prev] = s[s.length()-1];
        s[s.length()-1] = d;
        cout<<s;
    }
    return 0;
}