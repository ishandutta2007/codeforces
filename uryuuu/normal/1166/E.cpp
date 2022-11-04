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
//#include<unordered_map>
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
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;


bitset<10005>b;
vector<bitset<10005>>v;

int main()
{
    sync;
    int m,n;
    cin>>m>>n;
    int k;
    int x;
    for(int i=1;i<=m;i++)
    {
        cin>>k;
        b.reset();
        rep(j,1,k)
        {
            cin>>x;
            b.set(x);
        }
        v.push_back(b);
    }
    
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(!(v[i]&v[j]).any())
            {
                cout<<"impossible"<<endl;
                return 0;
            }
        }
    }
    
    cout<<"possible"<<endl;
    
    
    return 0;
}