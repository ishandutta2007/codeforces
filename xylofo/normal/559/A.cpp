#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,b) FOR(i,0,b)
#define X first 
#define Y second
#define PB push_back
#define ALLOF(a) (a).begin(),(a).end()
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

int main(){
    LL a1,a2,a3,a4,a5,a6;
    cin>>a1>>a2>>a3>>a4>>a5>>a6;
    LL ans=0;
    LL b=a2;
    REP(i,a1+a6){
        if(i<a1 && i<a3){
            ans+=b*2+1;
            // cout<<b*2+1<<endl;
            b++;
        }
        else if(i>=a1 && i>=a3){
            ans+=b*2-1;
            // cout<<b*2-1<<endl;
            b--;
        }
        else{
            // cout<<b*2<<endl;
            ans+=b*2;
        }
    }
    cout<<ans<<endl;
    return 0;
}