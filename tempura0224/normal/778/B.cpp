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
using B=bitset<1000>;
int main(){
    int n,m;
    cin>>n>>m;

    map<string,B> mp0,mp1;
    vector<int> ans1(m), ans0(m);
    mp0["?"]=0;
    mp1["?"]=~B(0);
    string s;
    getline(cin,s);
    rep(i,n){
        string s;
        getline(cin,s);
        string cur="";
        vector<string> a;
        for(auto c:s){
            if(c==' '){
                a.push_back(cur);
                cur="";
            }
            else cur+=c;
        }
        a.push_back(cur);
        if(a.size()==3){
            B res(0);
            rep(i,m)if(a[2][i]=='1'){
                res[i]=1;
                ans0[i]+=1;
                ans1[i]+=1;
            }
            mp0[a[0]]=mp1[a[0]]=res;
        }
        else {
            B res0,res1;
            auto l0=mp0[a[2]],l1=mp1[a[2]],r0=mp0[a[4]],r1=mp1[a[4]];
            rep(i,m){
                if(a[3]=="XOR"){
                    res0[i]=l0[i]^r0[i];
                    res1[i]=l1[i]^r1[i];
                }
                if(a[3]=="OR"){
                    res0[i]=l0[i]|r0[i];
                    res1[i]=l1[i]|r1[i];
                }
                if(a[3]=="AND"){
                    res0[i]=l0[i]&r0[i];
                    res1[i]=l1[i]&r1[i];
                }
                ans0[i]+=res0[i];
                ans1[i]+=res1[i];
            }
            mp0[a[0]]=res0;
            mp1[a[0]]=res1;
        }
    }
    B ma(0),mi(0);
    rep(i,m){
        if(ans0[i]>ans1[i]){
            mi[i]=1;
        }
        else if(ans0[i]<ans1[i]){
            ma[i]=1;
        }
    }
    rep(i,m)cout<<mi[i];
    cout<<endl;
    rep(i,m)cout<<ma[i];
    cout<<endl;
    return 0;
}