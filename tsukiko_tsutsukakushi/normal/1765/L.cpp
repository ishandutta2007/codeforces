#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++ i)

#define all(c) std::begin(c), std::end(c)

#ifdef LOCAL
#define debug(...) debug_impl(#__VA_ARGS__, __VA_ARGS__)

template<class T, class ...Args> void debug_impl(string s, T&& first, Args &&...args) {
    cerr << "(" << s << ") : (" << forward<T>(first);
    ((cerr << ", " << forward<Args>(args)), ..., (cerr << ") " << "\n"));
}

#else
#define debug(...) void(0)
#endif

template<class T> bool chmax(T& a, const T& b) {
    return b > a ? (a == b, true) : false;
}

template<class T> bool chmin(T& a, const T& b) {
    return b < a ? (a == b, true) : false;
}

template<class T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& e : v) in >> e;
    return in;
}

template<class ...Args> void read(Args &...args) {
    (cin >> ... >> args);
}

template<class T> ostream& operator<<(ostream& out, const vector<T>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        out << v[i];
        if (i + 1 != n) out << ' ';
    }
    return out;
}

template<class Head, class ...Tails> void print(Head&& h, Tails && ...tail) {
    cout << h, ((cout << ' ' << forward<Tails>(tail)), ..., (cout << '\n'));
}

template <typename T, T(*op)(T, T), T(*e)()>
struct  segtree {
    int siz;
    vector<T> dat;
    segtree(int n = 0) : segtree(vector<T>(n, e())) {}
    segtree(const vector<T> &a) {
        const int n = a.size();
        siz = 1;
        while (siz < n) siz <<= 1;
        dat.resize(2 * siz, e());
        rep(i, n) {
            dat[siz + i] = a[i];
        }
        for (int i = n - 1; i > 0; --i) {
            update(i);
        }
    }

    T prod(int l, int r) {
        T sml = e(), smr = e();
        l += siz, r += siz;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) sml = op(sml, dat[l++]);
            if (r & 1) smr = op(dat[--r], smr);
        }
        return op(sml, smr);
    }

    void set(int i, const T &val) {
        i += siz;
        dat[i] = val;
        while (i >>= 1) update(i);
    }

    T get(int i) {
        return dat[siz + i];
    }

    T prod_all() {
        return dat[1];
    }

private:
    void update(int i) {
        dat[i] = op(dat[2 * i], dat[2 * i + 1]);
    }
};

int op(int x, int y) {
    return min(x, y);
}
int e() {
    return 100000000;
}

constexpr int L = 7;

const map<string, int> days {
    { "Monday", 0 },
    { "Tuesday", 1 },
    { "Wednesday", 2 },
    { "Thursday", 3 },
    { "Friday", 4 },
    { "Saturday", 5 },
    { "Sunday", 6 }
};

int main() {
    int n, m, k;
    read(n, m, k);

    vector segs(L, segtree<int, op, e>(n));

    vector work(n, array<bool, L>{});

    rep(i, n) {
        int k;
        read(k);
        rep(j, k) {
            string s;
            read(s);
            work[i][days.at(s)] = true;
        }
    }

    vector<priority_queue<int, vector<int>, greater<int>>> pqs(n);

    vector<int> h(m);
    read(h);
    for (auto &e : h) --e;

    vector<deque<int>> proj(k);
    rep(i, k) {
        int l;
        read(l);
        rep(j, l) {
            int idx;
            read(idx);
            --idx;
            proj[i].push_back(idx);
        }
        int worker = proj[i].front();
        pqs[worker].push(i);

        rep(j, L) if (work[worker][j]) {
            segs[j].set(worker, worker);
        }
    }

    vector<int> ans(k);

    for (int d = 0, done_cnt = 0, hi = 0; done_cnt < k; ++d) {
        if (hi < m and d == h[hi]) {
            ++hi;
            continue;
        }

        // debug(d + 1);

        vector<int> suc_project;
        vector<int> worked;

        const int p = d % L;
        while (true) {
            int worker = segs[p].prod_all();
            if (worker != e()) {
                if (pqs[worker].empty()) {
                    segs[p].set(worker, e());
                    continue;
                }

                assert(pqs[worker].size());
                worked.push_back(worker);
                int project = pqs[worker].top();
                suc_project.push_back(project);
                assert(proj[project].size());
                proj[project].pop_front();
                assert(pqs[worker].size());
                pqs[worker].pop();
                segs[p].set(worker, e());

                // debug(worker + 1, project + 1);
            } else {
                break;
            }
        }


        for (int project : suc_project) {
            if (proj[project].size()) {
                int worker = proj[project].front();
                // debug(worker + 1, project + 1);
                if (pqs[worker].empty()) {
                    rep(j, L) if (work[worker][j]) {
                        segs[j].set(worker, worker);
                    }
                }
                pqs[worker].push(project);
            } else {
                ans[project] = d + 1;
                ++done_cnt;
                // debug(done_cnt, project);
            }
        }

        for (int worker : worked) {
            if (pqs[worker].size()) {
                segs[p].set(worker, worker);
            }
        }
    }

    print(ans);
}