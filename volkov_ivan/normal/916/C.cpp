#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (i == n) break;
        if (n % i == 0) return 0;
    }
    return 1;
}

struct edge{
    int v, u, w;
    edge() {};
    edge(int v, int u, int w) {
        this->v = v;
        this->u = u;
        this->w = w;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    if (n == 2) {
        cout << "2 2" << endl;
        cout << "1 2 2" << endl;
        return 0;
    }
    vector <edge> g;
    g.push_back(edge(1, n, 2));
    m--;
    for (int i = 2; i < n - 1; i++) {
        g.push_back(edge(i, i + 1, 2));
        m--;
    }
    int s = 2 * (n - 2);
    for (int i = 1; i < 100000; i++) {
        if (is_prime(s + i)) {
            //cout << "! " << i << ' ' << s + i << endl;
            g.push_back(edge(n - 1, n, i));
            s += i;
            m--;
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        if (m == 0) break;
        for (int j = i + 1; j <= n; j++) {
            if (m == 0) break;
            if (i == 1 && j == n) continue;
            if (j == i + 1 && i != 1) continue;
            g.push_back(edge(i, j, INF));
            m--;
        }
    }
    cout << "2 " << s << endl;
    for (edge elem : g) {
        cout << elem.v << ' ' << elem.u << ' ' << elem.w << endl;
    }
    return 0;
}