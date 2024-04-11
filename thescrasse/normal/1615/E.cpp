// https://rmi.lbi.ro/rmi_2021/contest/solutions/

//NlogN
#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
#define DIM 200005
#define f first
#define s second
#define int long long
using namespace std;
int n, i, x, y, c, k, nrfrunze, root, nr;
int tcost[DIM], pos[DIM], pheap[DIM], l, z;
long long sol[DIM], heapmax[DIM], heapmin[DIM], sumk, valh[DIM], res;
pair<long long, int> lantJos[DIM], lantSus[DIM], lantInit[DIM];
vector< pair<int, int> > v[DIM];
void dfs(int nod, int t) {
    if (v[nod].size() == 1) {
        lantJos[nod] = make_pair(0, nod);
        return;
    }
    for (int i = 0; i < v[nod].size(); i++) {
        int fiu = v[nod][i].f;
        if (fiu == t) {
            continue;
        }
        dfs(fiu, nod);
        tcost[fiu] = v[nod][i].s;
        if (lantJos[nod].f <= lantJos[fiu].f + tcost[fiu]) {
            lantJos[nod].f = lantJos[fiu].f + tcost[fiu];
            lantJos[nod].s = lantJos[fiu].s;
        }
    }
}
void dfs2(int nod, int t) {
    if (nod == root || lantJos[nod].s != lantJos[t].s) {
        lantInit[++nr] = lantJos[nod];
        lantInit[nr].f += tcost[nod];
    }
    int pmax = 0, pmax2 = 0;
    for (int i = 0; i < v[nod].size(); i++) {
        int fiu = v[nod][i].f;
        if (fiu == t) {
            continue;
        }
        if (lantJos[fiu].f + tcost[fiu] >= lantJos[pmax].f + tcost[pmax]) {
            pmax2 = pmax;
            pmax = fiu;
        }
        else if (lantJos[fiu].f + tcost[fiu] >= lantJos[pmax2].f + tcost[pmax2]) {
            pmax2 = fiu;
        }
    }
    for (int i = 0; i < v[nod].size(); i++) {
        int fiu = v[nod][i].f;
        if (fiu == t) {
            continue;
        }
        lantSus[fiu] = make_pair(lantSus[nod].f + tcost[fiu], lantSus[nod].s);
        if (pmax != fiu) {
            if (lantSus[fiu].f <= lantJos[pmax].f + tcost[pmax] + tcost[fiu]) {
                lantSus[fiu].f = lantJos[pmax].f + tcost[pmax] + tcost[fiu];
                lantSus[fiu].s = lantJos[pmax].s;
            }
        }
        else {
            if (lantSus[fiu].f <= lantJos[pmax2].f + tcost[pmax2] + tcost[fiu]) {
                lantSus[fiu].f = lantJos[pmax2].f + tcost[pmax2] + tcost[fiu];
                lantSus[fiu].s = lantJos[pmax2].s;
            }
        }
        dfs2(fiu, nod);
    }
}
void urcmin(int poz) {
    int c = poz, p = c / 2;
    while (p > 0 && valh[ heapmin[c] ] < valh[ heapmin[p] ]) {
        swap(heapmin[c], heapmin[p]);
        pos[ heapmin[c] ] = c;
        pos[ heapmin[p] ] = p;
        c = p;
        p /= 2;
    }
}
void cobmin(int poz) {
    int p = poz, c = 2 * p;
    while (c <= k) {
        if (c + 1 <= k && valh[ heapmin[c + 1] ] < valh[ heapmin[c] ]) {
            c++;
        }
        if (valh[ heapmin[c] ] < valh[ heapmin[p] ]) {
            swap(heapmin[c], heapmin[p]);
            pos[ heapmin[c] ] = c;
            pos[ heapmin[p] ] = p;
            p = c;
            c *= 2;
        }
        else {
            break;
        }
    }
}
void urcmax(int poz) {
    int c = poz, p = c / 2;
    while (p > 0 && valh[ heapmax[c] ] > valh[ heapmax[p] ]) {
        swap(heapmax[c], heapmax[p]);
        pos[ heapmax[c] ] = c;
        pos[ heapmax[p] ] = p;
        c = p;
        p /= 2;
    }
}
void cobmax(int poz) {
    int p = poz, c = 2 * p;
    while (c <= nrfrunze - k) {
        if (c + 1 <= nrfrunze - k && valh[ heapmax[c + 1] ] > valh[ heapmax[c] ]) {
            c++;
        }
        if (valh[ heapmax[c] ] > valh[ heapmax[p] ]) {
            swap(heapmax[c], heapmax[p]);
            pos[ heapmax[c] ] = c;
            pos[ heapmax[p] ] = p;
            p = c;
            c *= 2;
        }
        else {
            break;
        }
    }
}
void inloc(int nod, long long val) {
    if (pheap[nod] == 0) {
        sumk += val - valh[nod];
        valh[nod] = val;
        cobmin(pos[nod]);
        urcmin(pos[nod]);
    }
    else {
        valh[nod] = val;
        cobmax(pos[nod]);
        urcmax(pos[nod]);
    }
    if (valh[heapmin[1]] < valh[heapmax[1]]) {
        sumk += valh[heapmax[1]] - valh[heapmin[1]];
        pheap[ heapmin[1] ] = 1;
        pheap[ heapmax[1] ] = 0;
        swap(heapmin[1], heapmax[1]);
        cobmin(1);
        cobmax(1);
    }
}
void dfs3(int nod, int t) {
    sol[nod] = sumk;
    for (int i = 0; i < v[nod].size(); i++) {
        int fiu = v[nod][i].f;
        if (fiu == t) {
            continue;
        }
        inloc(lantJos[fiu].s, lantJos[fiu].f);
        inloc(lantSus[fiu].s, lantSus[fiu].f);
        dfs3(fiu, nod);
        inloc(lantJos[fiu].s, lantJos[fiu].f + tcost[fiu]);
        inloc(lantSus[fiu].s, lantSus[fiu].f - tcost[fiu]);
    }
}
main(){
    cin>> n >> k;
    for (i = 1; i < n; i++) {
        cin>> x >> y; c = 1;
        v[x].push_back(make_pair(y, c));
        v[y].push_back(make_pair(x, c));
    }

    for (i = 2; i <= n; i++) {
        if (v[i].size() == 1) l++;
    }

    for (i = 1; i <= n; i++) {
        if (v[i].size() == 1) {
            nrfrunze ++;
            if (nrfrunze <= k) {
                pos[i] = nrfrunze;
                heapmin[nrfrunze] = i;
                pheap[i] = 0;
            }
            else {
                pos[i] = nrfrunze - k;
                heapmax[nrfrunze - k] = i;
                pheap[i] = 1;
            }
        }
        else {
            if (root == 0) {
                root = i;
            }
        }
    }
    dfs(root, 0);
    dfs2(root, 0);
    for (i = 1; i <= nrfrunze; i++) {
        inloc(lantInit[i].s, lantInit[i].f);
    }
    dfs3(root, 0);
    /* for (i = 1; i <= n; i++) {
        cout<< sol[i] <<"\n";
    } */

    if (l > k) {
        z = n - (sol[1] + 1);
        z = min(z, n / 2);
        res = (n - k - z) * (k - z);
    } else {
        k = min(k, n / 2);
        res = (n - k) * k;
    }

    cout << res << "\n";
}