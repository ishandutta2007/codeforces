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

int xa,ya,xb,yb;
int main(){
    cin>>xa>>ya>>xb>>yb;
    cout<<(xa!=xb&&ya!=yb)+1<<" ";
    if ((xa+ya+xb+yb)%2) cout<<"0 ";
    else cout<<2-(abs(xa-xb)==abs(ya-yb))<<" ";
    cout<<max(abs(xa-xb),abs(ya-yb));
}