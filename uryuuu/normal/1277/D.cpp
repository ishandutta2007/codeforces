#include<iostream>
#include<stdio.h>
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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int maxn=200005;
const ll Mod=1000000007;

string s[maxn];
int a[maxn],b[maxn];
map<string,int>mp;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int b1=0,b0=0,e0=0,e1=0;
        mp.clear();
        int cnt=0;
        int c=0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            mp[s[i]]++;
        }
        int f=0;
        for(int i=0;i<n;i++)
        {
            int len=s[i].length();
            if(s[i][0]=='1')
                b1++;
            else
                b0++;
            if(s[i][len-1]=='1')
                e1++;
            else
                e0++;
            if(s[i][0]==s[i][len-1])
                continue;
            f=1;
            string ss=s[i];
            reverse(ss.begin(),ss.end());
            if(mp[ss])
                continue;
            a[cnt++]=i;
        }
        if(f==0)
        {
            if(b1==n||b0==n)
                cout<<0<<endl<<endl;
            else
                cout<<-1<<endl;
            continue;
        }
        if((e0-b0)==(b1-e1)&&abs(e0-b0)<=1)
        {
            cout<<0<<endl<<endl;
            continue;
        }
        f=0;
        for(int i=0;i<cnt;i++)
        {
            int id=a[i];
            if(s[id][0]=='1')
            {
                if(b1>=e1)
                {
                    b[c++]=id;
                    b1--;
                    b0++;
                    e1++;
                    e0--;
                }
            }
            else
            {
                if(b0>=e0)
                {
                    b[c++]=id;
                    b0--;
                    b1++;
                    e0++;
                    e1--;
                }
            }
            if((e0-b0)==(b1-e1)&&abs(e0-b0)<=1)
            {
                f=1;
                break;
            }
        }
        if(f)
        {
            cout<<c<<endl;
            for(int i=0;i<c;i++)
                cout<<b[i]+1<<' ';
            cout<<endl;
        }
        else
            cout<<-1<<endl;
    }
    return 0;
}