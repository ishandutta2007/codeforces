#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    map<char,int> m;
    for(char c:s)
        m[c]++;
    if(m.size()<2||m.size()>4)
    {
        cout<<"No";
        exit(0);
    }
    if(m.size()==2)
        for(auto p:m)
            if(p.second<2)
            {
                cout<<"No";
                exit(0);
            }
    if(m.size()==3)
    {
        bool ok=false;
        for(auto p:m)
            if(p.second>=2)
                ok=true;
        if(!ok)
        {
            cout<<"No";
            exit(0);
        }
    }
    cout<<"Yes";
}