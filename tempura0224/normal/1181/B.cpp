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


string add(string& s, string t){
    string ans = "";
    if(s.size()>t.size())swap(s,t);
    while(t.size()>s.size())s = '0'+s;
    int dig = 0;
    int n = s.size();
    rep(i,n){
        int ret = dig + (s[n-i-1]-'0')+(t[n-i-1]-'0');
        dig = ret/10;
        ret%=10;
        ans=(char)(ret+'0')+ans;
    }
    if(dig)ans = '1'+ans;
    return ans;
}
void chmin(string& s, string& t){
    if(s.size()==t.size())s=min(s,t);
    else if(s.size()>t.size())s = t;
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans(n+1,'9');
    int mid = n/2;
    for(int i = mid-1;i>=0;--i){
        if(s[i+1]!='0'){
            string t = s.substr(0,i+1);
            string u = s.substr(i+1);
            string res = add(t,u);
            chmin(ans,res);
            break;
        }
    }
    for(int i = mid;i<n-1;++i){
        if(s[i+1]!='0'){
            string t = s.substr(0,i+1);
            string u = s.substr(i+1);
            string res = add(t,u);
            chmin(ans,res);
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}