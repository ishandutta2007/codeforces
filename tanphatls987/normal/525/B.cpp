#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
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
const int N=1e5+10;

int m,x,a[N];
string s;
int main(){
    cin>>s>>m;
    int n=s.length();
    while (m--){
        scanf("%d",&x);
        a[x-1]++;
    }
    REP(i,0,n/2){
        if (i) a[i]+=a[i-1];
        if (a[i]%2) swap(s[i],s[n-i-1]);
    }
    cout<<s;
}