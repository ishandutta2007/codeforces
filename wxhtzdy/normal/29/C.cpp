#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define fb(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define xx first
#define yy second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>



using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n;
pii graf[200005];
int deg[200005];
vector<int> grane[200005];
bool bio[200005];
vector<int> put;

void dfs(int x){
    bio[x] = true;
    put.pb(x);
    for(auto c:grane[x]){
        if(!bio[c])dfs(c);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    vector<int> svi;
    ff(i,0,n - 1){
        cin >> graf[i].xx >> graf[i].yy;
        svi.pb(graf[i].xx);
        svi.pb(graf[i].yy);
    }
    svi.erase(unique(svi.begin(), svi.end()), svi.end());
    sort(svi.begin(), svi.end());
    map<int, int> hes;

    ff(i,0,(int)svi.size() - 1){
        hes[svi[i]] = i;
    }

    ff(i,0,n - 1){
        graf[i].xx = hes[graf[i].xx];
        graf[i].yy = hes[graf[i].yy];
        deg[graf[i].xx]++;
        deg[graf[i].yy]++;
        grane[graf[i].xx].pb(graf[i].yy);
        grane[graf[i].yy].pb(graf[i].xx);
    }

    int od;
    ff(i,0,2 * n){
        if(deg[i] == 1){
            od = i;
            break;
        }
    }
    ff(i,0,n - 1)bio[i] = false;
    dfs(od);

    ff(i,0,(int)put.size()-1){
        cout << svi[put[i]] << " ";
    }
    return 0;
}