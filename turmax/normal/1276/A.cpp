#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    for(int cycle=0;cycle<q;++cycle)
    {
    string s;
    cin>>s;
    int i=0;
    int s1=0;
    vector <int> v;
    while(i<s.size())
    {
        if(i<s.size()-4 && s[i]=='t' &&  s[i+1]=='w' && s[i+2]=='o' && s[i+3]=='n' && s[i+4]=='e')
        {
            s.erase(s.begin()+i+2);
            v.push_back(i+2+s1);
            ++s1;
        }
        else if(i<s.size()-2 && s[i]=='o' && s[i+1]=='n' && s[i+2]=='e')
        {
            s.erase(s.begin()+i+1);
            v.push_back(i+1+s1);
            ++s1;
        }
        else if(i<s.size()-2 && s[i]=='t' && s[i+1]=='w' && s[i+2]=='o')
        {
            s.erase(s.begin()+i+1);
            v.push_back(i+1+s1);
            ++s1;
        }
        else
        {
            ++i;
        }
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]+1<<" ";
    }
    cout<<endl;
    }
    return 0;
}