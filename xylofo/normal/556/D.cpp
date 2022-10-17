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
typedef long long int LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef pair<LL,LL> PII;

vector<pair<PII,int> > d;
class comp{
    public:
    bool operator()(const LL &a, const LL &b){
        return d[a].first.second > d[b].first.second;
    }
};

int main(){
    LL N,M;
    cin>>N>>M;
    VI l(N),r(N);
    vector<PII> b(M);
    REP(i,N)cin>>l[i]>>r[i];
    REP(i,M)cin>>b[i].first,b[i].second=i+1;
    sort(ALLOF(b));
    d.resize(N-1);
    map<PII,int> mq;
    REP(i,N-1){
        d[i]=make_pair(make_pair(l[i+1]-r[i],r[i+1]-l[i]),i);
    }
    sort(ALLOF(d));
    priority_queue<LL,VI,comp> Q;
    VI ans(N-1);
    LL k=0;
    REP(i,M){
        //cout<<b[i]<<":"<<endl;
        while(k<d.size() && d[k].first.first<=b[i].first){
            //cout<<"pusing "<<d[k].first<<" "<<d[k].second<<endl;
                Q.push(k);
                k++;
        }
        //while(!Q.empty() && Q.top().second<b[i])Q.pop();

        if(!Q.empty()){
            //cout<<"popping "<<d[Q.top()].first<<" "<<d[Q.top()].second<<endl;
            if(d[Q.top()].first.second<b[i].first){
                cout<<"No"<<endl;
                return 0;
            }
            else {
                //cout<<d[Q.top()].second<<endl;
                ans[d[Q.top()].second]=b[i].second;
                Q.pop();
            }
        }
    }
    if(!Q.empty() || k!=N-1){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    REP(i,N-1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/*
*/