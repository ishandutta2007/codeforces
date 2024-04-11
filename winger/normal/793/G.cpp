// vvvvvvvvvvvvvvvvv Library code start


#define NDEBUG
NDEBUG


#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
#include <queue>
#include <random>


#define forn(t, i, n) for (t i = 0; i < (n); ++i)


#define all(c) c.begin(), c.end()


using namespace std;

/// caide keep
bool __hack = std::ios::sync_with_stdio(false);
/// caide keep
auto __hack1 = cin.tie(nullptr);

template<class T>
inline T mn(T arg) {
    return arg;
}

template<class T, class... Ts>
inline typename common_type<T, Ts...>::type mn(T arg, Ts... args) {
    auto arg1 = mn(args...);
    return arg < arg1 ? arg : arg1;
}


template <class T>
T pop(queue<T>& v) {
    T ret = v.front();
    v.pop();
    return ret;
}


// Section with adoption of array and vector algorithms.


// 32 bit ints (sum LSB + MSB == 32)


// TODO: Section with some container algorithms


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}


#define dbg(...) ;


//TODO migrate iterators into iterator_utils
namespace graph_impl {

    template<class T, class G, T next(const G&, T)>
    struct GenListIterator {
        GenListIterator(const G& g_, T t_): g(g_), t(t_) {}

        T operator*() const {
            return t;
        }

        GenListIterator& operator++() {
            t = next(g, t);
            return *this;
        }

        
        bool operator!=(const GenListIterator& o) const {
            assert(&g == &o.g);
            return t != o.t;
        }
    private:
        const G& g;
        T t;
    };

    template<class T, class G, T next(const G&, T)>
    struct GenListIterable {
        GenListIterable(const G& g_, T from_, T to_): g(g_), from(from_), to(to_) {}

        GenListIterator<T, G, next> begin() {
            return {g, from};
        };

        GenListIterator<T, G, next> end() {
            return {g, to};
        };
    private:
        const G& g;
        T from, to;
    };

    template<class T>
    struct GenRangeIterator {
        explicit GenRangeIterator(int at_): at(at_) {}

        T operator*() const {
            return T{at};
        }

        GenRangeIterator& operator++() {
            at++;
            return *this;
        }

        
        bool operator!=(const GenRangeIterator& o) const {
            return at != o.at;
        }
    private:
        int at;
    };

    template<class T>
    struct GenRangeIterable {
        GenRangeIterable(int from_, int to_):  from(from_), to(to_) {}

        GenRangeIterator<T> begin() {
            return GenRangeIterator<T>{from};
        };

        GenRangeIterator<T> end() {
            return GenRangeIterator<T>{to};
        };
    private:
        int from, to;
    };

    template<class K, class V>
    struct GenMap {
        using Value = V;

        explicit GenMap(V v_ = V{}): v(v_) {
        }

        GenMap& reserve(int n) {
            impl_.reserve(n);
            return *this;
        }

        GenMap& clear() {
            impl_.clear();
            return *this;
        }

        V& operator()(K k) {
            if (impl_.size() <= k.id) {
                impl_.resize(k.id + 1, v);
            }
            return impl_[k.id];
        }

        const V& operator()(K k) const {
            if (impl_.size() <= k.id) {
                return v;
            }
            return impl_[k.id];
        }
        vector<V> impl_;
    private:
        V v;
    };


    struct NodeT {
        int firstOut = -1;
        int degree = 0;
    };

    struct ArcT {
        int to, nextOut;
    };
}

struct Graph {
    struct Node {
        int id;
        explicit Node(int id_ = -1): id(id_) {}
        bool operator==(const Node o) const {return id == o.id;}
        
        
    };

    struct Arc {
        int id;
        explicit Arc(int id_ = -1): id(id_) {}
        
        bool operator!=(const Arc o) const {return id != o.id;}

        
    };

    struct Edge {
        int id;
        explicit Edge(int id_ = -1): id(id_) {}
        
        
        template<class C>
        Edge& withUV(C& c, typename C::Value v) {
            c(Arc{2 * id}) = v;
            return *this;
        };

        
    };

    template<class V>
    using NodeMap = graph_impl::GenMap<Node, V>;

    template<class V>
    using ArcMap = graph_impl::GenMap<Arc, V>;

    
    Node addNode() {
        int n = (int)nodes_.size();
        nodes_.push_back({});
        return Node{n};
    }

    vector<Node> addNodes(int count) {
        vector<Node> ret(count);
        forn (int, i, count) {
            ret[i] = addNode();
        }
        return ret;
    }

    Edge addEdge(Node u, Node v) {
        assert(valid(u));
        assert(valid(v));
        int n = (int)arcs_.size();
        arcs_.push_back({});
        arcs_[n].to = v.id;
        arcs_[n].nextOut = nodes_[u.id].firstOut;
        nodes_[u.id].firstOut = n;
        arcs_.push_back({});
        arcs_[n + 1].to = u.id;
        arcs_[n + 1].nextOut = nodes_[v.id].firstOut;
        nodes_[v.id].firstOut = n + 1;
        nodes_[u.id].degree++;
        nodes_[v.id].degree++;
        return Edge{n >> 1};
    }

    
    int nodesCount() const {
        return (int)nodes_.size();
    }

    int arcsCount() const {
        return (int)arcs_.size();
    }

    
    Arc dual(Arc a) const {
        if (a.id == -1) {
            return a;
        }
        assert(valid(a));
        return Arc{a.id ^ 1};
    }

    Arc firstInArc(Node a) const {
        assert(valid(a));
        return dual(Arc{nodes_[a.id].firstOut});
    }

    Arc firstOutArc(Node a) const {
        assert(valid(a));
        return Arc{nodes_[a.id].firstOut};
    }

    Arc nextInArc(Arc a) const {
        assert(valid(a));
        return dual(Arc{arcs_[dual(a).id].nextOut});
    }

    Arc nextOutArc(Arc a) const {
        assert(valid(a));
        return Arc{arcs_[a.id].nextOut};
    }

    Node from(Arc a) const {
        assert(valid(a));
        return Node{arcs_[dual(a).id].to};
    }

    Node to(Arc a) const {
        assert(valid(a));
        return Node{arcs_[a.id].to};
    }

    
    template <class T>
    NodeMap<T> nodeMap(T v0 = T{}) const {
        NodeMap<T> ret(v0);
        ret.reserve(nodesCount());
        return ret;
    }

    template <class T>
    ArcMap<T> arcMap(T v0 = T{}) const {
        ArcMap<T> ret(v0);
        ret.reserve(arcsCount());
        return ret;
    }

    
private:

    static Arc nextInArc_(const Graph& g, Arc a) {
        return g.nextInArc(a);
    }

    
public:

    graph_impl::GenListIterable<Arc, Graph, &Graph::nextInArc_> inArcs(Node a) const {
        assert(valid(a));
        return graph_impl::GenListIterable<Arc, Graph, &Graph::nextInArc_>(*this, firstInArc(a), Arc{});
    }

    
    graph_impl::GenRangeIterable<Arc> arcs() const {
        return graph_impl::GenRangeIterable<Arc>(0, arcsCount());
    }

    
private:
    vector<graph_impl::NodeT> nodes_;
    vector<graph_impl::ArcT> arcs_;
};


// Highest-label variation of Karzanov's algorithm
template <class Cap = int32_t, class Excess = int64_t>
struct DinicFlow {
    using Node = Graph::Node;
    using Arc = Graph::Arc;
    

    DinicFlow(const Graph& g_, const Graph::ArcMap<Cap>& cap_): g(g_), cap(cap_) {}

    Excess run(Node s, Node t) {
        residual = cap;
        label = g.nodeMap<int>(g.nodesCount());
        currentArc = g.nodeMap<Arc>();
        value = 0;
        while (buildNet(s, t)) {
            Cap inf = numeric_limits<Cap>::max();
            Cap cur;
            while ((cur = flowDfs(s, t, inf)) > 0) {
                value += cur;
            }
        }
        flow = g.arcMap<Cap>();
        for (auto a : g.arcs()) {
            flow(a) = cap(a) - residual(a);
        }
        return value;
    }

    bool buildNet(Node s, Node t) {
        label.clear();
        label(t) = 0;
        queue<Node> q;
        q.push(t);
        while (!q.empty()) {
            auto u = pop(q);
            currentArc(u) = g.firstOutArc(u);
            if (u == s) {
                break;
            }
            for (auto a : g.inArcs(u)) {
                auto v = g.from(a);
                if (residual(a) > 0 && label(v) == g.nodesCount()) {
                    label(v) = label(u) + 1;
                    q.push(v);
                }
            }
        }
        if (label(s) == g.nodesCount()) {
            return false;
        }
        return true;
    }

    Cap flowDfs(Node u, Node t, Cap max) {
        if (u == t) {
            return max;
        }
        Cap ret = 0;
        auto& a = currentArc(u);
        for (; a != Arc{}; a = g.nextOutArc(a)) {
            auto v = g.to(a);
            Cap cur;
            if (label(u) == label(v) + 1 && residual(a) > 0 && (cur = flowDfs(v, t, mn(residual(a), max))) > 0) {
                ret += cur;
                max -= cur;
                residual(a) -= cur;
                residual(g.dual(a)) += cur;
                if (max == 0) {
                    break;
                }
            }
        }
        return ret;
    }

    // outputs
    Excess value;
    Graph::ArcMap<Cap> flow, residual;

private:
    // inputs
    const Graph& g;
    const Graph::ArcMap<Cap>& cap;

    // temp
    Graph::NodeMap<int> label;
    Graph::NodeMap<Arc> currentArc;
};

// ^^^^^^^^^^^^^^^^^ Library code end

void solve(istream& in, ostream& out) {
    int n = next<int>(in);
    Graph g;
    Graph::Node s = g.addNode(), t = g.addNode();
    auto cap = g.arcMap<int>();
    vector<vector<Graph::Node>> levelsIn, levelsOut;
    levelsIn.push_back(g.addNodes(n));
    levelsOut.push_back(g.addNodes(n));
    forn (int, i, n) {
        g.addEdge(s, levelsIn[0][i]).withUV(cap, 1);
        g.addEdge(levelsOut[0][i], t).withUV(cap, 1);
    }
    for (int l = 1; (1 << l) <= n; ++l) {
        levelsIn.push_back(g.addNodes(n - (1 << l) + 1));
        levelsOut.push_back(g.addNodes(n - (1 << l) + 1));
        forn (int, i, n - (1 << l) + 1) {
            g.addEdge(levelsIn[l - 1][i], levelsIn[l][i]).withUV(cap, n);
            g.addEdge(levelsIn[l - 1][i + (1 << (l - 1))], levelsIn[l][i]).withUV(cap, n);
            g.addEdge(levelsOut[l][i], levelsOut[l - 1][i]).withUV(cap, n);
            g.addEdge(levelsOut[l][i], levelsOut[l - 1][i + (1 << (l - 1))]).withUV(cap, n);
        }
    }
    int qs = next<int>(in);
    using evt = tuple<int, int, pair<int, int>>;
    vector<evt> evs;
    forn (int, q, qs) {
        int x1 = next<int>(in) - 1;
        int y1 = next<int>(in) - 1;
        int x2 = next<int>(in) - 1;
        int y2 = next<int>(in) - 1;
        evs.push_back(evt{x1, +1, {y1, y2 + 1}});
        evs.push_back(evt{x2 + 1, -1, {y1, y2 + 1}});
    }
    evs.push_back(evt{0, -1, {0, n}});
    evs.push_back(evt{n, +1, {0, n}});
    sort(all(evs));
    auto insertRect = [&](int x0, int x1, int y0, int y1) {
        if (x0 == x1 || y0 == y1) {
            return;
        }
        int dx = 0, dy = 0;
        while (x0 + (1 << (dx + 1)) <= x1) {
            ++dx;
        }
        while (y0 + (1 << (dy + 1)) <= y1) {
            ++dy;
        }
        auto u = g.addNode();
        g.addEdge(levelsIn[dx][x0], u).withUV(cap, n);
        g.addEdge(levelsIn[dx][x1 - (1 << dx)], u).withUV(cap, n);
        g.addEdge(u, levelsOut[dy][y0]).withUV(cap, n);
        g.addEdge(u, levelsOut[dy][y1 - (1 << dy)]).withUV(cap, n);
        dbg(x0 + 1, y0 + 1, x1, y1, u.id);
    };
    map<int, pair<int, int>> ranges;
    for (auto& e : evs) {
        int x = get<0>(e);
        auto& range = get<2>(e);
        if (get<1>(e) == -1) {
            ranges[range.first] = {range.second, x};
        } else {
            auto it = ranges.upper_bound(range.first);
            --it;
            pair<int, int> outer;
            outer.first = it->first;
            while (it != ranges.end() && it->first < range.second) {
                insertRect(it->second.second, x, it->first, it->second.first);
                outer.second = it->second.first;
                auto jt = it;
                it++;
                ranges.erase(jt);
            }
            if (outer.first < range.first) {
                ranges[outer.first] = {range.first, x};
            }
            if (range.second < outer.second) {
                ranges[range.second] = {outer.second, x};
            }
        }
    }
    DinicFlow<int> f(g, cap);
    out << f.run(s, t) << "\n";
}


int main() {
    solve(cin, cout);
    return 0;
}