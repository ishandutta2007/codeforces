#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(it,st,en) for(int it=(st);it<(int)(en);++it)
#define REP(it,en) FOR(it,0,en)
#define ITE(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define ALLOF(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define X first
#define Y second
typedef long long int LL; 
typedef long double LD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
const int INF=(int)1e9; 
const double EPS=(LD)1e-7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    VI w(N);
    REP(i,N)cin>>w[i];
    deque<int> cur(N,INF);
    VI seen(N,0);
    int cnt=0;
    int ans=0;
    REP(i,M){
        int a;
        cin>>a;
        // cout<<":"<<a<<endl;
        // REP(i,cur.size())cout<<cur[i]<<" \n"[i==N-1];
        a--;
        if(!seen[a]){
            seen[a]=1;
            cur[cnt]=a;
            cnt++;
        }
        int b=0;
        while(cur[b]!=a){
            ans+=w[cur[b]];
            // cout<<"lifting book: "<<b+1<<endl;
            b++;
        }
        cur.erase(cur.begin()+b);
        cur.push_front(a);
    }
    cout<<ans<<endl;
    return 0;
}