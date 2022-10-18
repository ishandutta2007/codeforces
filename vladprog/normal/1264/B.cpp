#include<bits/stdc++.h>

typedef long long ll;
#define int ll

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(c==0&&d==0)
    {
        if(abs(a-b)>1)
            cout<<"NO",exit(0);
        cout<<"YES\n";
        int last=(a>b?1:0);
        while(true)
        {
            if(last==1)
                if(a)
                    cout<<0<<" ",a--;
                else
                    break;
            else
                if(b)
                    cout<<1<<" ",b--;
                else
                    break;
            last=1-last;
        }
        exit(0);
    }
    if(a==0&&b==0)
    {
        if(abs(c-d)>1)
            cout<<"NO",exit(0);
        cout<<"YES\n";
        int last=(c>d?3:2);
        while(true)
        {
            if(last==2)
                if(d)
                    cout<<3<<" ",d--;
                else
                    break;
            else
                if(c)
                    cout<<2<<" ",c--;
                else
                    break;
            last=5-last;
        }
        exit(0);
    }
    if(b-a<0)
        cout<<"NO",exit(0);
    if(c-d<0)
        cout<<"NO",exit(0);
    vector<int> l;
    while(true)
        if(l.empty()||l.back()==0)
            if(b)
                l.push_back(1),b--;
            else
                break;
        else
            if(a)
                l.push_back(0),a--;
            else
                break;
    vector<int> r;
    while(true)
        if(r.empty()||r.back()==3)
            if(c)
                r.push_back(2),c--;
            else
                break;
        else
            if(d)
                r.push_back(3),d--;
            else
                break;
    if(b<c&&l.back()==1)
        b++,l.pop_back();
    if(c<b&&r.back()==2)
        c++,r.pop_back();
    if(b!=c)
        cout<<"NO",exit(0);
    vector<int> m;
    while(b-->0)
        m.push_back(2),
        m.push_back(1);
    reverse(l.begin(),l.end());
    cout<<"YES\n";
    for(int x:l)
        cout<<x<<" ";
    for(int x:m)
        cout<<x<<" ";
    for(int x:r)
        cout<<x<<" ";
}