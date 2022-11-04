#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<set>
#include<queue>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
vector<int>v[maxn];

int main()
{
    int t;
    cin>>t;
    int n;
    int m,p;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            v[i].clear();
        }
        int m,p;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&m,&p);
            v[m].push_back(p);
        }
        ll sum=0;
        int have=0,res=n;
        priority_queue<int ,vector<int>,greater<int>>q;
        for(int i=n-1;i>=0;i--)
        {
            res-=v[i].size();
            for(auto p:v[i])
                q.push(p);
            while(have+res<i)
            {
                sum+=q.top();q.pop();
                have++;
            }
        }
        cout<<sum<<endl;
    }
}