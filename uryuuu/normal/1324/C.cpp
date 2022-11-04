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
const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
 

string s;

int main()
{
    sync;
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.length();
        int pos=-1;
        int d=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R')
            {
                d=max(d,i-pos);
                pos=i;
            }
        }
        d=max(d,n-pos);
        cout<<d<<endl;
    }
    return 0;
}