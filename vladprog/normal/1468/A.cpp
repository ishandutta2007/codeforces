#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax = 5e5+100;

typedef long long ll;
#define int ll

template<typename T>
class SparseTable{
public:
    SparseTable(const vector<T>& m){
        n=m.size();
        a.resize(n);
        for (int i=0; i<n; i++) a[i]=m[i];
        fill_lg();
        BuildedMin=BuildedMax=false;
    }
    int MinPos(int l, int r){
        if (!BuildedMin) BuildMin();
        if ((l<0) or (r>=n) or (l>r)) cerr<<"Error: incorrect segment: l="<<l<<", r="<<r<<", while n="<<n<<endl;
        int j=lg[r-l+1];
        r-=(1<<j)-1;
        return (a[mn[j][l]] < a[mn[j][r]]) ? mn[j][l] : mn[j][r];
    }
    int MaxPos(int l, int r){
        if (!BuildedMax) BuildMax();
        if ((l<0) or (r>=n) or (l>r)) cerr<<"Error: incorrect segment: l="<<l<<", r="<<r<<", while n="<<n<<endl;
        int j=lg[r-l+1];
        r-=(1<<j)-1;
        return (a[mx[j][l]] < a[mx[j][r]]) ? mx[j][r] : mx[j][l];
    }
    T Min(int l, int r){ return a[MinPos(l, r)]; }
    T Max(int l, int r){ return a[MaxPos(l, r)]; }
private:
    void BuildMin(){ BuildedMin=true;
        mn.resize(lg[n]+1);
        mn[0].resize(n);
        for (int i=0; i<n; i++) mn[0][i]=i;
        for (int j=1; j<=lg[n]; j++)
        {
            mn[j].resize(n-(1<<j)+1);
            for (int i=0; i<=n-(1<<j); i++)
                mn[j][i]=(a[mn[j-1][i]] < a[mn[j-1][i+(1<<(j-1))]]) ? mn[j-1][i] : mn[j-1][i+(1<<(j-1))];
        }
    }
    void BuildMax(){ BuildedMax=true;
        mx.resize(lg[n]+1);
        mx[0].resize(n);
        for (int i=0; i<n; i++) mx[0][i]=i;
        for (int j=1; j<=lg[n]; j++)
        {
            mx[j].resize(n-(1<<j)+1);
            for (int i=0; i<=n-(1<<j); i++)
                mx[j][i]=(a[mx[j-1][i]] < a[mx[j-1][i+(1<<(j-1))]]) ? mx[j-1][i+(1<<(j-1))] : mx[j-1][i];
        }
    }
    void fill_lg(){
        lg.assign(n+1, 0);
        for (int i=2; i<=n; i++) lg[i]=lg[i/2]+1;
    }
    bool BuildedMin, BuildedMax;
    int n;
    vector<int> lg;
    vector<T> a;
    vector<vector<int> > mn;
    vector<vector<int> > mx;
};


int n;
pair<int, int> f[nmax];

pair<int, int> get(int r)
{
    pair<int, int> ans = {0, 0};
    for (int i=r; i>0; i&=(i+1), i--)
        ans=max(ans, f[i]);
    return ans;
}

void upd(int x, pair<int, int> pa)
{
    for (int i=x; i<=n; i|=(i+1))
        f[i]=max(f[i], pa);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int q=0; q<t; q++)
    {
        cin>>n;
        for (int i=1; i<=n; i++)
            f[i]={0, -1e9};

        vector<int> v;
        for (int i=1; i<=n; i++)
        {
            int a;
            cin>>a;
            v.pb(a);
        }

        vector<pair<int, int> > upds;
        SparseTable<int> st(v);
        int c = 0;
        int ans = 0;
        for (int i:v)
        {
            pair<int, int> pr = get(i);

            pr.se = -pr.se;
            int res;
            if (pr.se > n)
                res = 1;
            else
            if (st.Max(pr.se, c) > i)
                res = pr.fi + 2;
            else
                res = pr.fi + 1;

            c++;
            upd(i, {res, -c});
            upds.pb({res, c});
            ans = max(ans, res);
        }
        cout<<ans<<"\n";
    }
}