#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> b;
vector <int> c;
const int p=(1e9+7);
int po[1500000];
vector <int> strhash(string s)
{
    vector <int> v;
    v.clear();
    v.push_back(0);
    for(int i=0;i<s.size();++i)
    {
        v.push_back((v[i]*1000+s[i])%p);
    }
    return v;
}
int decode1(int i)
{
    int x=b.size()-1;
    return ((b[x]-b[i]*po[x-i])%p);
}
int decode2(int i)
{
    return ((c[i])%p);
}
void change(int j)
{
    int x=c.size();
    int y=b[b.size()-1];
    for(int i=0;i<(x-j-1);++i)
    {
        b.push_back((y*po[i+1]+(c[i+j+1]-c[j]*po[i+1]))%p);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    po[0]=1;
    for(int i=1;i<1500000;++i)
    {
        po[i]=(po[i-1]*1000)%p;
    }
    int n;
    cin>>n;
    vector <string> a;
    string s;
    for(int i=0;i<n;++i)
    {
        cin>>s;
        a.push_back(s);
    }
    b=strhash(a[0]);
    string h=a[0];
    for(int i=1;i<n;++i)
    {
        c=strhash(a[i]);
        for(int j=min(b.size()-1,c.size()-1);j>=0;j--)
        {
            if((decode1(b.size()-1-j)-decode2(j))%p==0)
            {
                for(int k=j;k<a[i].size();++k)
                {
                    h+=a[i][k];
                }
                change(j);
                break;
            }
        }
    }
    cout<<h;
    return 0;
}