#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=1e6+5;
bool used[maxn];vector<int> pr;int fact[2*maxn];int d[maxn];int ma[maxn];map<int,int> h[maxn];int t1[maxn];int t2[maxn];int cnt[maxn];
bool check(vector<int> a,vector<int> v)
{
    int n=a.size();for(int i=0;i<n;++i) if(a[i]!=0 && a[i]!=v[i]) return false;
    for(int i=0;i<n;++i) for(int j=i+1;j<n;++j) {if((__gcd(i+1,j+1)==1)!=(__gcd(v[i],v[j])==1)) return false;}
    return true;
}
int naive(vector<int> a)
{
    int n=a.size();
    vector<int> v(n);iota(v.begin(),v.end(),1);
    int ans=0;
    while(true)
    {
        //if(v[0]!=1) break;
        if(v[0]>=2 && v[0]<=(n/2)) {next_permutation(v.begin(),v.end());continue;}
        if(check(a,v)) {++ans;
        #ifdef LOCAL
            for(auto h:v) cout<<h<<' '; cout<<endl;
            #endif
            }
        if(!next_permutation(v.begin(),v.end())) break;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;for(int i=1;i<2*maxn;++i) {fact[i]=(fact[i-1]*i)%p;}
    for(int i=1;i<maxn;++i) {d[i]=1;ma[i]=0;}
    int n;cin>>n;
    used[0]=true;used[1]=true;for(int i=2;i<=n;++i) {if(!used[i]) {pr.push_back(i);cnt[n/i]++;} else {continue;} for(int j=i;j<=n;j+=i) {ma[j]=i;d[j]*=i;used[j]=true;}}
    cnt[1]++;
    for(int i:pr)
    {
        if(i*i<=n) {t1[i]=i;t2[i]=i;for(int j=1;j<=n/i;++j)
        {
            if(ma[i*j]==i)
            {
            h[i][d[i*j]]++;
            }
        }}
        else
        {
        for(int j=1;j<=n/i;++j)
        {
            h[i][d[j]]++;
        }
        }
    }
    vector<int> a(n);for(int i=0;i<n;++i) cin>>a[i]; if(n<=10) {cout<<naive(a)<<endl; return 0;} a.insert(a.begin(),0);
    for(int i=1;i<=n;++i)
    {
        int x=a[i];
        if(x==0) continue;
        if(x==1 || ((upper_bound(pr.begin(),pr.end(),x)-lower_bound(pr.begin(),pr.end(),x)) && 2*x>n))
        {
            if(i!=1 && !((upper_bound(pr.begin(),pr.end(),i)-lower_bound(pr.begin(),pr.end(),i)) && 2*i>n))
            {
                cout<<0;return 0;
            }
            t1[i]=x;t2[x]=i;cnt[1]--;
        }
        else if(i==1 || ((upper_bound(pr.begin(),pr.end(),i)-lower_bound(pr.begin(),pr.end(),i)) && 2*i>n))
        {
            cout<<0;return 0;
        }
        else
        {
            int p1=ma[i];int p2=ma[x];
            if(p1!=p2 || p1*p1>n || p2*p2>n)
            {
            int di=d[i/p1];int dx=d[x/p2];
            if(di!=dx) {cout<<0;return 0;}
            if((n/p1)!=(n/p2)) {cout<<0;return 0;}
            if(t1[p1]==0) {cnt[n/p1]--;}
            if(t1[p1]==0 || t1[p1]==p2) {t1[p1]=p2;}
            else {cout<<0;return 0;}
            if(t2[p2]==0 || t2[p2]==p1) {t2[p2]=p1;}
            else {cout<<0;return 0;}
            h[p1][di]--;
            }
            else
            {
            if(d[i]!=d[x]) {cout<<0;return 0;}
            h[p1][d[x]]--;
            }
        }
    }
    int ans=1;for(int i=1;i<=n;++i) {ans*=fact[cnt[i]];ans%=p;}
    for(int i:pr)
    {
        for(auto [key,val]:h[i])
        {
            ans*=fact[val];ans%=p;
        }
    }
    cout<<(ans%p+p)%p;
    return 0;
}
/*
12
0 0 0 0 0 0 0 0 0 0 0 0
288
*/