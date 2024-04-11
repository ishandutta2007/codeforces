#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin>>n;
    int k;
    vector <int> a;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        a.push_back(k);
    }
    sort(a.begin(),a.end());
    int g=0;
    int h;
    vector <int> b;
    vector <int> c;
    int v1,v2;
    v1=-1;
    v2=-1;
    while(g<a.size())
    {
        h=a[g];
        if(h>v1)
        {
            b.push_back(h);
            v1=h;
        }
        else if(h>v2)
        {
            c.push_back(h);
            v2=h;
        }
        else
        {
            cout<<"NO";
            return 0;
        }
        ++g;
    }
    cout<<"YES"<<endl;
    reverse(c.begin(),c.end());
    cout<<b.size()<<endl;
    for(int i=0;i<b.size();++i)
    {
        cout<<b[i]<<" ";
    }
    cout<<""<<endl;
    cout<<c.size()<<endl;
    for(int i=0;i<c.size();++i)
    {
        cout<<c[i]<<" ";
    }
    cout<<""<<endl;
    return 0;
}