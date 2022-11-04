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
const int maxn=400005;
const ll Mod=1000000007;

pair<int,int>a[maxn];
int ans[maxn];

int main()
{
    sync;
    int t,n,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>l>>r;
            a[2*i-1]=make_pair(l,-i);
            a[2*i]=make_pair(r,i);
            ans[i]=0;
        }
        sort(a+1,a+2*n+1);
        multiset<int>s;
        int c=0;
        for(int i=1;i<=2*n;i++)
        {
            if(a[i].second<0)
                s.insert(-a[i].second);
            else
                s.erase(s.find(a[i].second));
            if(s.size()==0)
                c++;
            if(s.size()==1&&a[i].second>0&&a[i+1].second<0&&a[i+1].first>a[i].first)
                ans[*s.begin()]++;
            if(s.size()==1&&a[i].second<0&&a[i+1].second>0)
                ans[*s.begin()]--;
        }
        int da=-n;
        for(int i=1;i<=n;i++)
            da=max(da,ans[i]);
        cout<<c+da<<endl;
    }
    return 0;
}