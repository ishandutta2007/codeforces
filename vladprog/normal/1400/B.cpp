#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3010;

int a[N];
int cnt[N][N];

int solve()
{
    int p,f,cnt_s,cnt_w,s,w;
    cin>>p>>f>>cnt_s>>cnt_w>>s>>w;
    if(s>w)
        swap(s,w),
        swap(cnt_s,cnt_w);
    int ans=0;
    for(int i=0;i<=cnt_s;i++)
        if(i*s<=p)
        {
            int s1=i;
            int w1=min(cnt_w,(p-s1*s)/w);
            int s2=min(cnt_s-s1,f/s);
            int w2=min(cnt_w-w1,(f-s2*s)/w);
            ans=max(ans,s1+w1+s2+w2);
        }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        cout<<solve()<<"\n";
}