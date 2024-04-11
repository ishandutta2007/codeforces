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
const int N=1e5+10,alp=26;

int n,m,h[2];
string s1,s2;
int main(){
    cin>>n>>m>>s1>>s2;
    m=n-m;
    REP(i,0,n) h[(s1[i]==s2[i])]++;
    if (h[0]/2+h[1]<m){
        printf("-1");
        return 0;
    }
    string ans(n,'a');
    int c1=0,c2=0,use=min(h[0]/2,m);
    REP(i,0,n) if (s1[i]!=s2[i]){
        if (c1<use) ans[i]=s1[i],c1++;
        else if (c2<use) ans[i]=s2[i],c2++;
        else REP(j,0,alp) if (j!=s1[i]-'a'&&j!=s2[i]-'a') ans[i]='a'+j;
    }
    REP(i,0,n) if (s1[i]==s2[i]){
        if (c1<m) ans[i]=s1[i],c1++;
        else REP(j,0,alp) if (j!=s1[i]-'a') ans[i]=j+'a';
    }
    cout<<ans;
}