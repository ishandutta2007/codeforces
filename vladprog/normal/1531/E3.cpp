#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5;

string s;
int pos;

vector<int> mergesort(int l,int r)
{
    if(r-l==1)
        return {l};
    if(r-l<=0)
        return {};
    int m=(l+r)>>1;
    vector<int> a=mergesort(l,m);
    if(a==vector<int>{-1}) return {-1};
    vector<int> b=mergesort(m,r);
    if(b==vector<int>{-1}) return {-1};
    int cnt0=0,cnt1=0;
    vector<int> v(r-l);
    while(cnt0<m-l&&cnt1<r-m&&pos<s.size())
    {
        if(s[pos]=='0')
            v[cnt0+cnt1]=a[cnt0],
            cnt0++;
        else
            v[cnt0+cnt1]=b[cnt1],
            cnt1++;
        pos++;
    }
    if(cnt0<m-l&&cnt1<r-m)
    {
//        cout<<l<<" "<<r<<" -> "<<-1<<"\n";
        return {-1};
    }
    else
    {
        while(cnt0<m-l)
            v[cnt0+cnt1]=a[cnt0],
            cnt0++;
        while(cnt1<r-m)
            v[cnt0+cnt1]=b[cnt1],
            cnt1++;
//        cout<<l<<" "<<r<<" -> ";
//        for(int i:v)
//            cout<<i<<" ";
//        cout<<"\n";
        return v;
    }
}

int a[N];

int solve(int n)
{
    pos=0;
    vector<int> v=mergesort(0,n);
    if(v==vector<int>{-1})
        return -1;
    if(pos!=s.size())
        return s.size()-pos;
    for(int i=0;i<n;i++)
        a[v[i]+1]=i+1;
    cout<<n<<"\n";
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    exit(0);
}

int rnd()
{
    return rand()*(RAND_MAX+1)+rand();
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    cin>>s;
    int l=1,r=N;
    while(l<=r)
    {
        int m=(l+r)/2;
        int res=solve(m);
        if(res==-1)
            r=m-1;
        else
            l=m+1;
    }
}