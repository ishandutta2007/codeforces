#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> va,vb;
int main()
{
    for(int i=1;i<=100;++i)
    {
        bitset<14> tmp(0);
        for(int j=0;j<7;++j)
        {
            if(i & (1<<j)) tmp.set(2*j+1);
        }
        va.push_back(tmp.to_ulong());
    }
    for(int i=1;i<=100;++i)
    {
        bitset<14> tmp(0);
        for(int j=0;j<7;++j)
        {
            if(i & (1<<j)) tmp.set(2*j);
        }
        vb.push_back(tmp.to_ulong());
    }
    int reta,retb;
    cout<<"?";
    for(int i=0;i<100;++i) cout<<" "<<va[i];
    cout<<endl;
    cout.flush();
    cin>>reta;
    
    cout<<"?";
    for(int i=0;i<100;++i) cout<<" "<<vb[i];
    cout<<endl;
    cout.flush();
    cin>>retb;
    
    int ans=0;
    for(int i=0;i<14;++i)
    {
        if(i&1)
        {
            ans |= retb & (1<<i);
        }
        else
        {
            ans |= reta & (1<<i);
        }
    }
    cout<<"! "<<ans<<endl;
}