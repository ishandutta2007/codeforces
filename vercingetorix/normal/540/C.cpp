#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
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
    int n,m;
    cin>>n>>m;
    char c;
    vvi p(n, vi(m, 0));
    for(int i=0;i<n;i++) {
        for(int j=0; j<m; j++) {
            cin>>c;
            if(c=='.') p[i][j]=1;
        }
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1;
    cin>>x2>>y2;
    x1--; y1--; x2--; y2--;
    vvi u(n, vi(m, 0));
    deque<pi> q;
    q.pb(mp(x1,y1));
    u[x1][y1]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop_front();
        if((x>0)&&(0==u[x-1][y])) {
            u[x-1][y]=1;
            if(p[x-1][y]==1) q.pb(mp(x-1,y));
        }
        if((y>0)&&(0==u[x][y-1])) {
            u[x][y-1]=1;
            if(p[x][y-1]==1) q.pb(mp(x,y-1));
        }
        if((x<n-1)&&(0==u[x+1][y])) {
            u[x+1][y]=1;
            if(p[x+1][y]==1) q.pb(mp(x+1,y));
        }
        if((y<m-1)&&(0==u[x][y+1])) {
            u[x][y+1]=1;
            if(p[x][y+1]==1) q.pb(mp(x,y+1));
        }
    }
    
    /*for(int i=0;i<n;i++) {
        for(int j=0; j<m; j++) {
            cout<<u[i][j];
        }cout<<endl;
    }*/
    if(u[x2][y2]==0) {
        cout<<"NO";
        return 0;
    }
    else {
        
        int ans=0;
        if ((x2>0)&&(p[x2-1][y2]==1)) ans++;
        if ((x2<n-1)&&(p[x2+1][y2]==1)) ans++;
        if ((y2>0)&&(p[x2][y2-1]==1)) ans++;
        if ((y2<m-1)&&(p[x2][y2+1]==1)) ans++;
        if(p[x2][y2]==0) {
            if( ((abs(x1-x2)+abs(y1-y2))<1)&&(ans==0)) cout<<"NO";
            else cout<<"YES";
            return 0;
        }
        if((abs(x1-x2)+abs(y1-y2))<2){
            if(ans>0) cout<<"YES";
            else cout<<"NO";
            return 0;
        }
        
        if(ans>1) cout<<"YES";
        else cout<<"NO";
    }
}