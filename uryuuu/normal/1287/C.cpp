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
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
const ll  Mod=998244353;
 
int a[105],q[105],w[105],v[105];
int c=0,d=0;
int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        v[a[i]]++;
    }
    for(int i=1;i<=n;i+=2)
    {
        if(v[i]==0)
            c++;
    }
    for(int i=2;i<=n;i+=2)
    {
        if(v[i]==0)
            d++;
    }
    if(c+d==n)
    {
        if(n==1)
            cout<<0<<endl;
        else
            cout<<1<<endl;
        return 0;
    }
    
    
    int l,r,lid,rid,qcnt=0,wcnt=0,len=0;
    int sum=0;
    int p=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]>0&&a[i-1]>0&&(a[i]%2!=a[i-1]%2))
            sum++;
    }
    while(p<n-1)
    {
        if(a[p]==0&&a[p-1])
        {
            len=0;
            l=p-1;
            while(p<n-1&&a[p]==0)
            {
                p++;
                len++;
            }
            r=p;
            if(a[r]==0)
                break;
            if(a[l]%2!=a[r]%2)
                sum++;
            else
            {
                if(a[l]%2==1)
                {
                    q[qcnt++]=len;
                }
                else
                    w[wcnt++]=len;
            }
            p--;
        }
        p++;
    }
    sort(q,q+qcnt);
    sort(w,w+wcnt);
    for(int i=0;i<qcnt;i++)
    {
        if(c<q[i])
        {
            sum+=2*(qcnt-i);
            break;
        }
        else
            c-=q[i];
    }
    for(int i=0;i<wcnt;i++)
    {
        if(d<w[i])
        {
            sum+=2*(wcnt-i);
            break;
        }
        else
            d-=w[i];
    }
    qcnt=0;
    wcnt=0;
    if(a[0]==0)
    {
        int pp=0;
        len=0;
        while(a[pp]==0)
        {
            pp++;
            len++;
        }
        if(a[pp]%2==1)
        {
            q[qcnt++]=len;
        }
        else
            w[wcnt++]=len;
    }
    if(a[n-1]==0)
    {
        int pp=n-1;
        len=0;
        while(a[pp]==0)
        {
            pp--;
            len++;
        }
        if(a[pp]%2==1)
        {
            q[qcnt++]=len;
        }
        else
            w[wcnt++]=len;
    }
    sort(q,q+qcnt);
    sort(w,w+wcnt);
    for(int i=0;i<qcnt;i++)
    {
        if(c<q[i])
        {
            sum+=(qcnt-i);
            break;
        }
        else
            c-=q[i];
    }
    for(int i=0;i<wcnt;i++)
    {
        if(d<w[i])
        {
            sum+=(wcnt-i);
            break;
        }
        else
            d-=w[i];
    }
    
    
    
    cout<<sum<<endl;
    return 0;
}