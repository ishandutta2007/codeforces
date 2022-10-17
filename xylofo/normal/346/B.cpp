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

string a,b,c;
vi pi;
vector<vvi> dp;

void buildTable(string& w, vi& t) {
  t = vi(max((int)w.size(),2));
  int i = 2, j = 0;
  t[0] = -1; t[1] = 0;
  while(i < w.length()) {
    if(w[i-1] == w[j]) { t[i] = j+1; i++; j++; }
    else if(j > 0) j = t[j];
    else { t[i] = 0; i++; }
  }
}

int solve(int aa,int bb,int cc){
    //cout<<aa<<" "<<bb<<" "<<cc<<endl;
    if(cc==c.size()) return -INF+1;
    if(aa==a.size() || bb==b.size()) return 0;
    int& d = dp[aa][bb][cc];
    if(d!=-INF)return d;
    d=max(solve(aa+1,bb,cc),solve(aa,bb+1,cc));
    if(a[aa]==b[bb]){
        while(cc>=0 && c[cc]!=a[aa]) cc=pi[cc];
        ++cc;
        d=max(d,solve(aa+1,bb+1,cc)+1);
    }
    return d;
}

void reconstruct(int aa,int bb,int cc,int t){
    if(aa==a.size() || bb==b.size()) return;
    if(solve(aa+1,bb,cc)==t){reconstruct(aa+1,bb,cc,t);return;}
    if(solve(aa,bb+1,cc)==t){reconstruct(aa,bb+1,cc,t);return;}
    while(cc>=0 && c[cc]!=a[aa]) cc=pi[cc];
    ++cc;
    cout<<a[aa];
    reconstruct(aa+1,bb+1,cc,t-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c;
    dp.assign(a.size(),vvi(b.size(),vi(c.size(),-INF)));
    buildTable(c,pi);
    int t=solve(0,0,0);
    //cout<<t<<endl;
    if(t==0)cout<<0<<endl;
    else reconstruct(0,0,0,t);
    return 0;
}