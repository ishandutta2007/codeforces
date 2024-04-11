#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    int a[n+2];
    a[0]=0;
    rep(i,n)cin>>a[i+1];
    a[n+1]=m;
    int sum[n+2];
    sum[0]=0;
    int sgn=1;
    rep(i,n+1){
        sum[i+1]=sgn*(a[i+1]-a[i]);
        sgn*=-1;
    }
    cout<<endl;
    int pos[n+2];
    pos[0]=0;
    rep(i,n+1)pos[i+1]=pos[i]+sum[i+1];
    rep(i,n+1)sum[n-i]+=sum[n-i+1];
    int ans=sum[0];
    rep(i,n+1){
        if(i%2==0)continue;
        if(a[i]-1!=a[i-1])ans=max(ans,pos[i]-2-sum[i+1]);
        if(a[i]+1!=a[i+1])ans=max(ans,pos[i]-2-sum[i+1]);
    }
    cout<<(ans+m)/2<<endl;
    return 0;
}