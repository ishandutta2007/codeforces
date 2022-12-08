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
    string t = s;
    int n=s.size();
    string ans1 = "", ans2= "";
    int i = 0, j = n-1;
    while(i<j){
        if(s[i]==t[j]){
            ans1+=s[i];
            ans2+=s[i];
            ++i;--j;
        }
        else if(j>1&&s[i]==t[j-1]){
            ans1+=s[i];
            if(i!=j-1)ans2+=s[i];
            ++i;j-=2;
        }
        else if(i+1<n&&s[i+1]==t[j]){
            ans1+=s[i+1];
            if(i+1!=j)ans2+=s[i+1];
            i+=2;j-=1;
        }
        else if(i+1<n&&j>1&&i+1<=j-1&&s[i+1]==t[j-1]){
            ans1+=s[i+1];
            if(i+1!=j-1)ans2+=s[i+1];
            i+=2;j-=2;
        }
        else assert(0);
    }
    reverse(ans2.begin(),ans2.end());
    cout<<ans1<<ans2<<endl;
    return 0;
}