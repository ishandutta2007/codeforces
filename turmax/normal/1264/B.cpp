#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(d>(c+1))
    {
        cout<<"NO";
        return 0;
    }
    if(a>(b+1))
    {
        cout<<"NO";
        return 0;
    }
    if(abs(a+c-b-d)>1)
    {
        cout<<"NO";
        return 0;
    }
    if(d==(c+1) && (a!=0 || b!=0))
    {
        cout<<"NO";
        return 0;
    }
    if(a==(b+1) && (c!=0 || d!=0))
    {
        cout<<"NO";
        return 0;
    }
    if(a==(b+1))
    {
        cout<<"YES"<<endl;
        for(int i=0;i<b;++i)
        {
            cout<<0<<" "<<1<<" ";
        }
        cout<<0;
        return 0;
    }
    if(d==(c+1))
    {
        cout<<"YES"<<endl;
        for(int i=0;i<c;++i)
        {
            cout<<3<<" "<<2<<" ";
        }
        cout<<3;
        return 0;
    }
    if((a+c)>=(b+d))
    {
        cout<<"YES"<<endl;
        while(a>0)
        {
            cout<<0<<" ";
            if(b>0)
            {
                cout<<1<<" ";
            }
            a--;
            b--;
        }
        if(c>0)
        {
        cout<<2<<" ";
        c--;
        }
        while(b>0)
        {
            cout<<1<<" ";
            if(c>0)
            {
                cout<<2<<" ";
            }
            b--;
            c--;
        }
        if(d>0)
        {
        cout<<3<<" ";
        d--;
        }
        while(c>0)
        {
            cout<<2<<" ";
            if(d>0)
            {
                cout<<3<<" ";
            }
            c--;
            d--;
        }
    }
    else
    {
        cout<<"YES"<<endl;
        while(d>0)
        {
            cout<<3<<" ";
            if(c>0)
            {
                cout<<2<<" ";
            }
            d--;
            c--;
        }
        if(b>0)
        {
        cout<<1<<" ";
        b--;
        }
        while(c>0)
        {
            cout<<2<<" ";
            if(b>0)
            {
                cout<<1<<" ";
            }
            c--;
            b--;
        }
        if(a>0)
        {
        cout<<0<<" ";
        a--;
        }
        while(b>0)
        {
            cout<<1<<" ";
            if(a>0)
            {
                cout<<0<<" ";
            }
            b--;
            a--;
        }
    }
    return 0;
}