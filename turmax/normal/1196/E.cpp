#include <bits/stdc++.h>

using namespace std;
#define int long long
int cou(int a,vector <int> b)
{
    for(int i=0;i<b.size();++i)
    {
        if(a==b[i])
        {
            return 1;
        }
    }
    return 0;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    int b,w;
    for(int j=0;j<q;++j)
    {
    cin>>b>>w;
    if(b==w)
    {
        cout<<"YES"<<endl;
        int x=1e7;
        int y=1e7;
        for(int i=0;i<2*b;++i)
        {
            cout<<x<<" "<<y<<endl;
            x++;
        }
        continue;
    }
    if(b>w)
    {
        if(b>(3*w+1))
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            cout<<"YES"<<endl;
            set <pair<int,int> > v;
            int x=1e7;
            int y=1e7;
            for(int i=0;i<2*w;i+=2)
            {
                cout<<(x+i)<<" "<<y<<endl;
                cout<<(x+i+1)<<" "<<y<<endl;
                v.insert({x+i,y-1});
                v.insert({x+i,y+1});
            }
            v.insert({x+(2*w-1),y});
            v.insert({x-1,y});
            for(int i=0;i<(b-w);++i)
            {
                cout<<(*v.begin()).first<<" "<<(*v.begin()).second<<endl;
                v.erase(v.begin());
            }
            continue;
        }
    }
    else
    {
        swap(b,w);
        if(b>(3*w+1))
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            cout<<"YES"<<endl;
            set <pair<int,int> > v;
            int x=1e7-1;
            int y=1e7;
            for(int i=0;i<2*w;i+=2)
            {
                cout<<(x+i)<<" "<<y<<endl;
                cout<<(x+i+1)<<" "<<y<<endl;
                v.insert({x+i,y-1});
                v.insert({x+i,y+1});
            }
            v.insert({x+(2*w-1),y});
            v.insert({x-1,y});
            for(int i=0;i<(b-w);++i)
            {
                cout<<(*v.begin()).first<<" "<<(*v.begin()).second<<endl;
                v.erase(v.begin());
            }
            continue;
        }
    }
    }
    return 0;
}