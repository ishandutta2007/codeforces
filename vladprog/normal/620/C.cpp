#include<bits/stdc++.h>

#define read(a) cin>>a
#define write1(a) cout<<a<<'\n'
#define write2(a,b) cout<<a<<' '<<b<<'\n'

using namespace std;

int n,a;
vector<int> v;
set<int> s;

int main()
{
    read(n);
    v.push_back(0);
    for(int i=1;i<=n;i++)
    {
        read(a);
        if(s.count(a)==1)
        {
            s.clear(); //cout<<"s.clear()\n";
            v.push_back(i); //cout<<"v.push_back("<<i<<")\n";
        }
        else
        {
            s.insert(a); //cout<<"s.insert("<<a<<")\n";
        }
    }
    if(v.size()==1)
        write1(-1);
    else
    {
        write1(v.size()-1);
        v[v.size()-1]=n;
        for(int i=1;i<v.size();i++)
            write2(v[i-1]+1,v[i]);
    }
}