#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
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
    vvi nb(n);
    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        nb[a].pb(b);
        nb[b].pb(a);
    }
    int s1,l1,t1,s2,l2,t2;
    cin>>s1>>t1>>l1;
    cin>>s2>>t2>>l2;
    s1--; s2--; t1--; t2--;
    int ans = 0;
    vvi dist(n, vi(n));
    for(int f=0; f<n; f++) {
        vi u(n,-1);
        deque<int> q;
        q.pb(f);
        u[f]=0;
        while(!q.empty()){
            int v=q.front();
            q.pop_front();
            for(int i=0; i<nb[v].size(); i++) {
                if(-1==u[nb[v][i]]) {
                    q.pb(nb[v][i]);
                    u[nb[v][i]] = u[v] + 1;
                }
            }
        }
        for(int i=0; i<n; i++) {
            dist[f][i] = u[i];
        }
    }
    if((dist[s1][t1]>l1)||(dist[s2][t2]>l2)) {
        cout<<-1;
        return 0;
    }
    ans = dist[s1][t1] + dist[s2][t2];
    
    for(int f=0; f<n; f++) {
        for(int l=0;l<n;l++) {
            int b=dist[f][l];
            if((dist[s1][f]+b+dist[l][t1])>l1) continue;
            if((dist[s2][f]+b+dist[l][t2])>l2) continue;
            ans=min(ans, dist[s1][f]+b+dist[l][t1]+dist[s2][f]+dist[l][t2]);
        }
    }
    swap(s2, t2);
    for(int f=0; f<n; f++) {
        for(int l=0;l<n;l++) {
            int b=dist[f][l];
            if((dist[s1][f]+b+dist[l][t1])>l1) continue;
            if((dist[s2][f]+b+dist[l][t2])>l2) continue;
            ans=min(ans, dist[s1][f]+b+dist[l][t1]+dist[s2][f]+dist[l][t2]);
        }
    }
    cout<<m-ans;
}