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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    vector<int> a(m);
    rep(i,0,n)cin>>v[i];
    rep(i,0,m)cin>>a[i],a[i]--;
    string s = v[a[0]];
    rep(i,1,m){
        if(v[a[i]].size()!=s.size()) goto no;
        rep(j,0,s.size()) if(s[j] != v[a[i]][j]) s[j] = '?';
    }
    rep(i,0,n){
        if(find(a.begin(),a.end(),i) == a.end() && v[i].size()==s.size()){
            bool b = true;
            rep(j,0,s.size()) if(s[j] != v[i][j] && s[j] != '?' ) b=false;
            if(b) goto no;
        }
    }
    cout<<"Yes\n"<<s<<endl;
    return 0;
    no:
    cout<<"No"<<endl;
}