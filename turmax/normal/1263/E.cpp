#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1000005;
int t[4*maxn];
int mini[4*maxn];
int maxi[4*maxn];
void to(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=r || tr<=l)
    {
        return;
    }
    if(tr<=r && tl>=l)
    {
        mini[node]+=val;
        maxi[node]+=val;
        t[node]+=val;
        return;
    }
    to(2*node+1,tl,(tl+tr)/2,l,r,val);
    to(2*node+2,(tl+tr)/2,tr,l,r,val);
    mini[node]=min(mini[2*node+1],mini[2*node+2])+t[node];
    maxi[node]=max(maxi[2*node+1],maxi[2*node+2])+t[node];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int t=0;
    int ans=0;
    bool f=true;
    int curr=0;
    string u;
    for(int i=0;i<1000001;++i)
    {
        u+=' ';
    }
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='(')
        {
            if(u.size()<=curr)
            {
                u+='(';
                ++t;
                to(0,0,maxn,curr,maxn,1);
            }
            else if(u[curr]=='(')
            {
            }
            else if(u[curr]==')')
            {
                to(0,0,maxn,curr,maxn,2);
                t+=2;
            }
            else
            {
                to(0,0,maxn,curr,maxn,1);
                t++;
            }
            u[curr]='(';
        }
        else if(s[i]==')')
        {
            if(u.size()<=curr)
            {
                u+=')';
                --t;
                to(0,0,maxn,curr,maxn,-1);
            }
            else if(u[curr]==')')
            {
            }
            else if(u[curr]=='(')
            {
                to(0,0,maxn,curr,maxn,-2);
                t-=2;
            }
            else
            {
                to(0,0,maxn,curr,maxn,-1);
                t--;
            }
            u[curr]=')';
        }
        else if(s[i]=='L')
        {
            if(curr!=0)
            {
                --curr;
            }
        }
        else if(s[i]=='R')
        {
            ++curr;
        }
        else
        {
            if(u.size()<=curr)
            {
                u+=' ';
            }
            if(u[curr]==')')
            {
                ++t;
                to(0,0,maxn,curr,maxn,1);
            }
            else if(u[curr]=='(')
            {
                --t;
                to(0,0,maxn,curr,maxn,-1);
            }
            u[curr]=s[i];
        }
        if(mini[0]<0 || t!=0)
        {
            cout<<(-1)<<" ";
        }
        else
        {
            cout<<maxi[0]<<" ";
        }
        //cout<<u<<endl;
    }
    return 0;
}