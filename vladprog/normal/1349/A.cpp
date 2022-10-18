#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    map<int,pair<int,pii>> m;
    #define key x
    #define val y
    #define cnt x
    #define mn y
    #define fir x
    #define sec y
    for(int _=0;_<n;_++)
    {
        int a;
        cin>>a;
        for(int d=2;d*d<=a;d++)
            if(a%d==0)
            {
                int k=0;
                while(a%d==0)
                    k++,
                    a/=d;
                auto&p=m[d];
                if(!p.cnt)
                    p={0,{1e9,1e9}};
                p.cnt++;
                if(k<p.mn.sec)
                    p.mn.sec=k;
                if(p.mn.fir>p.mn.sec)
                    swap(p.mn.fir,p.mn.sec);
            }
        if(a>1)
        {
            int d=a;
            int k=1;
            auto&p=m[d];
            if(!p.cnt)
                p={0,{1e9,1e9}};
            p.cnt++;
            if(k<p.mn.sec)
                p.mn.sec=k;
            if(p.mn.fir>p.mn.sec)
                swap(p.mn.fir,p.mn.sec);
        }
    }
    int ans=1;
    for(auto p:m)
    {
        int pw=(p.val.cnt==n?p.val.mn.sec:p.val.cnt==n-1?p.val.mn.fir:0);
        int d=p.key;
        while(pw--)
            ans*=d;
    }
    cout<<ans;
}