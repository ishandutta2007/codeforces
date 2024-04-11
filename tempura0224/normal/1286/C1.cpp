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
    if(n==1){
        cout<<"? "<<1<<" "<<1<<endl;
        string s;
        cin>>s;
        cout<<"! "<<s<<endl;
        return 0;
    }
    cout<<"? "<<1<<" "<<n<<endl;
    vector<string> v1[n+1];
    rep(i,n*(n+1)/2){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        int m=s.size();
        v1[m].push_back(s);
    }
    rep(i,n+1)sort(v1[i].begin(),v1[i].end());
    cout<<"? "<<2<<" "<<n<<endl;
    vector<string> v2[n+1];
    rep(i,n*(n-1)/2){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        int m=s.size();
        v2[m].push_back(s);
    }
    rep(i,n+1){
        sort(v2[i].begin(),v2[i].end());
        v2[i].push_back("#");
    }
    string ans = "";
    vector<int> cnt(26);
    REP(i,1,n+1){
        string ret;
        rep(j,v1[i].size()){
            if(v1[i][j]!=v2[i][j]){
                ret=v1[i][j];
                break;
            }
        }
        vector<int> nc(26);
        for(auto c:ret)nc[c-'a']++;
        rep(k,26){
            if(cnt[k]!=nc[k])ans += 'a'+k;
        }
        nc.swap(cnt);
    }
    cout<<"! "<<ans<<endl;
    return 0;
}