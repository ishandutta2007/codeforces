#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
double calc(vector<double>& a, double x){
    int n=a.size();
    vector<double> b(n);
    rep(i,n)b[i]=a[i]+x;
    double mi=0, ma=0;
    double ama=0, ami=0;
    double sum=0;
    rep(i,n){
        sum+=b[i];
        ama=max(sum-mi,ama);
        ami=min(sum-ma,ami);
        ma=max(ma,sum);
        mi=min(mi,sum);
    }
    return max(ama,-ami);
}

int main(){
    int n;
    cin>>n;
    vector<double> a(n);
    rep(i,n)cin>>a[i];
    double st=-12000, en=12000;
    rep(_,90){
        double ml=(2*st+en)/3, mr=(st+2*en)/3;
        if(calc(a,ml)<calc(a,mr))en=mr;
        else st=ml;
    }
    cout<<fixed<<setprecision(12)<<calc(a,st)<<endl;
    return 0;
}