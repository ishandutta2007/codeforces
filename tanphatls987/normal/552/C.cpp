#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=100;

int s[N],w,m;
string solve(){
    if (m==2) return "YES";
    int top=0;
    while (w){
        s[++top]=w%m;
        w/=m;
    }
//    FOR(i,1,top) printf("%d ",s[i]);ENDL;
    FOR(i,1,top){
        if (s[i]>1&&s[i]!=m-1) return "NO";
        if (s[i]==m-1){
            int j=i+1;
            while (s[j]==m-1) j++;
            s[j]++;
            REP(k,i,j) s[k]=0;
            if (j>top) top++;
        }
    }
    return "YES";
}
int main(){
    cin>>m>>w;
    cout<<solve();
}