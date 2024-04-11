
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

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> a(2*n);
    rep(i,n)a[i]=(s[i]=='('?1:-1);
    rep(i,n)a[n+i]=a[i];
    vector<int> sum(2*n);
    rep(i,2*n)sum[i]=a[i];
    rep(i,2*n-1)sum[i+1]+=sum[i];
    if(sum[2*n-1]!=0){
        cout<<0<<endl;
        cout<<"1 1"<<endl;
        return 0;
    }
    int mi = *min_element(sum.begin(),sum.end());
    int idx=0;
    while(sum[idx]!=mi)++idx;
    int l1=idx,r1=idx,l0=idx,r0=idx,ma2=0,pre0=0,pre1=0, cnt0=0,cnt1=0,cnt2=0,ma1=0;
    REP(i,idx,idx+n+1){
        if(sum[i]==mi+2)++cnt2;
        if(sum[i]==mi+1){
            ++cnt1;
            if(cnt2>ma2){
                ma2=cnt2;
                l1=pre1+1, r1=i;
            }
            cnt2=0;pre1=i;
        }
        if(sum[i]==mi){
            if(cnt1>ma1){
                ma1=cnt1;
                l0=pre0+1, r0=i;
            }
            cnt1=0;pre0=i;
            ++cnt0;
        }
    }
    if(ma2+cnt0-1>=ma1){
        cout<<ma2+cnt0-1<<endl;
        cout<<(l1%n)+1<<" "<<(r1%n)+1<<endl;
    }
    else {
        cout<<ma1<<endl;
        cout<<(l0%n)+1<<" "<<(r0%n)+1<<endl;
    }
    return 0;
}