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
const int N=1e5+10,M=1e5;

int n;
int main(){
    cin>>n;
    if (n<=2) printf("1\n1");
    else if (n==3) printf("2\n1 3");
    else if (n==4) printf("4\n2 4 1 3");
    else{
        printf("%d\n",n);
        for(int i=1;i<=n;i+=2) printf("%d ",i);
        for(int i=2;i<=n;i+=2) printf("%d ",i);
    }
}