#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k,g;
    cin>>n>>k;
    vector <int> a;
    map <int,int> v;
    for(int i=0;i<n;++i)
    {
        v[i+1]=0;
    }
    for(int i=0;i<k;++i)
    {
        cin>>g;
        a.push_back(g);
    }
    int i;
    g=n;
    string s="";
    for(int p=0;p<k;++p)
    {
        i=a[p];
        if(v[i]==0)
        {
            g--;
        }
        ++v[i];
        if(g==0)
        {
            s+="1";
            for(int k=1;k<(n+1);++k)
            {
                v[k]-=1;
                if(v[k]==0)
                {
                    ++g;
                }
            }
        }
        else{
            s+="0";
        }
    }
    cout<<s;
    return 0;
}