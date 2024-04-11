#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
int lp[maxn];
bool used[maxn];vector <int> pr;vector <int> prc;
int cnt[maxn];
void init()
{
    used[0]=true;used[1]=true;
    for(int i=2;i<maxn;++i)
    {
        if(used[i]) continue;
        pr.push_back(i);prc.push_back(i);lp[i]=i;
        int cur=i;
        while(cur*i<maxn) {cur*=i;prc.push_back(cur);lp[cur]=i;}
        for(int j=2*i;j<maxn;j+=i)
        {
            used[j]=true;
        }
    }
}
int lcm(int x,int y) {return (x*y)/__gcd(x,y);}
int n;
int hid;int cnt2[maxn];
int a(int x)
{
    assert(x>=1 && x<=n);
    cout<<"A "<<x<<endl;
    //int ans=0;for(int i=x;i<=n;i+=x) ans+=cnt2[i];
    //return ans;
    int ans;cin>>ans;return ans;
}
int b(int x)
{
    assert(x>=2 && x<=n);
    cout<<"B "<<x<<endl;
    //for(int i=x;i<=n;i+=x) if(i!=hid) cnt2[i]=0;
    //return 0;
    int ans;cin>>ans;return ans;
}
int c(int x)
{
    assert(x>=1 && x<=n);
    cout<<"C "<<x<<endl;
    exit(0);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //hid=11113;
    init();
    //n=100000;
    cin>>n;
    for(int i=1;i<=n;++i) cnt2[i]=1;
    for(int i=1;i<=n;++i) cnt[i]=1;
    sort(prc.begin(),prc.end());
    int curans=1;
    int que=0;
    for(auto h:pr)
    {
        if(h*h<=n)
        {
            b(h);
            ++que;
            assert(que<=9998);
            for(int i=h;i<=n;i+=h) {cnt[i]=0;}
        }
    }
    int h=1;
    int ans=a(h);
    int ans1=0;for(int i=h;i<=n;i+=h) {ans1+=cnt[i];}
    bool f=(ans1!=ans);
    ++que;
    assert(que<=9998);
    if(f)
    {
    for(auto h:prc)
    {
        if(h>n) continue;
        int ans=a(h);
        ++que;
        assert(que<=9998);
        int ans1=0;for(int i=h;i<=n;i+=h) {ans1+=cnt[i];}
        if(ans1!=ans) curans=lcm(curans,h);
    }
    }
    else
    {
        int l=(-1);
        for(auto h:pr)
        {
            int h1=h;
            if(h*h<=n || h>n) continue;
            int ans=b(h);
            cnt[h]=0;
            ++que;
            if(que%300==0)
            {
                int h=1;
        int ans=a(h);
        ++que;
        int ans1=0;for(int i=h;i<=n;i+=h) {ans1+=cnt[i];}
        if(ans1!=ans)
        {
            int r=h1;
            for(int i=l+1;i<=r;++i)
            {
                if(!used[i])
                {
                    int ans=a(i);
                    ++que;
                    if(ans) {c(i);return 0;}
                }
            }
            assert(false);
            return 0;
        }
        else
        {
            l=h1;
        }
            }
        }
        int ans=a(1);
        ++que;
        if(ans==1) {c(1);return 0;}
        int r=n;
            for(int i=l+1;i<=r;++i)
            {
                if(!used[i])
                {
                    int ans=a(i);
                    if(ans) {c(i);return 0;}
                }
            }
    }
    c(curans);
    return 0;
}