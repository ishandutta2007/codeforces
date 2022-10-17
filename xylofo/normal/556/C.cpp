#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#define FOR(i,a,b) for(auto i=(a);i<(b);++i)
#define REP(i,b) FOR(i,0,b)
#define ALLOF(v) v.begin(), v.end()

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long int LL;
typedef pair<int,int> PII;

int main(){
    int N,K;
    cin>>N>>K;
    VVI v(K);
    //priority_queue<VI,VVI,greater<VI> > Q;
    int cheap=0;
    REP(i,K){
        int t;
        cin>>t;
        v[i].resize(t);
        REP(j,t)cin>>v[i][j];
        //Q.push(v[i]);
        if(v[i][0]==1){
            int k=1;
            int j=0;
            while(j<v[i].size() && v[i][j]==k)j++,k++;
            cheap=j-1;
        }

    }
    /*int k=0;
    int cnt=0;
    while(!Q.empty()){
        VI a=Q.top();
        Q.pop();
        k++;
        int i=0;
        while(i<a.size() && a[i]==k)i++;
        if(cnt+=)   
    }*/

    N-=cheap;
    int open=N-K;
    int close=N-1;
    //cout<<open<<" "<<close<<" "<<cheap<<endl;
    cout<<open+close<<endl;
    return 0;
}

/*
int N,M;
    cin>>N>>M;
    VI l(N),r(N),b(m);
    REP(i,N)cin>>l[i]>>r[i];
    REP(i,M)cin>>b[i];
    sort(ALLOF(b));
*/