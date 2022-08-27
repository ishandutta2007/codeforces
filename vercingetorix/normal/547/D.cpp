#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <stack>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n;
    cin>>n;
    vpi points;
    int x,y;
    vector<set<int>> rows(200001);
    vector<set<int>> cols(200001);
    vi rv(200001, 0);
    vi cv(200001, 0);
    stack<pi> last;
    map<pi, int> ans;
    for(int i=0; i<n; i++) {
        cin>>x>>y;
        points.pb(mp(x,y));
        cols[x].insert(y);
        rows[y].insert(x);
    }
    set<int> odd_rows;
    set<int> odd_cols;
    for(int i=1; i<=200000; i++) {
        if(rows[i].size()%2 == 1) odd_rows.insert(i);
        if(cols[i].size()%2 == 1) odd_cols.insert(i);
    }
    while((odd_cols.size()!=0)||(odd_rows.size()!=0)) {
        if(odd_cols.size()!=0) {
            x=*(odd_cols.begin());
            y=*(cols[x].begin());
            last.push(mp(x,y));
            cols[x].erase(y);
            rows[y].erase(x);
            odd_cols.erase(x);
            if(rows[y].size()%2==0) {
                odd_rows.erase(y);
            }
            else {
                odd_rows.insert(y);
            }
        }
        if(odd_rows.size()!=0) {
            y=*(odd_rows.begin());
            x=*(rows[y].begin());
            last.push(mp(x,y));
            cols[x].erase(y);
            rows[y].erase(x);
            odd_rows.erase(y);
            if(cols[x].size()%2==0) {
                odd_cols.erase(x);
            }
            else {
                odd_cols.insert(x);
            }
        }
    }
    for(int i=1; i<=200000; i++) {
        while(cols[i].size()>0) {
            int sx=i;
            auto it =cols[i].end();
            int sy=*(--it);
            int curx=sx;
            int cury=sy;
            do {
                cury=*(cols[curx].begin());
                ans[mp(curx,cury)]=-1;
                cols[curx].erase(cury);
                rows[cury].erase(curx);
                curx=*(rows[cury].begin());
                ans[mp(curx,cury)]=1;
                cols[curx].erase(cury);
                rows[cury].erase(curx);
            } while((curx!=sx)||(cury!=sy)) ;
        }
    }
    while(!last.empty()) {
        pi ad = last.top();
        x=ad.first;
        y=ad.second;
        last.pop();
        if(cv[x]==0) {
            if(rv[y]==0) {
                ans[mp(x,y)] = 1;
                rv[y]=1;
                cv[x]=1;
            }
            else {
                ans[mp(x,y)] = -rv[y];
                cv[x]= -rv[y];
                rv[y]=0;
            }
        }
        else {
            ans[mp(x,y)] = -cv[x];
            rv[y]=-cv[x];
            cv[x]=0;
        }
    }
    for(int i=0; i<n; i++) {
        cout<<((ans[points[i]]==1)? "r" : "b");
    }
}