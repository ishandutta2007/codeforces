#include <iostream>
#include <vector>
#include <cstdio>

const int ms = 100100;

struct Info {
    int t, x, y;
    
    void read() {
        //std::cin >> t;
        scanf("%d", &t);
        if(t == 2) {
            scanf("%d", &x);
            //std::cin >> x;
        } else {
            scanf("%d %d", &x, &y);
            //std::cin >> x >> y;
        }
    }
};

std::vector<int> edges[ms];
int tim = 0;
bool hmm[ms];
int in[ms], out[ms];

void dfs(int on) {
    in[on] = ++tim;
    for(auto to : edges[on]) {
        dfs(to);
    }
    out[on] = tim;
    //std::cout << "on " << on << " got [" << in[on] << ", " << out[on] << "]\n";
}

int par[ms];
int get_par(int x) {
    if(x == par[x]) {
        return x;
    } else {
        return par[x] = get_par(par[x]);
    }
}
void make_union(int a, int b) {
    par[get_par(a)] = get_par(b);
}

Info qries[ms];
int pack[ms], ori[ms];

int main() {
    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++) {
        qries[i].read();
        if(qries[i].t == 1) {
            edges[qries[i].y].push_back(qries[i].x);
            hmm[qries[i].x] = true;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!hmm[i]) {
            dfs(i);
        }
        par[i] = i;
    }
    int wut = 1;
    for(int i = 0; i < m; i++) {
        if(qries[i].t == 1) {
            make_union(qries[i].x, qries[i].y);
        } else if(qries[i].t == 2) {
            pack[wut++] = qries[i].x;
            ori[wut - 1] = get_par(qries[i].x);
            //std::cout << "for pack " << wut - 1 << " got ori " << ori[wut - 1] << "\n";
        } else {
            //std::cout << get_par(qries[i].x) << ", " << get_par(pack[qries[i].y]) << "\n";
            //std::cout << "(" << in[qries[i].x] << ", " << in[pack[qries[i].y]] << ", " << out[qries[i].x] << ")\n";
            //std::cout << in[ori[qries[i].y]] << '\n';
            if(in[ori[qries[i].y]] <= in[qries[i].x] && get_par(qries[i].x) == get_par(pack[qries[i].y]) && in[qries[i].x] <= in[pack[qries[i].y]] && in[pack[qries[i].y]] <= out[qries[i].x]) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
}