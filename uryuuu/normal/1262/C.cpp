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
const int maxn=2050;
int a[maxn];
string s;
struct node
{
    int l,r;
}b[4005];
int main()
{
    sync;
    int n,t,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                a[i+1]=1;
            else
                a[i+1]=0;
        }
        int cnt=0;
        int r=0;
        int dd=0;
        int g=0;
        for(int i=1;i<=n;i++)
        {
            g=i%2;
            if(i>=2*k&&i<n)
                g=(i+1)%2;
//            cout<<g<<' ';
            if(a[i]!=g)
            {
                r=i;
//                cout<<i<<' '<<a[i]<<endl;
                while(r<=n)
                {
                    if(a[r]==g)
                        break;
                    r++;
                }
//                if(r==)
                reverse(a+i,a+r+1);
                b[cnt].l=i;
                b[cnt++].r=r;
            }
            
        }
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++)
        {
            cout<<b[i].l<<' '<<b[i].r<<endl;
        }
    }
    return 0;
}