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
const int maxn=300005;
const ll Mod=1e9+7;

string s,h;
int a[30];
int b[30];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        mm(a);
        mm(b);
        cin>>s>>h;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            a[int(s[i]-'a')+1]++;
        }
        int len=h.length();
        if(len<n)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int id=int(h[i]-'a')+1;
            if(b[id]<a[id])
            {
                sum++;
            }
            b[id]++;
        }
        if(sum==n)
        {
            cout<<"YES"<<endl;
            continue;
        }
        int l=0,r=n-1;
        while(r<len-1)
        {
            int id=int(h[l]-'a')+1;
            b[id]--;
            if(b[id]<a[id])
                sum--;
            l++;
            r++;
            id=int(h[r]-'a')+1;
            b[id]++;
            if(b[id]<=a[id])
                sum++;
            if(sum==n)
            {
                break;
            }
        }
        if(sum==n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}