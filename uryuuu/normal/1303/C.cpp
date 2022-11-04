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
const int maxn=100005;
const ll Mod=1000000007;


string s;

int get(char x)
{
    return int(x-'a')+1;
}

int a[1000];
int v[40];
int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        mm(a);
        mm(v);
        int pos=300;
        int n=s.length(),id;
        a[pos]=get(s[0]);
        int f=0;
        v[get(s[0])]=1;
        for(int i=1;i<n;i++)
        {
            id=get(s[i]);
            if(a[pos-1]==id)
            {
                pos--;
                continue;
            }
            if(a[pos+1]==id)
            {
                pos++;
                continue;
            }
            if(a[pos+1]&&a[pos+1]!=id)
            {
                if(a[pos-1]&&a[pos-1]!=id)
                {
                    f=1;
                    break;
                }
                pos--;
                if(v[id])
                {
                    f=1;
                    break;
                }
                a[pos]=id;
                v[id]=1;
                continue;
            }
            pos++;
            if(v[id])
            {
                f=1;
                break;
            }
            a[pos]=id;
            v[id]=1;
            a[pos]=id;
        }
        if(f)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        int l=99999,r=1;
        for(int i=0;i<700;i++)
        {
            if(a[i])
            {
                l=min(l,i);
                r=max(r,i);
            }
        }
        for(int i=l;i<=r;i++)
            cout<<char('a'+a[i]-1);
        for(int i=1;i<=26;i++)
        {
            if(v[i]==0)
                cout<<char('a'+i-1);
        }
        cout<<endl;
    }
    return 0;
}