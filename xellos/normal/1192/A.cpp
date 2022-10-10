/* Constructs the minimum required grid graph.
   Tracks connected components using union-find.
   Decides which cells may be deleted based on neighbourhoods,
   updates that information when necessary and keeps these cells
   in a set<>.
   O(N log N)
*/
#include <bits/stdc++.h>
using namespace std;
 
class HashPair {
    static inline size_t hash_combine(size_t h_first, size_t h_second) {
        return h_first ^ (h_second + 0x9e3779b9 + (h_first << 6) + (h_second >> 2));
    }
 
    static inline size_t hash_int(unsigned int x) {
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        return x;
    }
 
public:
    size_t operator() (const pair<int, int> & p) const {
        size_t h_first  = hash_int(p.first);
        size_t h_second = hash_int(p.second);
 
        return hash_combine(h_first, h_second);
    }
};
 
class lego {
    int N, V;
    vector< pair<int, int> > cells, empty_cells;
    unordered_map< pair<int, int>, int, HashPair> cell_indices, empty_cell_indices;
    vector<char> removed;
 
    set<int> removable;
    vector<char> is_removable;
 
    vector< vector<int> > G4, G8;
 
    void construct_graphs(bool only_solvability = false) {
        constexpr static int dx[8] = {-1, -1, -1,  0,  1, 1, 1, 0};
        constexpr static int dy[8] = { 1,  0, -1, -1, -1, 0, 1, 1};
 
        if(!init_solvability_done) {
            for(int i = 0; i < N; i++) for(int j = 0; j < 8; j++) {
                pair<int, int> p = {cells[i].first + dx[j], cells[i].second + dy[j]};
                auto it = cell_indices.find(p);
                int cell_id = (it == end(cell_indices)) ? -1 : it->second;
                if(cell_id == -1) {
                    auto jt = empty_cell_indices.find(p);
                    if(jt == end(empty_cell_indices)) {
                        empty_cell_indices[p] = empty_cells.size();
                        cell_id = N + empty_cells.size();
                        empty_cells.push_back(p);
                        G4.push_back({});
                        G8.push_back(vector<int>(8, cell_id));
                    }
                    else cell_id = N + jt->second;
                    G8[cell_id][4^j] = i;
                    if(j % 2) G4[cell_id].push_back(i);
                }
                G8[i][j] = cell_id;
                if(j % 2) G4[i].push_back(cell_id);
            }
        }
        if(!init_done && !only_solvability) {
            for(int i = 0; i < (int)empty_cells.size(); i++) for(int j = 0; j < 8; j++) {
                if(G8[N+i][j] != N+i) continue;
                pair<int, int> p = {empty_cells[i].first + dx[j], empty_cells[i].second + dy[j]};
                auto it = empty_cell_indices.find(p);
                if(it == end(empty_cell_indices)) continue;
                int cell_id = N + it->second;
                G8[N+i][j] = cell_id;
                if(j % 2) G4[N+i].push_back(cell_id);
            }
        }
    }
 
    int outer_component;
    vector< vector<int> > components4, components8;
    vector<int> comp4, comp8;
    vector<int> deg4, deg8; // degree = number of full neighbouring cells
 
    void find_components(bool only_solvability = false) {
        queue<int> q;
 
        if(!init_solvability_done) {
            components4.clear(); components4.resize(V);
            components8.clear(); components8.resize(V);
            comp4.clear(); comp4.resize(V, -1);
            comp8.clear(); comp8.resize(V, -1);
            deg4.clear(); deg4.resize(V, 0);
            deg8.clear(); deg8.resize(V, 0);
            for(int i = 0; i < V; i++) if(comp8[i] == -1 && !is_empty(i)) {
                comp8[i] = i;
                components8[i] = {i};
                q.push(i);
                while(!q.empty()) {
                    for(auto v : G8[q.front()]) if(comp8[v] == -1 && !is_empty(v)) {
                        comp8[v] = i;
                        components8[i].push_back(v);
                        q.push(v);
                    } 
                    q.pop();
                }
            }
        }
        if(!init_done && !only_solvability) {
            for(int i = 0; i < V; i++) if(comp4[i] == -1 && is_empty(i)) {
                comp4[i] = i;
                components4[i] = {i};
                q.push(i);
                while(!q.empty()) {
                    for(auto v : G4[q.front()]) if(comp4[v] == -1 && is_empty(v)) {
                        comp4[v] = i;
                        components4[i].push_back(v);
                        q.push(v);
                    } 
                    q.pop();
                }
            }
            for(int i = 0; i < V; i++) {
                for(auto v : G4[i]) if(!is_empty(v)) deg4[i]++;
                for(auto v : G8[i]) if(!is_empty(v)) deg8[i]++;
            }
        }
    }
 
    void add_edge(int v1, int v2) {
        int c1 = comp4[v1], c2 = comp4[v2];
        if(c1 == c2) return;
        if(components4[c1].size() < components4[c2].size()) swap(c1, c2);
        for(auto v : components4[c2]) {
            comp4[v] = c1;
            components4[c1].push_back(v);
        }
        if(c2 == outer_component) outer_component = c1;
        for(auto v : components4[c2])
            for(auto f : G8[v]) if(!is_empty(f)) update(f);
    }
 
    void update(int v) {
        static vector<char> seen = vector<char>(V, 0);
 
        bool reachable = false, articulation = false;
 
        for(auto adj : G4[v]) if(is_empty(adj))
            if(comp4[adj] == outer_component) reachable = true;
 
        if(deg8[v] <= 1) {
            if(reachable) {
                if(!is_removable[v]) {
                    removable.insert(v);
                    is_removable[v] = 1;
                }
            }
            else if(is_removable[v]) {
                removable.erase(v);
                is_removable[v] = 0;
            }
            return;
        }
 
        for(int j = 0; j < 8; j++) if(is_empty(G8[v][j])) {
            if(is_empty(G8[v][(j+1)%8])) continue; // 1 cell per region
            if(j % 2 == 0 && !is_empty(G8[v][(j+7)%8])) continue; // ignore corner gaps
            int c = comp4[G8[v][j]];
            if(seen[c]) {
                articulation = true;
                break;
            }
            seen[c]++;
        }
        for(int j = 0; j < 8; j++) if(is_empty(G8[v][j]))
            seen[comp4[G8[v][j]]] = 0;
 
        if(reachable && !articulation) {
            if(!is_removable[v]) {
                removable.insert(v);
                is_removable[v] = 1;
            }
        }
        else if(is_removable[v]) {
            removable.erase(v);
            is_removable[v] = 0;
        }
    }
 
    inline bool is_empty(int cell) {
        return (cell >= N || removed[cell]);
    }
 
    bool init_done, init_solvability_done;
 
    void init_solvability() {
        if(init_solvability_done) return;
        construct_graphs(true);
        V = G4.size();
        removed.resize(V, false);
        find_components(true);
        init_solvability_done = true;
    }
 
    void init() {
        if(init_done) return;
 
        construct_graphs();
        if(!init_solvability_done) {
            V = G4.size();
            removed.resize(V, false);
        }
 
        find_components();
        int min_coord = cells[0].first;
        for(int i = N; i < V; i++) if(min_coord >= empty_cells[i-N].first) {
            min_coord = empty_cells[i-N].first;
            outer_component = comp4[i];
        }
 
        is_removable.resize(N, 0);
        for(int i = 0; i < N; i++) update(i);
        
        init_done = init_solvability_done = true;
    }
 
  public:
    lego(vector< pair<int, int> > cells_) : N(cells_.size()), cells(cells_) {
        for(int i = 0; i < N; i++) cell_indices[cells[i]] = i;
        G4.resize(N);
        G8.resize(N, vector<int>(8));
        G4.reserve(9*N);
        G8.reserve(9*N);
        cell_indices.reserve(N);
        empty_cell_indices.reserve(8*N);
        
        init_done = init_solvability_done = false;
    }
    
    bool solvable() {
        init_solvability();
        return ((int)components8[comp8[0]].size() == N);
    }
 
    int remove() {
        init();
        if(removable.empty()) return -1;
        int rm_id = *rbegin(removable);
 
        removable.erase(--end(removable));
        removed[rm_id] = true;
 
        components4[rm_id] = {rm_id};
        comp4[rm_id] = rm_id;
        for(auto f : G4[rm_id]) if(!is_empty(f)) update(f);
        for(auto v : G4[rm_id]) {
            if(is_empty(v)) add_edge(rm_id, v);
            else deg4[v]--;
        }
        for(auto v : G8[rm_id]) {
            deg8[v]--;
            if(!is_empty(v)) update(v);
        }
 
        return rm_id;
    }
};
 
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, t;
    cin >> N >> t;
    vector< pair<int, int> > cells(N);
    for(int i = 0; i < N; i++) cin >> cells[i].first >> cells[i].second;
 
    lego solver(cells);
 
    if(!solver.solvable()) {
        cout << "NO\n";
        return 0;
    }
 
    cout << "YES\n";
    vector<int> build;
    for(int i = 0; i < N; i++) {
        int removed_cell_id = solver.remove();
        assert(removed_cell_id != -1);
        build.push_back(removed_cell_id+1);
    }
    reverse(begin(build), end(build));
    for(int i = 0; i < N; i++) cout << build[i] << "\n";
}