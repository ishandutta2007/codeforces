#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e2+10;

int n,m,p[N];
int main(){
    cin>>n>>m;
    if (m==0){
        int v=(n==1)?0:-1;
        cout<<v<<" "<<v;
        return 0;
    }
    if (m>9*n){
        cout<<-1<<" "<<-1;
        return 0;
    }
    int tmp=m-1;
    FORD(i,n,1){
        p[i]=min(tmp,9);
        tmp-=p[i];
    }
    p[1]++;
    FOR(i,1,n) cout<<p[i];
    cout<<" ";
    tmp=m;
    FOR(i,1,n){
        int v=min(tmp,9);
        cout<<v;
        tmp-=v;
    }
    //cout<<" ";
}