#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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
const int N=5e3+10;

string s;
int pos[30];
ll solve(){
//    cout<<s<<'\n';
    int n=s.length(),m=0;
    ll ans=0;
    REP(i,0,n) if (s[i]=='*') pos[++m]=i;
    REP(i,1,m)
        FOR(k,i+1,m){
            ll cmul=0,cans=0,last=1;
            for(int j=pos[i]+1;j<pos[k];j+=2) {
                if (s[j-1]=='*') last*=s[j]-'0';
                else cmul+=last,last=s[j]-'0';
            }
            cmul+=last;
            last=s[0]-'0';
//            printf("%d %d %lld\n",pos[i],pos[k],cmul);
            for(int j=2;j<pos[i];j+=2){
                if (s[j-1]=='*') last*=s[j]-'0';
                else cans+=last,last=s[j]-'0';
            }
            last*=cmul;
            for(int j=pos[k]+1;j<n;j+=2){
                if (s[j-1]=='*') last*=s[j]-'0';
                else cans+=last,last=s[j]-'0';
            }
//                printf("%d %d %lld\n",pos[i],pos[k],cans+last);
            ans=max(ans,cans+last);
    }
    return ans;
}
int main(){
    cin>>s;
    s="1*"+s+"*1";
    cout<<solve();
}