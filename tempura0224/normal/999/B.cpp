#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
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
const ll longinf=1LL<<60;
const ll mod=1e9+7;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1};

int main(){
    int n;
    cin>>n;
    vector<int> v;
    rep(i,n){
        if(n%(i+1)==0)v.push_back(i+1);
    }
    int a[n],b[n];
    rep(i,n)a[i]=i;
    rep(i,v.size()){
        rep(j,v[i])b[j]=a[v[i]-j-1];
        rep(j,v[i])a[j]=b[j];
    }
    string s;
    cin>>s;
    rep(i,n)cout<<s[a[i]];
    cout<<endl;
    return 0;
}