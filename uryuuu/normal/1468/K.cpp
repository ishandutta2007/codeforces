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
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;


string s;
int nx,ny;
int n;
map<pii,int>mp;

int check(int x,int y,int id)
{
    for(int i=id;i<n;i++)
    {
        if(s[i]=='L')
        {
            x--;
            if(x==nx&&y==ny)
                x++;
        }
        else if(s[i]=='R')
        {
            x++;
            if(x==nx&&y==ny)
                x--;
        }
        else if(s[i]=='U')
        {
            y++;
            if(x==nx&&y==ny)
                y--;
        }
        else
        {
            y--;
            if(x==nx&&y==ny)
                y++;
        }
    }
    if(x==0&&y==0)
        return 1;
    return 0;
}


int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        cin>>s;
        int x=0,y=0;
        n=s.length();
//        cout<<n<<endl;
        int f=0;
        for(int i=0;i<n;i++)
        {
            nx=x;
            ny=y;
            if(s[i]=='L')
                nx--;
            else if(s[i]=='R')
                nx++;
            else if(s[i]=='U')
                ny++;
            else
                ny--;
            if(mp[mkp(nx,ny)]==0)
            {
                if(check(x,y,i+1))
                {
                    f=1;
                    break;
                }
                mp[mkp(nx,ny)]=1;
            }
            x=nx;
            y=ny;
        }
   
        
        if(f)
        {
            cout<<nx<<' '<<ny<<endl;
        }
        else
        {
            cout<<0<<' '<<0<<endl;
        }
    }
    
    return 0;
}