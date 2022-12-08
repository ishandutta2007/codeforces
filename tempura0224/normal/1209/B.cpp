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
    vector<int> ans(240);
    rep(i,n){
        int a,b;
        cin>>a>>b;
        rep(j,b){
            ans[j]+=s[i]=='1';
        }
        rep(j,240-b){
            if(j%a==0){
                if(s[i]=='1')s[i]='0';
                else s[i]='1';
            }
            ans[j+b]+=s[i]=='1';
        }
    }
    cout<<*max_element(ans.begin(),ans.end())<<endl;
    return 0;
}