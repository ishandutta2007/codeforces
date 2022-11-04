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
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;
using namespace std;
const ll p=998857459;



string s;

int main()
{
    sync;
    int n;
    cin>>n>>s;
    int L=0,R=0;
    int sum=0;
    int f=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            L++;
            sum++;
        }
        else
        {
            R++;
            sum--;
        }
        if(sum<0)
            f=1;
    }
    if(L!=R||sum!=0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    if(f==0)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    int p=0;
    sum=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            sum++;
        }
        else
        {
            sum--;
        }
        if(sum<0)
        {
            p=i+1;
            break;
        }
    }
    sum=0;
    for(int i=p;i<n;i++)
    {
        if(s[i]=='(')
        {
            sum++;
        }
        else
        {
            sum--;
        }
        if(sum<0)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
//    cout<<p<<endl;
    cout<<"Yes"<<endl;
    
    return 0;
}