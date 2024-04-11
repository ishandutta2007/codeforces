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

string s,s1;
int main(){
    cin>>s>>s1;
    int n=s.length(),L=-1,R=n;
    while (L<n-2&&s[L+1]==s1[L+1]) L++;
    while (R>=2&&s[R-1]==s1[R-2]) R--;
    //cout<<L<<" "<<R<<'\n';
    if (L+1<R){
        if (L+2!=R) printf("0");
        else printf("1\n%d",L+2);
    }else{
        printf("%d\n",L-R+3);
        FOR(i,R-1,L+1) printf("%d ",i+1);
    }
}