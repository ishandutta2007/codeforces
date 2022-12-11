#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("180d.inp","r",stdin)
#define OUTPUT freopen("180d.out","w",stdout)
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
const int N=30;

int n,h[30];
string s,s1;
int main(){
    cin>>s>>s1;
    for(auto i:s) h[i-'a']++;
    int last=-1,n=s.length(),m=s1.length();
    while (last<min(n-1,m-1)&&h[s1[last+1]-'a']) h[s1[++last]-'a']--,s[last]=s1[last];
    s1.push_back('a'-1);
    //cout<<last<<'\n';
    //FOR(i,0,25) cout<<h[i]<<" \n"[i==25];
    while (last>=-1){
        //cout<<last<<'\n';
        //FOR(i,0,25) cout<<h[i]<<" \n"[i==25];
        FOR(j,s1[last+1]-'a'+1,25) if (h[j]){
            h[j]--;
            //cout<<j<<'\n';
            s[last+1]='a'+j;
            int cur=last+2;
            FOR(i,0,25)
                while (h[i]) s[cur++]='a'+i,h[i]--;
            cout<<s;
            return 0;
        }
        if (last>=0) h[s1[last--]-'a']++;else break;

    }
    printf("-1");
}