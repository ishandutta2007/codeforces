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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        string s;
        cin>>s;
        vector<int> mil(n+1), mal(n+1), cl(n+1);
        rep(i,n){
            if(s[i]=='+')cl[i+1]=cl[i]+1;
            else cl[i+1]=cl[i]-1;
            mal[i+1]=max(cl[i+1],mal[i]);
            mil[i+1]=min(cl[i+1],mil[i]);
        }
        vector<int> mir(n+1), mar(n+1);
        for(int i=n-1;i>=0;i--){
            if(s[i]=='+'){
                mar[i]=mar[i+1]+1;
                mir[i]=min(mir[i+1]+1,0);
            }
            else {
                mar[i]=max(mar[i+1]-1, 0);
                mir[i]=mir[i+1]-1;
            }
        }
        while(q--){
            int l, r;
            cin>>l>>r;
            int mi = min(mil[l-1], cl[l-1]+mir[r]);
            int ma = max(mal[l-1], cl[l-1]+mar[r]);
            cout<<ma-mi+1<<endl;
        }
    }
    return 0;
}