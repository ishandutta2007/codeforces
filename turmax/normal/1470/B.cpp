#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> rasl(int n)
{
    vector <int> v;
    if(n==1) return v;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            v=rasl(n/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(n);
    return v;
}
const int maxn=1e6+5;
bool issq[maxn];
int sq[maxn];
int h(int n)
{
    //cout<<n<<" n "<<endl;
    if(issq[n]) return 1;
    if(n==1) return n;
    for(int i=2;i*i*i<=n;++i)
    {
        if(n%i==0 && issq[n/i])
        {
            return h(i);
        }
        if(n%(i*i)==0)
        {
            return h(n/(i*i));
        }
    }
    return n;
}
int32_t main()
{
    for(int i=0;i<=1000;++i) {issq[i*i]=true;sq[i*i]=i;}
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int b[n];
        int l=0;
        for(int i=0;i<n;++i) {cin>>a[i];b[i]=h(a[i]);if(b[i]==1) ++l;}
        map <int,int> o;vector <int> keys;
        int ma=0;
        for(int i=0;i<n;++i)
        {
            if(!o.count(b[i])) {o[b[i]]=1;keys.push_back(b[i]);}
            else o[b[i]]++;
        }
        for(int i=0;i<n;++i)
        {
            ma=max(ma,o[b[i]]);
            if(b[i]!=1)
            if(o[b[i]]%2==0) ++l;
        }
        int q;
        cin>>q;
        while(q--)
        {
            int tm;
            cin>>tm;
            if(tm==0)
            {
                cout<<ma<<'\n';
            }
            else
            {
                cout<<max(ma,l)<<'\n';
            }
        }
    }
    return 0;
}