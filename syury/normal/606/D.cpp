#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
#include<utility>
#include<map>
#include<cstdlib>
#include<ctime>
#include<random>
#include<string>
#include<iostream>
#include<cstring>

using namespace std;

typedef long long int lint;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<lint> vl;
typedef pair<int, int> pi;
typedef pair<lint, lint> pl;

struct edge{
    int w;
    bool inmst;
    int v, id;
    int b, e;
    int nxt;
    edge(){}
    edge(int _w){w = _w;}
    void get(){
        int t;
        scanf("%d%d", &w, &t);
        inmst = (t == 1);
    }
};

bool operator < (const edge & a, const edge & b){
    return a.w < b.w;
}

int n, m;
set<int, greater<int> > can;
vector<edge> e;
vector<edge> we;
int me = -100;

int binsearch(int x){
    int l = 0, r = n - 1;
    while(r - l > 1){
        int mid = (r + l) >> 1;
        if(we[mid].w > x){r = mid - 1;}
        else{l = mid;}
    }
    if(we[r].w <= x){return r;}
    if(we[l].w <= x){return l;}
    return -1;
}

int main(){
    scanf("%d%d", &n, &m);
    e.resize(m); we.resize(n);
    we[0] = edge(1e9 + 9);
    int cv = 1;
    for(int i = 0; i < m; i++){
        e[i].get();
        e[i].id = i;
        if(e[i].inmst){e[i].v = cv; we[cv++] = e[i];}
    }
    sort(we.begin(), we.end());
    for(int i = 0; i < n; i++){
        if(i > 0){can.insert(i);}
        we[i].nxt = i - 1;
    }
    for(int i = 0; i < m; i++){
        if(e[i].inmst){e[i].b = 1; e[i].e = e[i].v + 1; continue;}
        int pos = binsearch(e[i].w);
        if(pos == -1){printf("-1"); return 0;}
        auto it = can.lower_bound(pos);
        if(it == can.end()){printf("-1"); return 0;}
        int f = *it, s = we[f].nxt;
        e[i].b = we[f].v + 1; e[i].e = we[s].v + 1;
        we[f].nxt--;
        if(we[f].nxt < 0){can.erase(f);}
    }
    for(int i = 0; i < m; i++){
        printf("%d %d\n", e[i].b, e[i].e);
    }
    return 0;
}