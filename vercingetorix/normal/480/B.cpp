#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

const long long mod = 1000000007;

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
    int n,l,x,y;
    int ans=0;
    cin>>n>>l>>x>>y;
    vi a;
    int z;
    for(int i=0;i<n;i++){
        cin>>z;
        a.pb(z);
    }
    vi gm,gf;
    vi cm, cf;
    for(int i=0;i<n;i++){
        cm.pb(a[i]);
        cm.pb(a[i]+y);
        cf.pb(a[i]);
        cf.pb(a[i]+x);
    }
    sort(all(cm));
    sort(all(cf));
    bool m=false;
    bool f=false;
    for(int i=1; i<2*n; i++) if(cm[i]==cm[i-1]) m=true;
    for(int i=1; i<2*n; i++) if(cf[i]==cf[i-1]) f=true;
    if(m&&f){
        cout<<0;
        return 0;
    }
    if(m||f){
        cout<<1<<endl;
        if(m) cout<<x;
        else cout<<y;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(a[i]>=y) gm.pb(a[i]-y);
        if(a[i]+y<=l) gm.pb(a[i]+y);
        if(a[i]>=x) gf.pb(a[i]-x);
        if(a[i]+x<=l) gf.pb(a[i]+x);
    }
    sort(all(gf));
    sort(all(gm));
    int fs=gf.size();
    int ms=gm.size();
    int curf=0, curm=0;
    while((curf<fs)&&(curm<ms)){
        if(gf[curf]==gm[curm]){
            cout<<1<<endl<<gf[curf];
            return 0;
        }
        else if(gf[curf]>gm[curm]){
            curm++;
        }
        else curf++;
    }
    cout<<2<<endl;
    cout<<x<<" "<<y;
    return 0;
}