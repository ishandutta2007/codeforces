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
#define lb(x) (x&(-x));
#define add(a,b) ((a+=(b))%=Mod)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=1000005;
const ll Mod=1000000007;

string s,t;

int v[30];

int main()
{
    sync;
    int T;
    cin>>T;
    while(T--)
    {
        mm(v);
        cin>>s>>t;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            v[int(s[i]-'a')+1]++;
        }
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(v[int(t[i]-'a')+1])
                 {
                     f=1;
                     break;
                 }
        }
        if(f)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}