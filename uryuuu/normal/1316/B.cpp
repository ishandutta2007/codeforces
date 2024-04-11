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
const int maxn=250005;
const ll Mod=1000000007;



string s,s1,ss;

int main()
{
    sync;
    int n,t;
    cin>>t;
    ll m;
    while(t--)
    {
        cin>>n;
        cin>>s;
        int k=1;
        ss=s;
        for(int i=1;i<=n-1;i++)
        {
            s1="";
            for(int j=i;j<n;j++)
                s1+=s[j];
            if((n-i-1)%2)
                for(int j=0;j<i;j++)
                    s1+=s[j];
            else
                for(int j=i-1;j>=0;j--)
                    s1+=s[j];
//            cout<<s1<<endl;
            if(s1<ss)
            {
                ss=s1;
                k=i+1;
            }
        }
        cout<<ss<<endl;
        cout<<k<<endl;
    }
    
    
    
    return 0;
}