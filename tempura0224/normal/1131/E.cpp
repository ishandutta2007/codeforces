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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


vector<ll> cnt(26);
int main(){
    int n;
    cin>>n;
    rep(i,n){
        string s;
        cin>>s;
        int m=s.size();
        bool one=true;
        rep(j,m)if(s[j]!=s[0])one=false;
        if(one){
            int pos=s[0]-'a';
            cnt[pos]=cnt[pos]*(m+1)+m;
            rep(j,26)if(j!=pos)cnt[j]=!!cnt[j];
        }
        else{
            vector<ll> nc(26);
            int pre=-1;
            ll cn=0;
            rep(j,m){
                int cur=s[j]-'a';
                if(cur==pre){
                    nc[cur]=max(++cn,nc[cur]);
                }
                else {
                    cn=0;
                    pre=cur;
                    nc[cur]=max(++cn,nc[cur]);
                }
            }
            cn=0;
            while(s[cn]==s[0])++cn;
            int cur=s[0]-'a';
            if(cnt[cur])nc[cur]=max(nc[cur],cn+1);
            ll cr=0;
            int curr=s.back()-'a';
            while(s[m-1-cr]==s.back())++cr;
            if(cnt[curr])nc[curr]=max(nc[curr],cr+1);
            if(curr==cur&&cnt[cur]){
                nc[cur]=max(cn+cr+1,nc[cur]);
            }
            rep(j,26){
                if(cnt[j])nc[j]=max(1LL,nc[j]);
            }
            cnt.swap(nc);
        }
    }
    cout<<*max_element(cnt.begin(), cnt.end())<<endl;
    return 0;
}