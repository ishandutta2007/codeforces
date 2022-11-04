//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
#include<unordered_map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;

int s[maxn];
int main()
{
    sync;
    int a,b,c,d,x,y,z,n;
    cin>>a>>b>>c>>d;
    if(c<d)
    {
        if(c==d-1&&a==0&&b==0)
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=c;i++)
                cout<<3<<' '<<2<<' ';
            cout<<3<<endl;
            return 0;
        }
        cout<<"NO"<<endl;
        return 0;
    }
    n=0;
    if(a>0)
    {
        b-=(a-1);
        n=a-1;   //10;
    }
    z=d;
    c-=d;//32
    if(b<c)
    {
        if(b==c-1&&a==0)
        {
            cout<<"YES"<<endl;
            cout<<2<<' ';
            for(int i=1;i<=b;i++)
                cout<<1<<' '<<2<<' ';
            for(int i=1;i<=z;i++)
                cout<<3<<' '<<2<<' ';
            cout<<endl;
            return 0;
        }
        cout<<"NO"<<endl;
        return 0;
    }
    b-=c;
    y=c;  //12
    x=b;  //1;
//    cout<<x<<y<<z<<n<<endl;
    if(x<0||x>2)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(x<0||x>2)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    
    if(x==2)
    {
        if(a==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        cout<<"YES"<<endl;
        cout<<1<<' '<<0<<' ';
        for(int i=1;i<=n;i++)
            cout<<1<<' '<<0<<' ';
        for(int i=1;i<=y;i++)
            cout<<1<<' '<<2<<' ';
        cout<<1<<' ';
        for(int i=1;i<=z;i++)
            cout<<2<<' '<<3<<' ';
        cout<<endl;
    }
    if(x==1)
       {
           cout<<"YES"<<endl;
           for(int i=1;i<=z;i++)
               cout<<3<<' '<<2<<' ';
           for(int i=1;i<=y;i++)
               cout<<1<<' '<<2<<' ';
           for(int i=1;i<=n;i++)
               cout<<1<<' '<<0<<' ';
           cout<<1<<' ';
           if(a>0)
               cout<<0<<endl;
           cout<<endl;
       }
    if(x==0)
    {
        if(a==0)
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=z;i++)
                    cout<<3<<' '<<2<<' ';
                for(int i=1;i<=y;i++)
                    cout<<1<<' '<<2<<' ';
                cout<<endl;
            return 0;
        }
        if(z>0&&y==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        cout<<"YES"<<endl;
        cout<<0<<' ';
        for(int i=1;i<=y;i++)
            cout<<1<<' '<<2<<' ';
//        cout<<1<<' ';
        for(int i=1;i<=z;i++)
            cout<<3<<' '<<2<<' ';
        for(int i=1;i<=n;i++)
            cout<<1<<' '<<0<<' ';
        cout<<endl;
    }
    
    
    return 0;
}