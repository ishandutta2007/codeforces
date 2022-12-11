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
const int N=2e2+10;


string sk,s;
int n,m,k,h[N][2],t[30],th[N][2],seal[N],tseal[N],mark[2];
vector <ii> ru[N][2];
bool filldemand(int x,int type){
    if (!th[x][type]) return 0;
    th[x][type^1]=0;
    if (tseal[x]) return 1;
    tseal[x]=1;
    for(auto i:ru[x][type]) if (!filldemand(i.X,i.Y)) return 0;
    return 1;
}
void makecache(){
    FOR(i1,1,n)
        FOR(j1,0,1) th[i1][j1]=h[i1][j1];
    FOR(i1,1,n) tseal[i1]=seal[i1];
}
string check(int pos){
    string ans(n,'@');
//    cout<<pos<<'\n';
    FOR(i,1,n)
        FOR(j,0,1) h[i][j]=1;
    memset(seal,0,sizeof(seal));
    FOR(i,1,n){
        if (i<pos){
            makecache();
            if (filldemand(i,t[s[i-1]-'a'])) ans[i-1]=s[i-1];
        }else{
            memset(mark,0,sizeof(mark));
            REP(j,((i==pos)?s[i-1]-'a'+1:0),k) if (!mark[t[j]]&&h[i][t[j]]){
                mark[t[j]]=1;
                makecache();
                if (filldemand(i,t[j])){
                    ans[i-1]=j+'a';
                    break;
                }
            }
        }
        if (ans[i-1]=='@') return "-1";
//        cout<<i<<" "<<ans[i-1]<<'\n';
        FOR(i1,1,n){
            seal[i1]=tseal[i1];
            FOR(j1,0,1) h[i1][j1]=th[i1][j1];
        }
    }
    return ans;
}
string solve(){
    FORD(i,n+1,1){
        string ans=check(i);
        if (ans!="-1") return ans;
    }
    return "-1";
}
void prepare(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>sk>>n>>m;
    k=sk.length();
    REP(i,0,k) t[i]=(sk[i]=='C');
    int x,y;
    char ch1,ch2;
    FOR(i,1,m){
        cin>>x>>ch1>>y>>ch2;
        ru[x][ch1=='C'].push_back(ii(y,ch2=='C'));
        ru[y][ch2=='V'].push_back(ii(x,ch1=='V'));
    }
    cin>>s;
}
int main(){
    prepare();
    //
    cout<<solve();
}