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

template<class T>
inline T mx(T arg) {
    return arg;
}

template<class T, class... Ts>
inline typename common_type<T, Ts...>::type mx(T arg, Ts... args) {
    auto arg1 = mx(args...);
    return arg > arg1 ? arg : arg1;
}

template<class T, class... Args>
inline bool rmn(T &to, Args... args) {
    auto v = mn(args...);
    if (to > v) {
        to = v;
        return true;
    }
    return false;
}


template <class T>
T pop_back(vector<T>& v) {
    T ret = v.back();
    v.pop_back();
    return ret;
}

template <class T>
T pop(queue<T>& v) {
    T ret = v.front();
    v.pop();
    return ret;
}

template <class T>
T pop(priority_queue<T>& v) {
    T ret = v.top();
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
        bool operator!=(const Node o) const {return id != o.id;}
        bool operator<(const Node o) const {return id < o.id;}

        
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

        template<class C>
        Edge& withVU(C& c, typename C::Value v) {
            c(Arc{2 * id + 1}) = v;
            return *this;
        };

        
    };

    template<class V>
    using NodeMap = graph_impl::GenMap<Node, V>;

    template<class V>
    using ArcMap = graph_impl::GenMap<Arc, V>;

    template<class V>
    using EdgeMap = graph_impl::GenMap<Edge, V>;

    Graph& reserve(int nodes, int edges) {
        nodes_.reserve(nodes);
        arcs_.reserve(2 * edges);
        return *this;
    }

    Graph& clear() {
        arcs_.clear();
        nodes_.clear();
        return *this;
    }

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

    
    Arc uv(Edge e) const {
        assert(valid(e));
        return Arc{e.id << 1};
    }

    Arc vu(Edge e) const {
        assert(valid(e));
        return dual(Arc{e.id << 1});
    }

    Node u(Edge e) const {
        assert(valid(e));
        return from(uv(e));
    }

    Node v(Edge e) const {
        assert(valid(e));
        return to(uv(e));
    }

    int nodesCount() const {
        return (int)nodes_.size();
    }

    int arcsCount() const {
        return (int)arcs_.size();
    }

    int edgesCount() const {
        return (int)arcs_.size() / 2;
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

    
    graph_impl::GenRangeIterable<Node> nodes() const {
        return graph_impl::GenRangeIterable<Node>(0, nodesCount());
    }

    graph_impl::GenRangeIterable<Arc> arcs() const {
        return graph_impl::GenRangeIterable<Arc>(0, arcsCount());
    }

    graph_impl::GenRangeIterable<Edge> edges() const {
        return graph_impl::GenRangeIterable<Edge>(0, edgesCount());
    }

    
private:
    vector<graph_impl::NodeT> nodes_;
    vector<graph_impl::ArcT> arcs_;
};


template<class Cap, class Cost = Cap>
struct StripMinCapacities {
    using Node = Graph::Node;
    
    using Edge = Graph::Edge;
    using CapMap = Graph::ArcMap<Cap>;
    using CostMap = Graph::EdgeMap<Cost>;

    StripMinCapacities(const Graph& g_, const CapMap& capMin_, const CapMap& capMax_): g(g_), capMin(capMin_), capMax(capMax_) {}

    
    StripMinCapacities& run(Node s, Node t) {
        g1.clear().reserve(g.nodesCount() + 2, g.edgesCount() + g.nodesCount() + 1);
        capOut.clear().reserve(g1.edgesCount());
        if (cost) {
            costOut.clear();
            costOut.reserve(g1.edgesCount());
        }
        g1.addNodes(g.nodesCount());
        s1 = g1.addNode();
        t1 = g1.addNode();
        Graph::NodeMap<Cap> residual;
        for (Edge e : g.edges()) {
            Edge e1 = g1.addEdge(g.u(e), g.v(e))
                .withUV(capOut, capMax(g.uv(e)) - capMin(g.uv(e)))
                .withVU(capOut, capMax(g.vu(e)) - capMin(g.vu(e)));
            int delta = capMin(g.uv(e)) - capMin(g.vu(e));
            residual(g.u(e)) += delta;
            residual(g.v(e)) -= delta;
            if (cost) {
                costOut(e1) = (*cost)(e);
            }
        }
        targetFlow = 0;
        for (Node n : g.nodes()) {
            Graph::Edge e;
            Cap res = residual(n);
            if (res < 0) {
                e = g1.addEdge(s1, n).withUV(capOut, -res);
                targetFlow -= res;
            } else {
                e = g1.addEdge(n, t1).withUV(capOut, res);
            }
            if (cost) {
                costOut(e) = 0;
            }
        }
        ts = g1.addEdge(t, s).withUV(capOut, inf);
        if (cost) {
            costOut(ts) = 0;
        }
        return *this;
    }

    // outputs
    Graph g1;
    CapMap capOut;
    CostMap costOut;
    Node s1, t1;
    Edge ts;
    Cap targetFlow;

private:
    // inputs
    const Graph& g;
    const CapMap& capMin, capMax;
    const CostMap* cost = nullptr;
    Cap inf = numeric_limits<Cap>::max();

};


// TODO: gap heuristic & relabel sorting heuristic
// https://www.ads.tuwien.ac.at/teaching/archiv/praktika/CherkasskyGoldberg-1995-MaxFlow.pdf


// Highest-label variation of Karzanov's algorithm
template <class Cap = int32_t, class Excess = int64_t>
struct BlockingPreflow {
    using Node = Graph::Node;
    using Arc = Graph::Arc;
    

    BlockingPreflow(const Graph& g_, const Graph::ArcMap<Cap>& cap_): g(g_), cap(cap_) {}

    Excess run(Node s, Node t) {
        residual = cap;
        label = g.nodeMap<int>(g.nodesCount());
        inFlows = g.nodeMap<vector<pair<Cap, Arc>>>();
        excess = g.nodeMap<Excess>();
        excess(s) = numeric_limits<Excess>::max();
        currentArc = g.nodeMap<Arc>();
        while (buildNet(s, t)) {
            int maxDist = label(s);
            int curActive = maxDist;
            priority_queue<pair<int, Node>> inactives;
            while (countActives > 0 || !inactives.empty()) {
                if (countActives == 0) {
                    int l0 = -inactives.top().first;
                    while (!inactives.empty() && -inactives.top().first <= l0 + 1) {
                        auto u = pop(inactives).second;
                        inactive(u) = 1;
                        curActive = label(u) + 1;
                        auto& in = inFlows(u);
                        while (excess(u) > 0) {
                            assert(!in.empty());
                            auto p = pop_back(in);
                            auto a = p.second;
                            auto v = g.to(a);
                            Cap delta = mn(p.first, excess(u));
                            if (excess(v) == 0 && v != s) {
                                activeNodesByLabel[label(v)].push_back(v);
                                countActives++;
                            }
                            excess(u) -= delta;
                            excess(v) += delta;
                            residual(a) -= delta;
                            residual(g.dual(a)) += delta;
                            p.first -= delta;
                            if (p.first > 0) {
                                in.push_back(p);
                            }
                        }
                    }
                }
                if (activeNodesByLabel[curActive].empty()) {
                    curActive--;
                    continue;
                }
                Node u = pop_back(activeNodesByLabel[curActive]);
                if (discharge(u) && u != s) {
                    inactives.emplace(-label(u), u);
                }
            }
        }
        flow = g.arcMap<Cap>();
        for (auto a : g.arcs()) {
            flow(a) = cap(a) - residual(a);
        }
        return value = excess(t);
    }

    bool buildNet(Node s, Node t) {
        label.clear();
        label(t) = 0;
        queue<Node> q;
        q.push(t);
        while (!q.empty()) {
            auto u = pop(q);
            currentArc(u) = g.firstOutArc(u);
            inactive(u) = 0;
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
        inFlows.clear();
        activeNodesByLabel.clear();
        activeNodesByLabel.resize(label(s) + 1);
        activeNodesByLabel[label(s)].push_back(s);
        countActives = 1;
        return true;
    }

    bool push(Arc a, Node u, Node v) {
        if (residual(a) == 0) {
            return false;
        }
        Cap delta = (Cap)mn(excess(u), residual(a));
        if (excess(v) == 0 && label(v) > 0) {
            activeNodesByLabel[label(v)].push_back(v);
            countActives++;
        }
        excess(u) -= delta;
        excess(v) += delta;
        residual(a) -= delta;
        residual(g.dual(a)) += delta;
        inFlows(v).emplace_back(delta, g.dual(a));
        return excess(u) == 0;
    }

    bool discharge(Node u) {
        assert(excess(u) > 0);
        countActives--;
        while (currentArc(u) != Arc{}) {
            auto a = currentArc(u);
            auto v = g.to(a);
            if (label(u) == label(v) + 1 && !inactive(v) && push(a, u, v)) {
                return false;
            }
            currentArc(u) = g.nextOutArc(a);
        }
        return true;
    }

    // outputs
    Excess value;
    Graph::ArcMap<Cap> flow, residual;

private:
    // inputs
    const Graph& g;
    const Graph::ArcMap<Cap>& cap;

    // temp
    Graph::NodeMap<Excess> excess;
    Graph::NodeMap<int> label, inactive;
    Graph::NodeMap<vector<pair<Cap, Arc>>> inFlows;
    Graph::NodeMap<Arc> currentArc;

    vector<vector<Node>> activeNodesByLabel;
    int countActives;
};

// ^^^^^^^^^^^^^^^^^ Library code end

int insert(unordered_map<int, int>& xs, int x) {
    if (!xs.count(x)) {
        int next = xs.size();
        xs[x] = next;
    }
    return xs[x];
}

void solve(istream& in, ostream& out) {
    int n = next<int>(in);
    int m = next<int>(in);
    int64_t rc = next<int64_t>(in), bc = next<int64_t>(in);
    unordered_map<int, int> xs, ys;
    vector<pair<int, int>> es;
    forn (int, it, n) {
        int x = next<int>(in);
        int y = next<int>(in);
        es.emplace_back(insert(xs, x), insert(ys, y));
    }
    vector<int> xd(xs.size(), n), xdegree(xs.size()), yd(ys.size(), n), ydegree(ys.size());
    forn (int, it, m) {
        int t = next<int>(in);
        int at = next<int>(in);
        int d = next<int>(in);
        if (t == 1) {
            if (xs.count(at)) {
                rmn(xd[xs[at]], d);
            }
        } else {
            if (ys.count(at)) {
                rmn(yd[ys[at]], d);
            }
        }
    }
    Graph g;
    Graph::Node s = g.addNode(), t = g.addNode();
    auto xNodes = g.addNodes(xs.size());
    auto yNodes = g.addNodes(ys.size());
    auto capMin = g.arcMap<int>(), capMax = g.arcMap<int>();
    vector<Graph::Edge> ese;
    for (auto& e : es) {
        xdegree[e.first]++;
        ydegree[e.second]++;
        ese.push_back(g.addEdge(xNodes[e.first], yNodes[e.second]).withUV(capMax, 1));
    }
    forn (int, i, xNodes.size()) {
        auto u = xNodes[i];
        int degree = xdegree[i];
        int d = mn(xd[i], degree);
        int l = (degree - d + 1) / 2, r = (degree + d) / 2;
        if (l > r) {
            out << "-1\n";
            return;
        }
        g.addEdge(s, u).withUV(capMin, l).withUV(capMax, r);
    }
    forn (int, i, yNodes.size()) {
        auto u = yNodes[i];
        int degree = ydegree[i];
        int d = mn(yd[i], degree);
        int l = (degree - d + 1) / 2, r = (degree + d) / 2;
        if (l > r) {
            out << "-1\n";
            return;
        }
        g.addEdge(u, t).withUV(capMin,l).withUV(capMax, r);
    }
    StripMinCapacities<int> st(g, capMin, capMax);
    st.run(s, t);
    BlockingPreflow<int> f(st.g1, st.capOut);
    if (f.run(st.s1, st.t1) < st.targetFlow) {
        out << "-1\n";
        return;
    }
    auto cap1 = st.g1.arcMap<int>();
    for (auto a : st.g1.arcs()) {
        cap1(a) = st.capOut(a) - f.flow(a);
    }
    BlockingPreflow<int> f1(st.g1, cap1);
    int totalFlow = f1.run(s, t);
    out << (totalFlow * mn(rc, bc) + (n - totalFlow) * mx(rc, bc)) << "\n";
    for (auto e : ese) {
        out << (((rc < bc) ^ (f.flow(st.g1.uv(e)) + f1.flow(st.g1.uv(e)) == 0)) ? "r" : "b");
    }
    out <<"\n";
}


int main() {
    solve(cin, cout);
    return 0;
}