#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

double d(pii p,pii q){
    return hypot(abs(p.X-q.X),abs(p.Y-q.Y));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pii a,b,t;
    cin>>a.X>>a.Y>>b.X>>b.Y>>t.X>>t.Y;
    int n;
    cin>>n;
    vector<pii> v(n);
    vector<pair<ld,int> > bb(n),aa(n);
    ld ans=0;
    rep(i,0,n){
        cin>>v[i].X>>v[i].Y;
        ans+=2*d(v[i],t);
        bb[i]={-d(v[i],t)+d(b,v[i]),i};
        aa[i]={-d(v[i],t)+d(a,v[i]),i};
    }
    sort(allof(bb));
    sort(allof(aa));
    ld oans=ans;
    ans = oans+bb[0].X;
    ans = min(ans,oans+aa[0].X);
    if(n>1){
        if(aa[0].Y!=bb[0].Y)ans = min(ans,oans+aa[0].X+bb[0].X);
        ans = min(ans,oans+aa[1].X+bb[0].X);
        ans = min(ans,oans+aa[0].X+bb[1].X);
    }
    cout<<setprecision(30);
    cout<<ans<<endl;
    return 0;
}