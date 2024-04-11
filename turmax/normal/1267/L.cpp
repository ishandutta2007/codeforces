#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <bool> used;
vector <string> b;
string s;
int z;
int g;
int n,l,k;
void go(int x)
{
    while(b[x].size()<l)
    {
        if(used[g])
        {
            ++g;
        }
        else
        {
            used[g]=true;
            b[x]+=s[g];
        }
    }
}
void to(int symb,int x)
{
    used[symb]=true;
    b[x]+=s[symb];
    while(true)
    {
        if(used[g])
        {
            ++g;
        }
        else
        {
            break;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    g=0;
    cin>>n>>l>>k;
    b.resize(n);
    z=n*l;
    used.resize(z);
    for(int i=0;i<z;++i)
    {
        used[i]=false;
    }
    cin>>s;
    sort(s.begin(),s.end());
    vector <int> v;
    for(int i=0;i<k;++i)
    {
        v.push_back(i);
    }
    int o=k;
    int y;
    for(int i=0;i<l;++i)
    {
        //cout<<o<<endl;
        for(int j=k-o;j<k;++j)
        {
            to(g,j);
        }
        y=0;
        for(int j=(k-o);j<k;++j)
        {
            if(b[j][b[j].size()-1]==b[k-1][b[k-1].size()-1])
            {
                //cout<<" yhtgrfedwq "<<endl;
               ++y;
            }
        }
        o=y;
    }
    for(int i=0;i<n;++i)
    {
        go(i);
    }
    for(int i=0;i<n;++i)
    {
        cout<<b[i]<<endl;
    }
    return 0;
}