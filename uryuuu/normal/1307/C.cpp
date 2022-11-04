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
const int maxn=100005;
const ll Mod=1000000007;

ll a[maxn][30];

int get(char c)
{
    return int(c-'a')+1;
}

ll mp[30][30];
ll b[30];

string s;
int main()
{
    sync;
    cin>>s;
    int n=s.length();
    int id;
    ll zd=0ll;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<28;j++)
        {
            a[i+1][j]=a[i][j];
        }
        id=get(s[i]);
        b[id]++;
        zd=max(zd,b[id]);
        for(int j=1;j<=26;j++)
        {
            mp[j][id]+=a[i+1][j];
            zd=max(mp[j][id],zd);
        }
        a[i+1][id]++;
        
    }
    cout<<zd<<endl;
    return 0;
}