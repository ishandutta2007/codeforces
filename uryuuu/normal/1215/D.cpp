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
#define ch(a) (int(a-'0'))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=4000050;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;


string s;

int main()
{
    sync;
    int n;
    cin>>n;
    cin>>s;
    int L=0,R=0;
    int l=0,r=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='?')
        {
            if(i<n/2)
                l++;
            else
                r++;
        }
        else
        {
            if(i<n/2)
                L+=ch(s[i]);
            else
                R+=ch(s[i]);
        }
    }
//    cout<<L<<' '<<R<<' '<<l<<' '<<r<<endl;
    if(L>=R)
    {
        swap(L,R);
        swap(l,r);
    }
    int d=min(l,r);
    l-=d;
    r-=d;
    if(l==0)
    {
        if(L<R)
            cout<<"Monocarp"<<endl;
        else if(L==R)
        {
            if(r==0)
                cout<<"Bicarp"<<endl;
            else
                cout<<"Monocarp"<<endl;
        }
        return 0;
    }
    if(L+l/2*9<R||L+l/2*9>R)
        cout<<"Monocarp"<<endl;
    else
        cout<<"Bicarp"<<endl;
    
    
    
    return 0;
}