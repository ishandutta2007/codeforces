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
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216") //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;


set<pii>A,B;
int x[maxn];
int ans[maxn][2];

void print(int rd,int id)
{
    if(rd==0)
        return;
    int pre=ans[rd][id];
    print(pre,1-id);
    for(int i=pre+1;i<=rd;i++)
    {
        cout<<id<<' ';
    }
}

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int al,ar,bl,br;
    cin>>x[1]>>al>>ar>>bl>>br;
    if(al<=x[1]&&x[1]<=ar&&bl==0)
        B.insert(mkp(0,0));
    if(bl<=x[1]&&x[1]<=br&&al==0)
        A.insert(mkp(0,0));
    
    int fa,fb;
    for(int i=2;i<=n;i++)
    {
        cin>>x[i]>>al>>ar>>bl>>br;
        fa=A.size();
        fb=B.size();
    
        if(fa)
            B.insert(mkp(x[i-1],i-1));
        
        if(fb)
            A.insert(mkp(x[i-1],i-1));
        
        if(al<=x[i]&&x[i]<=ar)
        {
            while(B.size())
            {
                if((*B.begin()).first>=bl)
                    break;
                B.erase(*B.begin());
            }
            while(B.size())
            {
                if((*B.rbegin()).first<=br)
                    break;
                B.erase(*B.rbegin());
            }
        }
        else
            B.clear();
        
        if(bl<=x[i]&&x[i]<=br)
        {
            while(A.size())
            {
                if((*A.begin()).first>=al)
                    break;
                A.erase(*A.begin());
            }
            while(A.size())
            {
                if((*A.rbegin()).first<=ar)
                    break;
                A.erase(*A.rbegin());
            }
        }
        else
            A.clear();
        
        if(B.size())
            ans[i][0]=(*B.begin()).second;
        if(A.size())
            ans[i][1]=(*A.begin()).second;
    }
    
    if(A.size())
    {
        cout<<"Yes"<<endl;
        print(n,1);
        cout<<endl;
    }
    else if(B.size())
    {
        cout<<"Yes"<<endl;
        print(n,0);
        cout<<endl;
    }
    else
        cout<<"No"<<endl;
    
    return 0;
}