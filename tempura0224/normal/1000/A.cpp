#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

int main(){
    int n;
    cin>>n;
    map<string,int> a,b;
    rep(i,n){
        string s;
        cin>>s;
        a[s]++;
    }
    rep(i,n){
        string s;
        cin>>s;
        b[s]++;
    }
    int ans=0;
    string s[]={"S","M","L","XS","XXS","XXXS","XL","XXL","XXXL"};
    rep(i,9)ans+=abs(a[s[i]]-b[s[i]]);
    cout<<ans/2<<endl;
    return 0;
}