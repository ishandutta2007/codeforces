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
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=3010;
//const ll Mod=1000000007;
const ll Mod=998244353;

char a[maxn];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",a);
    vector<vector<int>>ps=vector<vector<int>>(k,vector<int>());
    int tol = 0;
    int m=0;
    while(1)
    {
        vector<int>step;
        for(int i = 0;i<n-1;i++)
        {
            if (a[i]=='R'&&a[i+1]=='L')
            {
                step.push_back(i);
                tol++;
            }
        }
        if(step.empty())
            break;
        if(m>=k)
        {
            puts("-1");
            return 0;
        }
        ps[m++]=step;
        for (auto x:step)
            swap(a[x], a[x+1]);
    }
    if(k>tol)
    {
        puts("-1");
        return 0;
    }
    int fs=m-1;//
    for(int i=k-1;i>=0;i--)
    {
        if(ps[fs].empty())
            fs--;
        if(!ps[i].empty())
            break;
        ps[i]=vector<int>{ps[fs].back()};
        ps[fs].pop_back();
    }
    for(int i=0;i<k;i++)
    {
        printf("%d ",ps[i].size());
        for(auto x:ps[i])
            printf("%d ",x+1);
        puts("");
    }
    return 0;
}