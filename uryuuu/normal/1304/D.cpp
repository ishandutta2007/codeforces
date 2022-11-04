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

string s;
int b[maxn]; //<
int a[maxn]; //>
int c[maxn];
int d[maxn];


int main()
{
    sync;
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        cin>>s;
        int zd=0;
        a[n]=0;
        for(int i=n-2;i>=0;i--)
        {
            a[i+1]=a[i+2];
            if(s[i]=='>')
                a[i+1]++;
            else
                a[i+1]=0;
        }
        int pos=1;
        int len,l,r;
        while(pos<=n)
        {
            len=a[pos];
            l=zd+1;
            r=zd+1+len;
            zd=r;
            for(int i=0;i<=len;i++,pos++)
            {
                d[pos]=r-i;
            }
        }
        b[1]=0;
        for(int i=0;i<n-1;i++)
        {
            b[i+2]=b[i+1];
            if(s[i]=='<')
                b[i+2]++;
            else
                b[i+2]=0;
        }
        pos=n;
        zd=0;
        while(pos>=1)
        {
            len=b[pos];
            l=zd+1;
            r=zd+1+len;
            zd=r;
            for(int i=0;i<=len;i++,pos--)
            {
                c[pos]=r-i;
            }
        }

        for(int i=1;i<=n;i++)
            cout<<c[i]<<' ';
        cout<<endl;
        
        for(int i=1;i<=n;i++)
            cout<<d[i]<<' ';
        cout<<endl;
        
    }
    return 0;
}