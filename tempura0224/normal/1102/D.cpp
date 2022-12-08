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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt[3]={};
    rep(i,n)cnt[s[i]-'0']++;
    int m=n/3;
    rep(i,n){
        if(s[i]=='2'){
            if(cnt[2]>m&&cnt[0]<m){
                s[i]='0';
                --cnt[2];
                ++cnt[0];
            }
            else if(cnt[2]>m&&cnt[1]<m){
                s[i]='1';
                --cnt[2];
                ++cnt[1];
            }
        }
        if(s[i]=='1'){
            if(cnt[1]>m&&cnt[0]<m){
                s[i]='0';
                --cnt[1];
                ++cnt[0];
            }
        }
    }
    for(int i=n-1;i>=0;--i){
        if(s[i]=='0'){
            if(cnt[0]>m&&cnt[2]<m){
                s[i]='2';
                --cnt[0];
                ++cnt[2];
            }
            else if(cnt[0]>m&&cnt[1]<m){
                s[i]='1';
                --cnt[0];
                ++cnt[1];
            }
        }
        if(s[i]=='1'){
            if(cnt[1]>m&&cnt[2]<m){
                s[i]='2';
                --cnt[1];
                ++cnt[2];
            }
        }
    }
    cout<<s<<endl;
    return 0;
}