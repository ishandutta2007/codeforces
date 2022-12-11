#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;


int n;
string s;
char spe;
vector <string> a[15];
int main(){
    cin>>n;
    int total=0;
    FOR(i,1,n){
        cin>>s;
        int m=s.length();
        a[m].push_back(s);
        total+=m;
    }
    FOR(i,1,10) sort(a[i].begin(),a[i].end());
    total/=(n/2);
    cin>>spe;
    vector <string> ans;
    if (total%2==0){
        int m=a[total/2].size();
        for(int i=0;i<m;i+=2) ans.push_back(a[total/2][i]+spe+a[total/2][i+1]);
    }
    FOR(i,1,(total-1)/2){
        int m=a[i].size();
        //cout<<m<<'\n';
        REP(j,0,m) ans.push_back(min(a[i][j]+spe+a[total-i][j],a[total-i][j]+spe+a[i][j]));
    }
    sort(ans.begin(),ans.end());
    for(auto cs:ans) cout<<cs<<'\n';
}