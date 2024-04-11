#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e3+10;

int n,m;
map <string,int> ma;
string s1;
char ch;
vector <string> v[26];
void DFS(string s){
    if (ma[s]) return;
    ma[s]=1;
    int n1=s.length();
    if (n1==n) return;
    string suf;
    REP(i,1,n1) suf.push_back(s[i]);
    for(auto s1:v[s[0]-'a']) DFS(s1+suf);
}
int main(){
    cin>>n>>m;
    while (m--){
        cin>>s1>>ch;
        v[ch-'a'].push_back(s1);
    }
    DFS("a");
    int ans=0;
    for(auto i:ma) if (i.X.length()==n) ans++;
    cout<<ans;
}