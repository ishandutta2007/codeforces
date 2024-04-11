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
const int maxn=400005;

int a[maxn],b[maxn],s[maxn];
int au,ag,bz,pos,l,r,mid,ss,cnt;

int pd(int mid)
{
    au=s[mid];
    if(ss-au>au*2)
       pos=upper_bound(s+1,s+cnt+1,au+au)-s;
    else
    {
        return 0;
    }
    ag=s[pos]-au;
    if(ss-au-ag>au)
        pos=lower_bound(s+1,s+cnt+1,ss/2+1)-s;
    else
    {
        return 0;
    }
    bz=s[pos-1]-au-ag;
    if(au+bz+ag>ss/2||bz<=au)
    {
        return 0;
    }
    return 1;
}


int main()
{
//    sync;
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            s[i]=0;
            b[i]=0;
        }
        cnt=1;
        for(int i=1;i<=n;i++)
        {
            if(i==1||a[i]==a[i-1])
            {
                b[cnt]++;
            }
            else
                b[++cnt]=1;
        }
        s[0]=0;
        for(int i=1;i<=cnt;i++)
        {
            s[i]=s[i-1]+b[i];
        }
        ss=s[cnt];
        l=1;r=cnt;
//        for(int i=1;i<=cnt;i++)
//            cout<<b[i]<<' ';
//        cout<<endl;
        while(l<r)
        {
            mid=(l+r)/2;
            if(pd(mid))
                l=mid+1;
            else
                r=mid;
        }
        if(pd(l))
        {
            au=s[l];
            pos=upper_bound(s+1,s+cnt+1,au+au)-s;
            ag=s[pos]-au;
            pos=lower_bound(s+1,s+cnt+1,ss/2+1)-s;
            bz=s[pos-1]-au-ag;
            cout<<au<<' '<<ag<<' '<<bz<<endl;
        }
        else
        {
            if(l>1)
            {
                l--;
                if(pd(l))
                {
                    au=s[l];
                    pos=upper_bound(s+1,s+cnt+1,au+au)-s;
                    ag=s[pos]-au;
                    pos=lower_bound(s+1,s+cnt+1,ss/2+1)-s;
                    bz=s[pos-1]-au-ag;
                    cout<<au<<' '<<ag<<' '<<bz<<endl;
                }
                else
                    cout<<0<<' '<<0<<' '<<0<<endl;
            }
            else
                cout<<0<<' '<<0<<' '<<0<<endl;
        }
        
    }
    return 0;
}