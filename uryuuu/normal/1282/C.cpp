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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
int s[maxn];
struct node
{
    int f,d,g;
}c[maxn];
bool cmp(node a,node b)
{
    if(a.g==b.g)
        return a.f>b.f;
    return a.g<b.g;
}
int main()
{
    sync;
    int n,m,a,b,t;
    cin>>m;
    while(m--)
    {
        cin>>n>>t>>a>>b;
        int aa=0,bb=0;
        for(int i=0;i<n;i++)
        {
            cin>>c[i].f;
        }
        for(int i=0;i<n;i++)
        {
            cin>>c[i].g;
            s[i]=c[i].g;
            if(c[i].f==0)
            {
                c[i].d=c[i].g-a;
                aa++;
            }
            else
            {
                c[i].d=c[i].g-b;
                bb++;
            }
        }
        sort(s,s+n);
        sort(c,c+n,cmp);
        int ss=0;
        ll sum=0;
        s[n]=t;
//        for(int i=0;i<n;i++)
//            cout<<c[i].d<<' ';
//        cout<<endl;
        if(sum<s[0])
        {
            int dd=s[0]-sum-1;
            if(dd>0)
            {
            ss+=min(dd/a,aa);
            if(aa*a<dd)
                ss+=min((dd-aa*a)/b,bb);
            }
        }
        for(int i=0;i<n;i++)
        {
//            cout<<c[i].d<<' ';
            if(sum>t)
            {
//                cout<<int(c[i].d<sum)<<int(c[i].d<0)<<int(sum>t)<<' ';
                break;
            }
            if(c[i].f==0)
            {
                sum+=a;
                aa--;
            }
            else
            {
                sum+=b;
                bb--;
            }
//            cout<<sum<<' '<<s[i+1]<<' ';
            if(i<n-1)
                if(sum<s[i+1])
                {
                    ss=max(ss,i+1);
                    int sss=0;
                    int dd=s[i+1]-sum-1;
                    sss+=min(dd/a,aa);
                    if(aa*a<dd)
                        sss+=min((dd-aa*a)/b,bb);
                    ss=max(ss,i+1+sss);
                }
            if(i==n-1)
                if(sum<=s[i+1])
                    ss=max(ss,i+1);
//            cout<<sum<<' ';
//            if(i==n-1)
//            {
//                if(sum<t)
//                    if(t>s[n-1])
//                        ss=n;
//            }
        }
        cout<<ss<<endl;
    }
    return 0;
}