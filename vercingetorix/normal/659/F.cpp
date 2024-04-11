#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const int MAXN=1000001;
vector<int> lst[MAXN];
int bestsize = 0;
int bestind = -1;
int parent[MAXN];

void make_set (int v) {
    lst[v] = vector<int> (1, v);
    parent[v] = v;
    if(bestsize==0) {
        bestsize = 1;
        bestind = v;
    }
}

int find_set (int v) {
    return parent[v];
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap (a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
        }
        if(lst[a].size()>bestsize) {
            bestsize=lst[a].size();
            bestind=a;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    ll k;
    //string s;
    ll ans = 0;
    
    scanf("%d %d %lld", &n,&m,&k);
    vvi a(n,vi(m,0));
    vector<pair<int, pi>> stog;
    forn(i,0,n) forn(j,0,m) {
        scanf("%d", &a[i][j]);
        stog.pb(mp(a[i][j],mp(i,j)));
    }
    sort(all(stog));
    reverse(all(stog));
    int cur = 0;
    int N=n*m;
    while(cur<N) {
        int add =stog[cur].first;
        pi to = stog[cur].second;
        make_set(to.first*1000+to.second);
        int curr=cur+1;
        while((curr<N)&&(stog[curr].first==add)) {
            pi to = stog[curr].second;
            make_set(to.first*1000+to.second);
            curr++;
        }
        map<int,int> blessed;
        forn(ax, cur, curr) {
            to = stog[ax].second;

            int x= to.first;
            int y=to.second;
            int ind = 1000*x+y;
            if(x>0) if(a[x-1][y]>=add) union_sets(ind, ind-1000);
            if(x<n-1) if(a[x+1][y]>=add) union_sets(ind, ind+1000);
            if(y>0) if(a[x][y-1]>=add) union_sets(ind, ind-1);
            if(y<m-1) if(a[x][y+1]>=add) union_sets(ind, ind+1);
            blessed[find_set(ind)]=1;
        }
        
        ll test = add;
        if(k%test==0) {
            forn(star, cur,curr) {
                pi to = stog[star].second;
                int ind = to.first*1000+to.second;
                int vv=find_set(ind);
                int startstog = ind;
                if(lst[vv].size()>=k/test) {
                    vi used(1000000, 0);
                    vector<int> dfs;
                    bestind=find_set(startstog);
                    
                    
                    dfs.pb(startstog);
                    used[startstog]=1;
                    int s = 1;
                    while(s<k/test) {
                        int past = dfs.back();
                        int x = past/1000;
                        int y=past%1000;
                        dfs.pop_back();
                        vi toadd;
                        if(x>0) if(a[x-1][y]>=add) if(find_set(past-1000)==bestind) if(used[past-1000]==0) toadd.pb(past-1000);
                        if(x<n-1) if(a[x+1][y]>=add) if(find_set(past+1000)==bestind) if(used[past+1000]==0) toadd.pb(past+1000);
                        if(y>0) if(a[x][y-1]>=add) if(find_set(past-1)==bestind) if(used[past-1]==0) toadd.pb(past-1);
                        if(y<m-1) if(a[x][y+1]>=add) if(find_set(past+1)==bestind) if(used[past+1]==0) toadd.pb(past+1);
                        while ((s<k/test)&&(toadd.size()>0)) {
                            used[toadd.back()] = 1;
                            s++;
                            dfs.pb(toadd.back());
                            toadd.pop_back();
                        }
                    }
                    printf("YES\n");
                    forn(i,0,n) {
                        forn(j,0,m) {
                            if(used[1000*i+j]) printf("%d ", add);
                            else printf("0 ");
                        }
                        printf("\n");
                    }
                    
                    return 0;
                }
            }
        }
        cur=curr;
    }
    cout<<"NO";
    // cout<<ans;
}