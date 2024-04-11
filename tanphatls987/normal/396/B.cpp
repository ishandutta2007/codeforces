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

const ll inf=1e9;
const int MOD=1e9+7;
const int N=1e5;


int n,x,t[N];
vector <int> pri;
bool checkprime(int x){
    for(auto i:pri){
        if (i*i>x) return 1;
        if (x%i==0) return 0;
    }
}
int main(){
    REP(i,2,N) if (!t[i]){
        pri.push_back(i);
        for(int j=i;j<N;j+=i) t[j]=i;
    }
    scanf("%d",&n);
    while (n--){
        scanf("%d",&x);
        int L=x,R=x+1;
        while (!checkprime(L)) L--;
        while (!checkprime(R)) R++;
//        cout<<L<<" "<<R<<'\n';
        ll num=1LL*L*R+2*x-2*L-2*R+2,den=2LL*L*R,tmp=__gcd(num,den);
//        cout<<num<<" "<<den<<'\n';
        cout<<num/tmp<<'/'<<den/tmp<<'\n';
    }
}