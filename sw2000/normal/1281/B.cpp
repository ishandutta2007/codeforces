#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=5e3+10;
string a,b;

void solve()
{
    int id=a.size()-1,pre[maxn];
    for(int i=id;~i;i--)
    {
        if(a[i]<a[id])id=i;
        pre[i]=id;
    }
//    for(int i=0;i<a.size();i++)
//        cout<<pre[i]<<' ';
//    cout<<endl;

    for(int i=0;i<min(a.size(),b.size());i++)
    {
        id=pre[i];
        if(a[id]<b[i])
        {
            swap(a[i],a[id]);
            cout<<a<<endl;
            return;
        }
        if(a[id]>b[i])
        {
            cout<<"---"<<endl;
            return;
        }
        if(a[i]!=b[i])
        {
            swap(a[i],a[id]);
            if(a<b)cout<<a<<endl;
            else cout<<"---"<<endl;
            return;
        }
    }
    if(a<b)cout<<a<<endl;
    else cout<<"---"<<endl;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        solve();
    }
    return 0;
}