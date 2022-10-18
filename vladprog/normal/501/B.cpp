#include<bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin>>q;
    map<string,string> a;
    for(int i=0;i<q;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        map<string,string>::iterator it=a.find(s1),e=a.end();
        if(it==e)
            a.insert(pair<string,string>(s2,s1));
        else
        {
            string s0=it->second;
            a.erase(it);
            a.insert(pair<string,string>(s2,s0));
        }
    }
    cout<<a.size()<<"\n";
    for(map<string,string>::iterator it=a.begin();it!=a.end();it++)
        cout<<it->second<<" "<<it->first<<"\n";
}