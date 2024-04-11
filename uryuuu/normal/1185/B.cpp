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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=1000005;
const ll Mod=1000000007;


struct node
{
    int x,len;
}a[maxn],b[maxn];

string s,t;
int main()
{
    sync;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s>>t;
        int ant=0,bnt=0;
        int pos;
        for(int i=0;i<s.length();i++)
        {
            a[ant].x=ch(s[i]);
            pos=i;
            int len=0;
            while(pos<s.length())
            {
                if(s[pos]==s[i])
                {
                    pos++;
                    len++;
                }
                else
                    break;
            }
            a[ant].len=len;
            i=pos-1;
            ant++;
        }
        for(int i=0;i<t.length();i++)
        {
            b[bnt].x=ch(t[i]);
            pos=i;
            int len=0;
            while(pos<t.length())
            {
                if(t[pos]==t[i])
                {
                    pos++;
                    len++;
                }
                else
                    break;
            }
            b[bnt].len=len;
            i=pos-1;
            bnt++;
        }
        if(ant!=bnt)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int f=0;
        for(int i=0;i<ant;i++)
        {
//            cout<<a[i].x<<' '<<a[i].len<<' '<<b[i].x<<' '<<b[i].len<<endl;
            if(a[i].x!=b[i].x||a[i].len>b[i].len)
            {
                f=1;
                break;
            }
        }
        if(f)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
        
    }
    
    return 0;
}