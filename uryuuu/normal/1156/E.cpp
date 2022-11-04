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
const ll Mod=998244353;
using namespace std;




int a[maxn],p[maxn],l[maxn],r[maxn];
stack<int>st;

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        while(!st.empty())
        {
            if(st.top()<a[i])
                st.pop();
            else
                break;
        }
        if(st.empty())
            l[i]=1;
        else
            l[i]=p[st.top()]+1;
        st.push(a[i]);
    }
     while(!st.empty())
         st.pop();
    for(int i=n;i>=1;i--)
    {
        while(!st.empty())
        {
            if(st.top()<a[i])
                st.pop();
            else
                break;
        }
        if(st.empty())
            r[i]=n;
        else
            r[i]=p[st.top()]-1;
        st.push(a[i]);
    }
    int sum=0;
    for(int i=2;i<n;i++)
    {
        int d=a[i];
        if(l[i]!=i&&r[i]!=i)
        {
            for(int j=l[i];j<i;j++)
            {
                if(p[d-a[j]]>i&&p[d-a[j]]<=r[i])
                    sum++;
            }
        }
    }
    cout<<sum<<endl;
    
    return 0;
}