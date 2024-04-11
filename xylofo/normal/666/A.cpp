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

set<string> st;
string s;
int dp[10005][5];
bool f(int pos,int cnt){
    if(pos<=4)return true;
    int& t=dp[pos][cnt];
    if(t) return t+1;
    t = -1;
    if( (cnt!=2 || !(s[pos-2]==s[pos] && s[pos-1]==s[pos+1])) && f(pos-2,2)) t = 1;
    if( (cnt!=3 || !(s[pos-3]==s[pos] && s[pos-2]==s[pos+1] && s[pos-1]==s[pos+2]))&&f(pos-3,3)) t = 1;
    if(t+1 && cnt) st.insert(s.substr(pos,cnt));
    return t+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    f(s.size(),0);
    cout<<st.size()<<'\n';
    for(string s:st)cout<<s<<'\n';
    return 0;
}