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
    string s;
    cin>>s;
    int sum = 0;
    int n=s.size();
    rep(i,n)sum+=(s[i]-'0');
    if(sum%3==0){
        cout<<s<<endl;
        return 0;
    }
    if(sum%3==1){
        string t = "";
        bool ok=false;
        rep(i,n){
            if((s[n-i-1]-'0')%3==1&&!ok){
                ok=true;
            }
            else t+=s[n-i-1];
        }
        reverse(t.begin(),t.end());
        int idx=0;
        while(idx+1<t.size()&&t[idx]=='0')++idx;
        t=t.substr(idx);
        string u = "";
        int cnt = 0;
        rep(i,n){
            if((s[n-i-1]-'0')%3==2&&cnt<2){
                ++cnt;
            }
            else u+=s[n-i-1];
        }
        reverse(u.begin(),u.end());
        idx=0;
        while(idx+1<u.size()&&u[idx]=='0')++idx;
        u=u.substr(idx);
        if(cnt<2&&!ok){
            cout<<-1<<endl;
        }
        else if(!ok){      
            if(u.size()==0)cout<<-1<<endl;
            else cout<<u<<endl;
        }
        else if(cnt<2){
            if(t.size()==0)cout<<-1<<endl;
            else cout<<t<<endl;
        }
        else if(t.size()>u.size())cout<<t<<endl;
        else cout<<u<<endl;
    }
    if(sum%3==2){
        string t = "";
        bool ok=false;
        rep(i,n){
            if((s[n-i-1]-'0')%3==2&&!ok){
                ok=true;
            }
            else t+=s[n-i-1];
        }
        reverse(t.begin(),t.end());
        int idx=0;
        while(idx+1<t.size()&&t[idx]=='0')++idx;
        t=t.substr(idx);
        string u = "";
        int cnt = 0;
        rep(i,n){
            if((s[n-i-1]-'0')%3==1&&cnt<2){
                ++cnt;
            }
            else u+=s[n-i-1];
        }
        reverse(u.begin(),u.end());
        idx=0;
        while(idx+1<u.size()&&u[idx]=='0')++idx;
        u=u.substr(idx);
        if(cnt<2&&!ok){
            cout<<-1<<endl;
        }
        else if(!ok){      
            if(u.size()==0)cout<<-1<<endl;
            else cout<<u<<endl;
        }
        else if(cnt<2){
            if(t.size()==0)cout<<-1<<endl;
            else cout<<t<<endl;
        }
        else if(t.size()>u.size())cout<<t<<endl;
        else cout<<u<<endl;
    }
    return 0;
}