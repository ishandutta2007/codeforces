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
const int N=2e5+10,M=2e6;

int a[N],n,h[M+5]={0};
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
    int tmp=n;n=0;
    FOR(i,1,tmp){
        a[++n]=a[i];
        while (i<tmp&&a[i+1]==a[n]) i++;
    }
    FOR(i,1,n) h[a[i]]++;
    FOR(i,1,M) h[i]=(h[i]>0)?i:h[i-1];
    int ans=0;
    FOR(i,1,n)
        for(int j=a[i]<<1;j<=M;j+=a[i]) ans=max(ans,h[j-1]%a[i]);
    cout<<ans;
}