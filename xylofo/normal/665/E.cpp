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
typedef unsigned int ui;

const int maxn = 30000000,mxlg=30;
ui msk = 0, ptr = 1;
ui sz[maxn],ch[maxn][2];
void add(ui x,ui r=1,ui d=mxlg){
    if(d==ui(-1)) {
        sz[r]++;
        return;
    }
    ui& t = ch[r][(x>>d)&1];
    if(!t) t = ++ptr;
    add(x,t,d-1);
    sz[r] = sz[ch[r][0]] + sz[ch[r][1]];
}
ll que(ui k,ui r=1,ui d=mxlg){
    if(d==ui(-1)) return 0;
    ui& lc = ch[r][(msk>>d)&1];
    ui& rc = ch[r][!((msk>>d)&1)];
    if((k>>d)&1) return que(k,rc,d-1);
    else return sz[rc] + que(k,lc,d-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ui n,k,x;
    cin>>n>>k;
    ll ans=0;
    rep(i,0,n){
        cin>>x;
        msk ^= x;
        add(x^msk);
        ans += que(k-1);
    }
    cout<<ans<<endl;
    return 0;
}