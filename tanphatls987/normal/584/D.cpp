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
const int N=int(sqrt(inf))+10,M=2e3+10;

vector <int> pri,v[M];
int h[N];
void prepare(){
    h[1]=1;
    REP(i,2,N) if (!h[i]){
        pri.push_back(i);
        for(int j=i+i;j<N;j+=i) h[j]=1;
    }
    v[2].push_back(2);
    for(int i=4;i<M;i+=2)
        for(auto j:pri) if (!h[i-j]){
            v[i]={i-j,j};
            break;
        }
}
bool isprime(int x){
    for(auto i:pri){
        if (i*i>x) return 1;
        if (x%i==0) return 0;
    }
}
int main(){
    prepare();
    int n;
    cin>>n;
    int x=n;
    while (!isprime(x)) x--;
    printf("%d\n%d ",1+int(v[n-x].size()),x);
    for(auto i:v[n-x]) printf("%d ",i);
}