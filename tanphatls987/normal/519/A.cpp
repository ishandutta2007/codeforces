#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=100;

int w[N];
string s;
int main(){
    w['q'-'a']=9;
    w['r'-'a']=5;
    w['b'-'a']=3;
    w['n'-'a']=3;
    w['p'-'a']=1;
    //w['q'-'a']=9;
    int ans=0;
    FOR(i,1,8){
        cin>>s;
        for(auto c:s) if (c!='.'){
            if (c>='a'&&c<='z') ans+=w[c-'a'];
            else ans-=w[c-'A'];
        }
    }
    if (ans<0) printf("White");
    else if (ans>0) printf("Black");
    else printf("Draw");
}