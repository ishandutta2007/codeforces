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
const int maxn=1000005;
const ll Mod=1000000007;

vector<pair<int,ll>>st;
double ans[maxn];
ll n,t,a[maxn];


int main()
{
    sync;
    cin>>n;
    ll sum=0;
    st.push_back(make_pair(0,0ll));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        pair<int,ll>p=make_pair(i,sum);
        t=st.size()-1;
        while(t>0&&(st[t].first-st[t-1].first)*(p.second-st[t].second)<=(st[t].first-p.first)*(st[t-1].second-st[t].second))
        {
            st.pop_back();
            t--;
        }
        st.push_back(p);
    }
    int last=1;
    for(auto p:st)
    {
        double sum=0.0;
        for(int i=last;i<=p.first;i++)
            sum+=a[i];
        for(int i=last;i<=p.first;i++)
            ans[i]=sum/(p.first-last+1);
        last=p.first+1;
    }
    for(int i=1;i<=n;i++)
        printf("%.10f\n",ans[i]);
    return 0;
}