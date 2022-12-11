#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,string> ps;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,n1;
string s[N];
ps a[N];
void prepare(){
    cin>>n;
    FOR(i,1,n) {
        cin>>s[i];
        int pos=7,n1=s[i].length();
        while (pos<n1&&s[i][pos]!='/') pos++;
        s[i].insert(pos,1,'@');
    }
    sort(s+1,s+n+1);
    n1=n;n=0;
    FOR(i,1,n1){
        s[++n]=s[i];
        while (i<n1&&s[i+1]==s[i]) i++;
    }
    FOR(i,1,n){
        int pos=0;
        while (s[i][pos]!='@') pos++;
        int n1=s[i].length()-1;
        FORD(j,n1,pos){
            a[i].Y.push_back(s[i][j]);
            s[i].pop_back();
        }
        a[i].X=s[i];
    }
    n1=0;
    FOR(i,1,n){
        a[++n1]=a[i];
        while (i<n&&a[i+1].X==a[n1].X) a[n1].Y+=a[++i].Y;
    }
    FOR(i,1,n1) swap(a[i].X,a[i].Y);
    sort(a+1,a+n1+1);
//    FOR(i,1,n1) cout<<a[i].X<<" "<<a[i].Y<<'\n';
}
void solve(){
    int ans=0;
    FOR(i,1,n1){
        if (i<n1&&a[i+1].X==a[i].X) ans++;
        while (i<n1&&a[i+1].X==a[i].X) i++;
    }
    cout<<ans<<'\n';
    FOR(i,1,n1){
        bool ok=0;
        if (i<n1&&a[i+1].X==a[i].X) {
            cout<<a[i].Y<<" ";
            ok=1;
        }
        while (i<n1&&a[i+1].X==a[i].X) cout<<a[++i].Y<<" ";
        if (ok) ENDL;
    }
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}