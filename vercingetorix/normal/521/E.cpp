#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
//#include <unordered_map>
#include <map>
#include <list>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

void cut_cycle (deque<int> & cycle, int a, int b) {
    int s = cycle.size();
    int pos = 0;
    while (cycle[pos] != a) {
        pos++;
    }
    int pos2 = pos;
    int posb = pos;
    int l = 0;
    while (cycle[posb] != b) {
        posb++;
        l++;
        if (posb == s) {
            posb = 0;
        }
    }
    cout << l + 1 << " " << a;
    while (cycle[pos] != b) {
        pos++;
        if (pos == s) {
            pos = 0;
        }
        cout << " " << cycle[pos];
    }
    cout << endl;
    cout << s - l + 1 << " " << a;
    while (cycle[pos2] != b) {
        pos2--;
        if (pos2 == -1) {
            pos2 = s - 1;
        }
        cout << " " << cycle[pos2];
    }
}

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n, m, a, b;
    int ans = 0;
    cin >> n >> m;
    vector<vi> nb(n+1);
    vb parsed(n+1, false);
    vi truepar(n+1, -1);
    vi v_lvl(n+1, -1);
    vi par(n+1, -1);
    vector<deque<int> > cycles;
    vi breaker(n+1, -1);
    vi cnum(n+1, -1);
    vector<pair<int,int> > roads;
    /*unordered_*/map<pair<int, int>, bool> road_used;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        roads.pb(mp(a,b));
        road_used[mp(a,b)] = false;
        road_used[mp(b,a)] = false;
        nb[a].pb(b);
        nb[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!parsed[i]) {
            deque<int> dfs;
            dfs.pb(i);
            parsed[i] = true;
            truepar[i] = i;
            v_lvl[i] = 1;
            while (dfs.size() > 0) {
                int v = dfs.back();
                int h = v_lvl[v] + 1;
                dfs.pop_back();
                for (int j = 0; j < nb[v].size(); j++) {
                    if (!parsed[nb[v][j]]) {
                        parsed[nb[v][j]] = true;
                        v_lvl[nb[v][j]] = h;
                        dfs.pb(nb[v][j]);
                        truepar[nb[v][j]] = v;
                        road_used[mp(v, nb[v][j])] = true;
                        road_used[mp(nb[v][j], v)] = true;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        par[i] = truepar[i];
    }
    for (int i = 0; i < m; i++) {
        auto road = roads[i];
        pair<int, int> inv_road = mp(road.second, road.first);
        if (!road_used[road]) {
            road_used[road] = true;
            road_used[inv_road] = true;
        }
        else {
            continue;
        }
        a = road.first;
        b = road.second;
        if (v_lvl[a] < v_lvl[b]) {
            std::swap(a, b);
        }
        bool triple = false;
        int cura = a;
        int curb = b;
        for (int j = 0; j < v_lvl[a] - v_lvl[b]; j++) {
            if (cura == par[cura]) {
                triple = true;
                break;
            }
            cura = par[cura];
        }
        if (triple) {
            // 3 routes cura <-> breaker[cura]
            deque<int> long_path;
            int curaa = a;
            while (curaa != cura) {
                long_path.push_front(curaa);
                curaa = par[curaa];
            }
            long_path.push_front(cura);
            //long_path.push_back(b);
            vb onc(n+1, false);
            deque<int> & tric = cycles[cnum[cura]];
            for (int j = 0; j < tric.size(); j++) {
                onc[tric[j]] = true;
            }
            int curbb = b;
            curaa = breaker[cura];
            while (v_lvl[curbb] > v_lvl[curaa]) {
                long_path.push_back(curbb);
                if (onc[curbb]) {
                    cout << "YES" << endl;
                    cout << long_path.size() << " ";
                    for (int j = 0; j < long_path.size(); j++) {
                        cout << long_path[j] << " ";
                    }
                    cout << endl;
                    cut_cycle(cycles[cnum[cura]], cura, curbb);
                    return 0;
                }
                curbb = truepar[curbb];
            }
            deque<int> long_path_end;
            while (v_lvl[curaa] > v_lvl[curbb]) {
                long_path_end.push_front(curaa);
                curaa = truepar[curaa];
            }
            while  (curaa != curbb) {
                long_path_end.push_front(curaa);
                long_path.push_back(curbb);
                curaa = truepar[curaa];
                curbb = truepar[curbb];
            }
            long_path.push_back(curaa);
            for (int j = 0; j < long_path_end.size(); j++) {
                long_path.push_back(long_path_end[j]);
            }
            cout << "YES" << endl;
            cout << long_path.size() << " ";
            for (int j = 0; j < long_path.size(); j++) {
                cout << long_path[j] << " ";
            }
            cout << endl;
            cut_cycle(cycles[cnum[cura]], cura, breaker[cura]);
            return 0;
        }
        else {
            while (cura != curb) {
                if (cura == par[cura]) {
                    triple = true;
                    break;
                }
                if (curb == par[curb]) {
                    triple = true;
                    break;
                }
                cura = par[cura];
                curb = par[curb];
            }
        }
        if (triple) {
            // 3 routes
            if (cura != par[cura]) {
                swap(a, b);
                swap(cura, curb);
            }
            deque<int> long_path;
            int curaa = a;
            while (curaa != cura) {
                long_path.push_front(curaa);
                curaa = par[curaa];
            }
            long_path.push_front(cura);
            //long_path.push_back(b);
            vb onc(n+1, false);
            deque<int> & tric = cycles[cnum[cura]];
            for (int j = 0; j < tric.size(); j++) {
                onc[tric[j]] = true;
            }
            int curbb = b;
            curaa = breaker[cura];
            while (v_lvl[curbb] > v_lvl[curaa]) {
                long_path.push_back(curbb);
                if (onc[curbb]) {
                    cout << "YES" << endl;
                    cout << long_path.size() << " ";
                    for (int j = 0; j < long_path.size(); j++) {
                        cout << long_path[j] << " ";
                    }
                    cout << endl;
                    cut_cycle(cycles[cnum[cura]], cura, curbb);
                    return 0;
                }
                curbb = truepar[curbb];
            }
            deque<int> long_path_end;
            while (v_lvl[curaa] > v_lvl[curbb]) {
                long_path_end.push_front(curaa);
                curaa = truepar[curaa];
            }
            while  (curaa != curbb) {
                long_path_end.push_front(curaa);
                long_path.push_back(curbb);
                curaa = truepar[curaa];
                curbb = truepar[curbb];
            }
            long_path.push_back(curaa);
            for (int j = 0; j < long_path_end.size(); j++) {
                long_path.push_back(long_path_end[j]);
            }
            cout << "YES" << endl;
            cout << long_path.size() << " ";
            for (int j = 0; j < long_path.size(); j++) {
                cout << long_path[j] << " ";
            }
            cout << endl;
            cut_cycle(cycles[cnum[cura]], cura, breaker[cura]);
            return 0;
        }
        else {
            cycles.push_back(std::deque<int>());
            int cyclenum = cycles.size() - 1;
            int br = cura;
            cura = a;
            curb = b;
            while (cura != br) {
                cycles[cyclenum].push_front(cura);
                par[cura] = cura;
                cnum[cura] = cyclenum;
                breaker[cura] = br;
                cura = truepar[cura];
            }
            while (curb != br) {
                cycles[cyclenum].push_back(curb);
                par[curb] = curb;
                cnum[curb] = cyclenum;
                breaker[curb] = br;
                curb = truepar[curb];
            }
            cycles[cyclenum].pb(br);
        }
    }
    cout << "NO";
}