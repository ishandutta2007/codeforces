#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
const int p=998244353;
int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*1LL*u)%p;} else {int u=po(a,b-1);return (a*1LL*u)%p;}}
int inv(int x) {return po(x,p-2);}
template<int M, int K, int G> struct Fft {
  // 1, 1/4, 1/8, 3/8, 1/16, 5/16, 3/16, 7/16, ...
  int g[1 << (K - 1)];
  constexpr Fft() : g() {
    static_assert(K >= 2, "Fft: K >= 2 must hold");
    g[0] = 1;
    g[1 << (K - 2)] = G;
    for (int l = 1 << (K - 2); l >= 2; l >>= 1) {
      g[l >> 1] = (static_cast<long long>(g[l]) * g[l]) % M;
    }
    assert((static_cast<long long>(g[1]) * g[1]) % M == M - 1);
    for (int l = 2; l <= 1 << (K - 2); l <<= 1) {
      for (int i = 1; i < l; ++i) {
        g[l + i] = (static_cast<long long>(g[l]) * g[i]) % M;
      }
    }
  }
  void fft(vector<int> &x) const {
    const int n = x.size();
    assert(!(n & (n - 1)) && n <= 1 << K);
    for (int h = __builtin_ctz(n); h--; ) {
      const int l = 1 << h;
      for (int i = 0; i < n >> 1 >> h; ++i) {
        for (int j = i << 1 << h; j < ((i << 1) + 1) << h; ++j) {
          const int t = (static_cast<long long>(g[i]) * x[j | l]) % M;
          if ((x[j | l] = x[j] - t) < 0) x[j | l] += M;
          if ((x[j] += t) >= M) x[j] -= M;
        }
      }
    }
    for (int i = 0, j = 0; i < n; ++i) {
      if (i < j) std::swap(x[i], x[j]);
      for (int l = n; (l >>= 1) && !((j ^= l) & l); ) {}
    }
  }
  vector<int> convolution(const vector<int> &a, const vector<int> &b) const {
    if(a.empty() || b.empty()) return {};
    const int na = a.size(), nb = b.size();
    int n, invN = 1;
    for (n = 1; n < na + nb - 1; n <<= 1) invN = ((invN & 1) ? (invN + M) : invN) >> 1;
    vector<int> x(n, 0), y(n, 0);
    std::copy(a.begin(), a.end(), x.begin());
    std::copy(b.begin(), b.end(), y.begin());
    fft(x);
    fft(y);
    for (int i = 0; i < n; ++i) x[i] = (((static_cast<long long>(x[i]) * y[i]) % M) * invN) % M;
    std::reverse(x.begin() + 1, x.end());
    fft(x);
    x.resize(na + nb - 1);
    return x;
  }
};
Fft<998244353,23,31> muls;
vector<int> form(vector<int> v,int n)
{
    while(v.size()<n) v.push_back(0);
    while(v.size()>n) v.pop_back();
    return v;
}
vector<int> operator *(vector<int> v1,vector<int> v2)
{
    return muls.convolution(v1,v2);
}
vector<int> operator +(vector<int> v1,vector<int> v2)
{
    while(v2.size()<v1.size()) v2.push_back(0); while(v1.size()<v2.size()) v1.push_back(0);
    for(int i=0;i<v1.size();++i) {v1[i]+=v2[i];if(v1[i]>=p) v1[i]-=p; else if(v1[i]<0) v1[i]+=p;}
    return v1;
}
vector<int> operator -(vector<int> v1,vector<int> v2)
{
    int sz=max(v1.size(),v2.size());while(v1.size()<sz) v1.push_back(0); while(v2.size()<sz) v2.push_back(0);
    for(int i=0;i<sz;++i) {v1[i]-=v2[i];if(v1[i]<0) v1[i]+=p; else if(v1[i]>=p) v1[i]-=p;} return v1;
}
vector<int> trmi(vector<int> v)
{
    for(int i=1;i<v.size();i+=2) {if(v[i]>0) v[i]=p-v[i]; else v[i]=(-v[i]);}
    return v;
}
vector<int> deriv(vector<int> v)
{
    if(v.empty()) return{};
    vector<int> ans(v.size()-1);
    for(int i=1;i<v.size();++i) ans[i-1]=(v[i]*1LL*i)%p;
    return ans;
}
vector<int> integ(vector<int> v)
{
    vector<int> ans(v.size()+1);ans[0]=0;
    for(int i=1;i<v.size();++i) ans[i-1]=(v[i]*1LL*i)%p;
    return ans;
}
vector<int> mul(vector<vector<int> > v)
{
    if(v.size()==1) return v[0];
    vector<vector<int> > v1,v2;for(int i=0;i<v.size()/2;++i) v1.push_back(v[i]); for(int i=v.size()/2;i<v.size();++i) v2.push_back(v[i]);
    return muls.convolution(mul(v1),mul(v2));
}
vector<int> inv1(vector<int> v,int n)
{
    assert(v[0]!=0);
    int sz=1;v=form(v,n);vector<int> a={inv(v[0])};
    while(sz<n)
    {
        vector<int> vsz;for(int i=0;i<min(n,2*sz);++i) vsz.push_back(v[i]);
        vector<int> b=((vector<int>) {1})-muls.convolution(a,vsz);
        for(int i=0;i<sz;++i) assert(b[i]==0);
        b.erase(b.begin(),b.begin()+sz);
        vector<int> c=muls.convolution(b,a);
        for(int i=0;i<sz;++i) a.push_back(c[i]);
        sz*=2;
    }
    return form(a,n);
}
vector<int> inv(vector<int> v,int n)
{
    v=form(v,n);assert(v[0]!=0);if(v.size()==1) {return {inv(v[0])};} vector<int> v1=trmi(v);
    vector<int> a=v1*v;a=form(a,2*n);
    vector<int> b((n+1)/2);for(int i=0;i<b.size();++i) b[i]=a[2*i];
    vector<int> ans1=inv(b,b.size());vector<int> ans2(n);for(int i=0;i<n;++i) {if(i%2==0) ans2[i]=ans1[i/2]; else ans2[i]=0;}
    return form(v1*ans2,n);
}
vector<int> operator/(vector<int> a,vector<int> b)
{
    while(!a.empty() && a.back()==0) a.pop_back(); while(!b.empty() && b.back()==0) b.pop_back();
    int n=a.size();int m=b.size();if(n<m) return {};
    reverse(a.begin(),a.end());reverse(b.begin(),b.end());vector<int> ans=a*inv(b,n-m+1);while(ans.size()>n-m+1) ans.pop_back();
    reverse(ans.begin(),ans.end());while(!ans.empty() && ans.back()==0) ans.pop_back();return ans;
}
vector<int> operator%(vector<int> a,vector <int> b)
{
    vector<int> ans=a-b*(a/b);while(!ans.empty() && ans.back()==0) ans.pop_back(); return ans;
}
#define prev quejdndjd
const int maxn=3e5+5;
int nxt[maxn];int pr[maxn];int d[maxn];bool used[maxn];bool bad[maxn];bool prev[maxn];int u[maxn][20];
int par[maxn];
int get(int x)
{
    if(par[x]==(-1)) return x;
    int ans=get(par[x]);par[x]=ans;return ans;
}
void merg(int x,int y)
{
    x=get(x);y=get(y);if(x==y) return; par[x]=y;
}
void dfs(int x)
{
    used[x]=true;if(bad[x]) {d[x]=1e18;return;}
    if(nxt[x]==(-1)) {d[x]=1;return;}
    dfs(nxt[x]);d[x]=d[nxt[x]]+1;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fill(nxt,nxt+maxn,-1);fill(pr,pr+maxn,-1);fill(par,par+maxn,-1);
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<n;++i)
    {
        int c;cin>>c;vector<int> v(c);for(int i=0;i<c;++i) cin>>v[i];
        for(int i=0;i<c-1;++i) {merg(v[i],v[i+1]);if(nxt[v[i]]!=(-1) && nxt[v[i]]!=v[i+1]) {bad[v[i]]=true;} nxt[v[i]]=v[i+1];}
        for(int i=1;i<c;++i) {if(pr[v[i]]!=(-1) && pr[v[i]]!=v[i-1]) {bad[v[i]]=true;} pr[v[i]]=v[i-1];}
    }
    for(int i=1;i<=k;++i) if(bad[i]) bad[get(i)]=true;
    for(int i=1;i<=k;++i) {u[i][0]=nxt[i];}
    for(int j=1;j<20;++j)
    {
        for(int i=1;i<=k;++i)
        {
            if(u[i][j-1]==(-1)) u[i][j]=(-1);
            else u[i][j]=u[u[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=k;++i) if(nxt[i]!=(-1)) prev[nxt[i]]=true;
    for(int i=1;i<=k;++i) if(u[i][19]!=(-1)) bad[i]=true;
    for(int i=1;i<=k;++i) {if(!bad[i] && !used[i]) dfs(i);}
    vector<int> v;for(int i=1;i<=k;++i) if(!bad[i] && !prev[i] && !bad[get(i)]) {v.push_back(d[i]);}
    vector<int> a(m+1);for(int &h:a) h=0;
    a[0]=1;
    for(int i:v)
    {
        if(i<=m) {a[i]--;if(a[i]<0) a[i]+=p;}
    }
    vector<int> u=inv(a,m+1);
    cout<<(u[m]%p+p)%p;
    return 0;
}