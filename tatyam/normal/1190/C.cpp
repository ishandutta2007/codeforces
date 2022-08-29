#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ull=unsigned long long;
using uint=unsigned int;
using pcc=pair<char,char>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pdd=pair<double,double>;
using tuplis=pair<ll,pll>;
using tuplis2=pair<pll,ll>;
template<class T> using pq=priority_queue<T,vector<T>,greater<T>>;
const ll LINF=0x1fffffffffffffff;
const int INF=0x3fffffff;
const ll MOD=1000000007;
const ll MODD=998244353;
const ld DINF=numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const vector<ll>four{0,1,0,-1,0};
#define _overload4(_1,_2,_3,_4,name,...) name
#define _overload3(_1,_2,_3,name,...) name
#define _rep1(n) for(ll i=0;i<n;++i)
#define _rep2(i,n) for(ll i=0;i<n;++i)
#define _rep3(i,a,b) for(ll i=a;i<b;++i)
#define _rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) _overload4(__VA_ARGS__,_rep4,_rep3,_rep2,_rep1)(__VA_ARGS__)
#define _rrep1(n) for(ll i=n-1;i>=0;i--)
#define _rrep2(i,n) for(ll i=n-1;i>=0;i--)
#define _rrep3(i,a,b) for(ll i=b-1;i>=a;i--)
#define _rrep4(i,a,b,c) for(ll i=a+(b-a-1)/c*c;i>=a;i-=c)
#define rrep(...) _overload4(__VA_ARGS__,_rrep4,_rrep3,_rrep2,_rrep1)(__VA_ARGS__)
#define each(i,a) for(auto &i:a)
#define sum(...) accumulate(range(__VA_ARGS__),0LL)
#define dsum(...) accumulate(range(__VA_ARGS__),double(0))
#define _range(i) (i).begin(),(i).end()
#define _range2(i,k) (i).begin(),(i).begin()+k
#define _range3(i,a,b) (i).begin()+a,(i).begin()+b
#define range(...) _overload3(__VA_ARGS__,_range3,_range2,_range)(__VA_ARGS__)
#define _rrange(i) (i).rbegin(),(i).rend()
#define _rrange2(i,k) (i).rbegin(),(i).rbegin()+k
#define _rrange3(i,a,b) (i).rbegin()+a,(i).rbegin()+b
#define rrange(...) _overload3(__VA_ARGS__,_rrange3,_rrange2,_rrange)(__VA_ARGS__)
#define elif else if
#define unless(a) if(!(a))
#define mp make_pair
#define mt make_tuple
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}
template<class T> inline constexpr T min(vector<T> &v){return *min_element(range(v));}
inline char min(string &v){return *min_element(range(v));}
template<class T> inline constexpr T max(vector<T> &v){return *max_element(range(v));}
inline char max(string &v){return *max_element(range(v));}
inline constexpr ll intpow(ll a,ll b){ll ans=1;for(ll i=1;b;i*=2){if(b&i){b^=i;ans*=a;}a*=a;}return ans;}
inline constexpr ll modpow(ll a,ll b,ll mod = MOD){ll ans=1;for(ll i=1;b;i*=2){if(b&i){b^=i;ans*=a;ans%=mod;}a*=a;a%=mod;}return ans;}
template<typename T>
inline constexpr bool chmin(T &mn,const T &cnt){if(mn>cnt){mn=cnt;return 1;}else return 0;}
template<typename T>
inline constexpr bool chmax(T &mx,const T &cnt){if(mx<cnt){mx=cnt;return 1;}else return 0;}
template<class T> unordered_map<T,ll> press(vector<T> &a){ auto b = a; sort(range(b)); b.erase(unique(range(b)), b.end()); unordered_map<T,ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }
template<class T> map<T,ll> press_map(vector<T> &a){ auto b = a; sort(range(b)); b.erase(unique(range(b)), b.end()); map<T,ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }
inline int scan(){ return getchar(); }
inline void scan(int &a){ scanf("%d", &a); }
inline void scan(unsigned &a){ scanf("%u", &a); }
inline void scan(long &a){ scanf("%ld", &a); }
inline void scan(long long &a){ scanf("%lld", &a); }
inline void scan(unsigned long long &a){ scanf("%llu", &a); }
inline void scan(char &a){ cin >> a; }
inline void scan(float &a){ scanf("%f", &a); }
inline void scan(double &a){ scanf("%lf", &a); }
inline void scan(long double &a){ scanf("%Lf", &a); }
inline void scan(vector<bool> &vec){ for(unsigned i = 0; i < vec.size(); i++) { int a; scan(a); vec[i] = a; } }
inline void scan(string &a){ cin >> a; }
template<class T> inline void scan(vector<T> &vec);
template<class T, size_t size> inline void scan(array<T, size> &vec);
template<class T, class L> inline void scan(pair<T, L> &p);
template<class T, size_t size> inline void scan(T (&vec)[size]);
template<class T> inline void scan(vector<T> &vec){ for(auto &i : vec) scan(i); }
template<class T, size_t size> inline void scan(array<T, size> &vec){ for(auto &i : vec) scan(i); }
template<class T, class L> inline void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
template<class T, size_t size> inline void scan(T (&vec)[size]){ for(auto &i : vec) scan(i); }
template<class T> inline void scan(T &a){ cin>>a; }
inline void in(){}
template <class Head, class... Tail> inline void in(Head &head, Tail&... tail){ scan(head); in(tail...); }
inline void print(){ putchar('\n'); }
inline void print(const bool &a){ printf("%d", a); }
inline void print(const int &a){ printf("%d", a); }
inline void print(const unsigned &a){ printf("%u", a); }
inline void print(const long &a){ printf("%ld", a); }
inline void print(const long long &a){ printf("%lld", a); }
inline void print(const unsigned long long &a){ printf("%llu", a); }
inline void print(const char &a){ printf("%c", a); }
inline void print(const char a[]){ printf("%s", a); }
inline void print(const float &a){ printf("%.10f", a); }
inline void print(const double &a){ printf("%.10f", a); }
inline void print(const long double &a){ printf("%.10Lf", a); }
template<class T> void print(const vector<T> &vec);
template<class T, size_t size> void print(const array<T, size> &vec);
template<class T, class L> void print(const pair<T, L> &p);
template<class T, size_t size> inline void print(const T (&vec)[size]);
template<class T> void print(const vector<T> &vec){ print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T, size_t size> void print(const array<T, size> &vec){ print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T, class L> void print(const pair<T, L> &p){ print(p.first); putchar(' '); print(p.second); }
template<class T, size_t size> inline void print(const T (&vec)[size]){ print(vec[0]); for(auto i = vec; ++i != end(vec); ){ putchar(' '); print(*i); } }
template<class T> inline void print(const T &a){ cout << a; }
inline int out(){ putchar('\n'); return 0; }
template<class T> inline int out(const T &t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> inline int out(const Head &head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
template <class T> inline void err(T t){cerr<<t<<'\n';}
inline void err(){cerr<<'\n';}
inline int first(const bool &i){return out(i?"first":"second");}
inline int yes(const bool &i){return out(i?"yes":"no");}
inline int Yes(const bool &i){return out(i?"Yes":"No");}
inline int YES(const bool &i){return out(i?"YES":"NO");}
inline int Yay(const bool &i){return out(i?"Yay!":":(");}
inline int Possible(const bool &i){return out(i?"Possible":"Impossible");}
inline int POSSIBLE(const bool &i){return out(i?"POSSIBLE":"IMPOSSIBLE");}
inline void Case(ll i){printf("Case #%lld: ",i);}


namespace tatyam {
    
    constexpr int LEFT_CHILD = -1, RIGHT_CHILD = 1, NIL_CHILD = 0;
    
    template <class Key, class Compare = std::less<Key>>
    struct set {
        using key_type = Key;
        using value_type = Key;
        using allocator_type = std::allocator<Key>;
        using traits = std::allocator_traits<allocator_type>;
        Compare key_compare = Compare();
        using reference = value_type&;
        using const_reference = const value_type&;
        struct iterator;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using size_type = size_t;
        using difference_type = ptrdiff_t;
        using pointer = typename std::allocator_traits<allocator_type>::pointer;
        using const_pointer = typename std::allocator_traits<allocator_type>::const_pointer;
        static allocator_type alloc;
        struct node;
        using node_ptr = node*;
        static node _NIL;
        static node_ptr NIL;
        node_ptr _root = NIL, _begin = NIL, _rbegin = NIL;
        set() {}
        explicit set(const Compare& comp): key_compare(comp)  {}
        template <class InputIterator>
        set(InputIterator first, InputIterator last, const Compare& comp = Compare()): key_compare(comp) {
            std::vector<pointer> p;
            while(first != last) {
                p.push_back(traits::allocate(alloc, 1));
                traits::construct(alloc, p.back(), *first);
                ++first;
            }
            _insert_all(p);
        }
        set(const set& x) { *this = set(x.begin(), x.end(), x.key_compare); }
        set(set&& x) {
            key_compare = std::move(x.key_compare);
            _root = x._root;
            _begin = x._begin;
            _rbegin = x._rbegin;
        }
        set(std::initializer_list<value_type> init, const Compare& comp = Compare()) { *this = set(init.begin(), init.end(), comp); }
        ~set() { clear(); }
        void _add_path(node_ptr from, int val) {
            from->size += val;
            while(from != _root) {
                from = from->parent;
                from->size += val;
            }
        }
        iterator begin() const noexcept { return iterator(this, _begin); }
        void clear() noexcept {
            std::function<void(node_ptr)> _erase = [&_erase](node_ptr at) {
                if(at->is_nil()) return;
                _erase(at->left); _erase(at->right);
                delete at;
            };
            _erase(_root);
            _root = _begin = _rbegin = NIL;
        }
        template <class K>
        bool contains(const K& x) const { return find(x) != end(); }
        template <class K>
        size_type count(const K& x) const { return find(x) != end(); }
        template <class... Args>
        std::pair<iterator, bool> emplace(Args&&... args) {
            pointer p = traits::allocate(alloc, 1);
            traits::construct(alloc, p, args...);
            return _insert(p);
        }
        bool empty() const noexcept { return !_root->size; }
        iterator end() const noexcept { return iterator(this, NIL); }
        inline bool _equal(key_type &a, key_type &b) const { return !key_compare(a, b) && !key_compare(b, a); }
        void _erase(iterator position) {
            node_ptr at = position.base;
            if(at == _begin) _begin = (++iterator(position)).base;
            if(at == _rbegin) _rbegin = (--iterator(position)).base;
            if(at->right->is_nil() && at->left->is_nil()) {
                if(at->parent->is_nil()) _root = NIL;
                else if(at->child == LEFT_CHILD) at->parent->left = NIL;
                else at->parent->right = NIL;
            }
            else if(at->right->is_nil()) {
                if(at->parent->is_nil()) _root = at->left;
                else if(at->child == LEFT_CHILD) at->parent->left = at->left;
                else at->parent->right = at->left;
                at->left->parent = at->parent;
                at->left->child = at->child;
                at->left->size = at->size;
            }
            else if(at->left->is_nil()) {
                if(at->parent->is_nil()) _root = at->right;
                else if(at->child == LEFT_CHILD) at->parent->left = at->right;
                else at->parent->right = at->right;
                at->right->parent = at->parent;
                at->right->child = at->child;
                at->right->size = at->size;
            }
            else if(at->left->size > at->right->size) {
                node_ptr replace = (--iterator(position)).base;
                replace->size = at->size;
                if(at->left != replace) {
                    replace->parent->right = replace->left;
                    if(!replace->left->is_nil()) {
                        replace->left->parent = replace->parent;
                        replace->left->child = RIGHT_CHILD;
                    }
                }
                replace->parent = at->parent;
                replace->child = at->child;
                if(at->left != replace) {
                    replace->left = at->left;
                    if(!replace->left->is_nil()) replace->left->parent = replace;
                }
                replace->right = at->right;
                if(!replace->right->is_nil()) replace->right->parent = replace;
                if(replace->parent->is_nil()) _root = replace;
                else if(replace->child == LEFT_CHILD) replace->parent->left = replace;
                else replace->parent->right = replace;
            }
            else {
                node_ptr replace = (++iterator(position)).base;
                replace->size = at->size;
                if(at->right != replace) {
                    replace->parent->left = replace->right;
                    if(!replace->right->is_nil()) {
                        replace->right->parent = replace->parent;
                        replace->right->child = LEFT_CHILD;
                    }
                }
                replace->parent = at->parent;
                replace->child = at->child;
                replace->left = at->left;
                if(!replace->left->is_nil()) replace->left->parent = replace;
                if(at->right != replace) {
                    replace->right = at->right;
                    if(!replace->right->is_nil()) replace->right->parent = replace;
                }
                if(replace->parent->is_nil()) _root = replace;
                else if(replace->child == LEFT_CHILD) replace->parent->left = replace;
                else replace->parent->right = replace;
            }
        }
        void _erase(iterator position, bool erase) {
            _erase(position);
            delete position.base;
        }
        iterator erase(iterator position) {
            node_ptr at = position.base;
            iterator ans = position;
            ++ans;
            if(at == _begin) _begin = (++iterator(position)).base;
            if(at == _rbegin) _rbegin = (--iterator(position)).base;
            if(at->size == 1) {
                _add_path(at, -1);
                if(at->parent->is_nil()) _root = NIL;
                else if(at->child == LEFT_CHILD) at->parent->left = NIL;
                else at->parent->right = NIL;
            }
            else if(at->right->is_nil()) {
                if(at->parent->is_nil()) _root = at->left;
                else if(at->child == LEFT_CHILD) at->parent->left = at->left;
                else at->parent->right = at->left;
                at->left->parent = at->parent;
                at->left->child = at->child;
                at->left->size = at->size;
                _add_path(at->left, -1);
            }
            else if(at->left->is_nil()) {
                if(at->parent->is_nil()) _root = at->right;
                else if(at->child == LEFT_CHILD) at->parent->left = at->right;
                else at->parent->right = at->right;
                at->right->parent = at->parent;
                at->right->child = at->child;
                at->right->size = at->size;
                _add_path(at->right, -1);
            }
            else if(at->left->size > at->right->size) {
                node_ptr replace = (--iterator(position)).base;
                _add_path(replace, -1);
                replace->size = at->size;
                if(at->left != replace) {
                    replace->parent->right = replace->left;
                    if(!replace->left->is_nil()) {
                        replace->left->parent = replace->parent;
                        replace->left->child = RIGHT_CHILD;
                    }
                }
                replace->parent = at->parent;
                replace->child = at->child;
                if(at->left != replace) {
                    replace->left = at->left;
                    if(!replace->left->is_nil()) replace->left->parent = replace;
                }
                replace->right = at->right;
                if(!replace->right->is_nil()) replace->right->parent = replace;
                if(replace->parent->is_nil()) _root = replace;
                else if(replace->child == LEFT_CHILD) replace->parent->left = replace;
                else replace->parent->right = replace;
            }
            else {
                node_ptr replace = (++iterator(position)).base;
                _add_path(replace, -1);
                replace->size = at->size;
                if(at->right != replace) {
                    replace->parent->left = replace->right;
                    if(!replace->right->is_nil()) {
                        replace->right->parent = replace->parent;
                        replace->right->child = LEFT_CHILD;
                    }
                }
                replace->parent = at->parent;
                replace->child = at->child;
                replace->left = at->left;
                if(!replace->left->is_nil()) replace->left->parent = replace;
                if(at->right != replace) {
                    replace->right = at->right;
                    if(!replace->right->is_nil()) replace->right->parent = replace;
                }
                if(replace->parent->is_nil()) _root = replace;
                else if(replace->child == LEFT_CHILD) replace->parent->left = replace;
                else replace->parent->right = replace;
            }
            delete at;
            return ans;
        }
        iterator erase(iterator first, iterator last) {
            iterator ans = last;
            ++ans;
            while(first != last) first = erase(first);
            return ans;
        }
        size_type erase(const key_type& x) {
            iterator at = find(x);
            if(at == end()) return 0;
            erase(at);
            return 1;
        }
        iterator find(const key_type& x) const {
            node_ptr ans = _root;
            while(!ans->is_nil()) {
                if(key_compare(*ans->val, x)) ans = ans->right;
                else if(key_compare(x, *ans->val)) ans = ans->left;
                else break;
            }
            return iterator(this, ans);
        }
        iterator find_by_order(difference_type x) const {
            node_ptr ans = _root;
            x -= _root->left->size;
            while(!ans->is_nil() && x) {
                if(x > 0) {
                    ans = ans->right;
                    x -= ans->left->size + 1;
                }
                else if(x < 0) {
                    ans = ans->left;
                    x += ans->right->size + 1;
                }
            }
            return iterator(this, ans);
        }
        std::pair<iterator, bool> insert(value_type&& y) {
            pointer p = traits::allocate(alloc, 1);
            traits::construct(alloc, p, y);
            return _insert(p);
        }
        std::pair<iterator, bool> insert(const value_type& x) {
            pointer p = traits::allocate(alloc, 1);
            traits::construct(alloc, p, x);
            return _insert(p);
        }
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last) {
            if(empty()) {
                operator=(set(first, last));
                return;
            }
            std::vector<pointer> p;
            while(first != last) {
                p.push_back(traits::allocate(alloc, 1));
                traits::construct(alloc, p.back(), *first);
                ++first;
            }
            if(!std::is_sorted(p.begin(), p.end(), [this](pointer a, pointer b){ return key_compare(*a, *b); }))
                std::sort(p.begin(), p.end(), [this](pointer a, pointer b) { return key_compare(*a, *b); } );
            p.erase(std::unique(p.begin(), p.end(), [this](pointer a, pointer b) { return _equal(*a, *b); } ), p.end());
            int i = 0;
            if(key_compare(*p[0], *begin())) {
                _insert_left(_begin, p[0]);
                ++i;
            }
            iterator l = begin(), r = ++begin();
            for(; i < p.size(); ++i) {
                while(!r.base->is_nil() && !key_compare(*p[i], *r)) l = r++;
                if(key_compare(*p[i], *l)) {
                    traits::deallocate(alloc, p[i], 1);
                    continue;
                }
                if(l.base->right->is_nil()) {
                    l.base = l.base->right = new node(l.base, RIGHT_CHILD, p[i]);
                    if(_rbegin == l.base) _rbegin = l.base->right;
                }
                else {
                    l.base = r.base->left = new node(r.base, LEFT_CHILD, p[i]);
                    if(_begin == r.base) _begin = r.base->left;
                }
            }
            _update_size(_root);
            _update(_root);
        }
        void insert(std::initializer_list<value_type> init) { insert(init.begin(), init.end()); }
        std::pair<iterator, bool> _insert(pointer p) {
            if(_root->is_nil()) {
                _root = _begin = _rbegin = new node(NIL, LEFT_CHILD, p, 1);
                return {begin(), true};
            }
            node_ptr at = _root;
            while(true) {
                if(key_compare(*at->val, *p)) {
                    if(at->right->is_nil()) {
                        _insert_right(at, p);
                        return {iterator(this, at->right), true};
                    }
                    else at = at->right;
                }
                else if(key_compare(*p, *at->val)) {
                    if(at->left->is_nil()) {
                        _insert_left(at, p);
                        return {iterator(this, at->left), true};
                    }
                    else at = at->left;
                }
                else {
                    traits::deallocate(alloc, p, 1);
                    return {iterator(this, at), false};
                }
            }
        }
        void _insert_all(std::vector<pointer> &p) {
            if(p.empty()) return;
            if(!std::is_sorted(p.begin(), p.end(), [this](pointer a, pointer b){ return key_compare(*a, *b); }))
                std::sort(p.begin(), p.end(), [this](pointer a, pointer b) { return key_compare(*a, *b); } );
            p.erase(std::unique(p.begin(), p.end(), [this](pointer a, pointer b) { return _equal(*b, *a); } ), p.end());
            std::function<void(node_ptr, int, size_type, size_type)> insert = [this, &insert, &p](node_ptr at, int child, size_type l, size_type r) {
                if(l >= r) return;
                size_type cen = (l + r) / 2;
                node_ptr next;
                if(child == LEFT_CHILD) next = at->left = new node(at, LEFT_CHILD, p[cen], r - l);
                else next = at->right = new node(at, RIGHT_CHILD, p[cen], r - l);
                insert(next, LEFT_CHILD, l, cen);
                insert(next, RIGHT_CHILD, cen + 1, r);
            };
            size_type cen = p.size() / 2;
            _root = _begin = _rbegin = new node(NIL, LEFT_CHILD, p[cen], p.size());
            insert(_root, LEFT_CHILD, 0, cen);
            insert(_root, RIGHT_CHILD, cen + 1, p.size());
            while(!_begin->left->is_nil()) _begin = _begin->left;
            while(!_rbegin->right->is_nil()) _rbegin = _rbegin->right;
        }
        void _insert_left(node_ptr at, pointer val) {
            at->left = new node(at, LEFT_CHILD, val);
            if(_begin == at) _begin = at->left;
            _add_path(at->left, 1);
            _maintain_path(at);
        }
        void _insert_right(node_ptr at, pointer val) {
            at->right = new node(at, RIGHT_CHILD, val);
            if(_rbegin == at) _rbegin = at->right;
            _add_path(at->right, 1);
            _maintain_path(at);
        }
        iterator lower_bound(const key_type& x) const { return operator>=(x); }
        void _maintain(node_ptr at, bool flag) {
            node_ptr& fixed = at->parent->is_nil() ? _root : at->child == LEFT_CHILD ? at->parent->left : at->parent->right;
            if (flag) {
                if (at->left->size < at->right->left->size) {
                    _rotate_right(at->right);
                    _rotate_left(at);
                }
                else if (at->left->size < at->right->right->size) _rotate_left(at);
                else return;
            }
            else {
                if (at->right->size < at->left->right->size) {
                    _rotate_left(at->left);
                    _rotate_right(at);
                }
                else if (at->right->size < at->left->left->size) _rotate_right(at);
                else return;
            }
            _maintain(fixed->left, false);
            _maintain(fixed->right, true);
            _maintain(fixed, true);
            _maintain(fixed, false);
        }
        void _maintain_path(node_ptr from) {
            while(from != _root) {
                node_ptr& fixed = from->parent->is_nil() ? _root : from->child == LEFT_CHILD ? from->parent->left : from->parent->right;
                from = from->parent;
                _maintain(fixed, false);
                _maintain(fixed, true);
            }
            _maintain(_root, false);
            _maintain(_root, true);
        }
        void merge(set& source) {
            if(empty()) {
                operator=(set(source));
                source.clear();
                return;
            }
            if(source.empty()) return;
            iterator p = source.begin();
            if(key_compare(*p, *begin())) {
                iterator q = p++;
                _move(source, q, _begin, LEFT_CHILD);
            }
            iterator l = begin(), r = ++begin();
            while(p != source.end()) {
                while(!r.base->is_nil() && !key_compare(*p, *r)) l = r++;
                if(key_compare(*p, *l)) {
                    ++p;
                    continue;
                }
                if(l.base->right->is_nil()) {
                    iterator q = p++;
                    _move(source, q, l.base, RIGHT_CHILD);
                    l.base = l.base->right;
                }
                else {
                    iterator q = p++;
                    _move(source, q, r.base, LEFT_CHILD);
                    l.base = r.base->left;
                }
            }
            _update_size(_root);
            _update(_root);
        }
        void merge(set&& source) { if(size() < source.size()) swap(source); merge(static_cast<set&>(source)); }
        difference_type order_of_key(iterator position) const {
            if(position == end()) return size();
            node_ptr at = position.base;
            difference_type ans = 0;
            while(at != _root) {
                if(at->child == LEFT_CHILD) ans -= at->right->size + 1;
                else ans += at->left->size + 1;
                at = at->parent;
            }
            return ans + at->left->size;
        }
        void _move(set& source, iterator from, node_ptr to, int child) {
            source._erase(from);
            node_ptr at = from.base;
            if(child == LEFT_CHILD) {
                to->left = at;
                at->parent = to;
                at->left = NIL;
                at->right = NIL;
                at->child = LEFT_CHILD;
                if(_begin == to) _begin = at;
            }
            else {
                to->right = at;
                at->parent = to;
                at->left = NIL;
                at->right = NIL;
                at->child = RIGHT_CHILD;
                if(_rbegin == to) _rbegin = at;
            }
        }
        reverse_iterator rbegin() const noexcept { return reverse_iterator(end()); }
        reverse_iterator rend() const noexcept { return reverse_iterator(begin()); }
        void _rotate_left(node_ptr at) {
            if(at->parent->is_nil()) _root = at->right;
            else {
                if(at->child == LEFT_CHILD) at->parent->left = at->right;
                else at->parent->right = at->right;
            }
            at->right->parent = at->parent;
            at->right->size = at->size;
            at->right->child = at->child;
            at->parent = at->right;
            at->child = LEFT_CHILD;
            at->right = at->parent->left;
            if(!at->right->is_nil()) {
                at->right->parent = at;
                at->right->child = RIGHT_CHILD;
            }
            at->parent->left = at;
            at->size = at->left->size + at->right->size + 1;
        }
        void _rotate_right(node_ptr at) {
            if(at->parent->is_nil()) _root = at->left;
            else {
                if(at->child == LEFT_CHILD) at->parent->left = at->left;
                else at->parent->right = at->left;
            }
            at->left->parent = at->parent;
            at->left->size = at->size;
            at->left->child = at->child;
            at->parent = at->left;
            at->child = RIGHT_CHILD;
            at->left = at->parent->right;
            if(!at->left->is_nil()) {
                at->left->parent = at;
                at->left->child = LEFT_CHILD;
            }
            at->parent->right = at;
            at->size = at->left->size + at->right->size + 1;
        }
        size_type size() const noexcept { return _root->size; }
        void swap(set& st) {
            std::swap(key_compare, st.key_compare);
            std::swap(_root, st._root);
            std::swap(_begin, st._begin);
            std::swap(_rbegin, st._rbegin);
        }
        void _update(node_ptr& at) {
            if(at->is_nil()) return;
            _maintain(at, true);
            _maintain(at, false);
            _update(at->left);
            _update(at->right);
        }
        void _update_size(node_ptr at) {
            if(at->is_nil()) return;
            _update_size(at->left);
            _update_size(at->right);
            at->size = at->left->size + at->right->size + 1;
        }
        iterator upper_bound(const key_type& x) const { return operator>(x); }
        set& operator=(set&& x) {
            clear();
            key_compare = std::move(x.key_compare);
            _root = x._root;
            _begin = x._begin;
            _rbegin = x._rbegin;
            x._root = NIL;
            return *this;
        }
        set& operator=(const set& x) { operator=(set(x.begin(), x.end())); }
        set& operator=(std::initializer_list<value_type> init) { operator=(set(init.begin(), init.end())); }
        bool operator==(const set& x) const {
            iterator a = begin(), b = x.begin();
            while(a != end() && b != x.end()) {
                if(!_equal(*a, *b)) return false;
                ++a; ++b;
            }
            return a == end() && b == x.end();
        }
        bool operator!=(const set& x) const { return operator==(x); }
        bool operator<(const set& x) const {
            iterator a = begin(), b = x.begin();
            while(true) {
                if(b == x.end()) return false;
                if(a == end()) return true;
                if(key_compare(*a, *b)) return true;
                if(key_compare(*b, *a)) return false;
                ++a; ++b;
            }
        }
        bool operator<=(const set& x) const { return !x.operator<(*this); }
        bool operator>(const set& x) const { return x.operator<(*this); }
        bool operator>=(const set& x) const { return !operator<(x); }
        iterator operator==(const key_type& x) const { return find(x); }
        iterator operator<(const key_type& x) const {
            node_ptr ans = NIL, at = _root;
            while(!at->is_nil()) {
                if(key_compare(*at->base, x)) { ans = at; at = at->right; }
                else at = at->left;
            }
            return iterator(this, ans);
        }
        iterator operator<=(const key_type& x) const {
            node_ptr ans = NIL, at = _root;
            while(!at->is_nil()) {
                if(key_compare(x, *at->base)) at = at->left;
                else if(key_compare(*at->base, x)) { ans = at; at = at->right; }
                else return iterator(this, at);
            }
            return iterator(this, ans);
        }
        iterator operator>(const key_type& x) const {
            node_ptr ans = NIL, at = _root;
            while(!at->is_nil()) {
                if(key_compare(x, *at->base)) { ans = at; at = at->left; }
                else at = at->right;
            }
            return iterator(this, ans);
        }
        iterator operator>=(const key_type& x) const {
            node_ptr ans = NIL, at = _root;
            while(!at->is_nil()) {
                if(key_compare(*at->base, x)) at = at->right;
                else if(key_compare(x, *at->base)) { ans = at; at = at->left; }
                else return iterator(this, at);
            }
            return iterator(this, ans);
        }
        set operator|(const set& x) const {
            std::vector<Key> v;
            std::set_union(begin(), end(), x.begin(), x.end(), std::inserter(v, v.end()), key_compare);
            return set(v.begin(), v.end());
        }
        set& operator|=(set&& x) { merge(x); return *this; }
        set& operator|=(const set& x){
            if(empty()) {
                operator=(set(x));
                return *this;
            }
            if(x.empty()) return *this;
            iterator p = x.begin();
            if(key_compare(*p, *begin())) {
                pointer val = traits::allocate(alloc, 1);
                traits::construct(alloc, val, *p);
                _begin = _begin->left = new node(_begin, LEFT_CHILD, val);
                ++p;
            }
            iterator l = begin(), r = ++begin();
            while(p != x.end()) {
                while(!r.base->is_nil() && !key_compare(*p, *r)) l = r++;
                if(key_compare(*l, *p)) {
                    if(l.base->right->is_nil()) {
                        pointer val = traits::allocate(alloc, 1);
                        traits::construct(alloc, val, *p);
                        l.base = l.base->right = new node(l.base, RIGHT_CHILD, val);
                    }
                    else {
                        pointer val = traits::allocate(alloc, 1);
                        traits::construct(alloc, val, *p);
                        l.base = r.base->left = new node(r.base, LEFT_CHILD, val);
                    }
                }
                ++p;
            }
            _update_size(_root);
            _update(_root);
            return *this;
        }
        set operator&(const set& x) const {
            std::vector<Key> v;
            std::set_intersection(begin(), end(), x.begin(), x.end(), std::inserter(v, v.end()), key_compare);
            return set(v.begin(), v.end());
        }
        set& operator&=(set&& x) {
            if(size() > x.size()) swap(x);
            operator&=(static_cast<const set&>(x));
            return *this;
        }
        set& operator&=(const set& x) {
            iterator p = begin(), q = x.begin();
            while(p != end() && q != x.end()) {
                if(key_compare(*p, *q)) _erase(p++, true);
                else if(key_compare(*q, *p)) ++q;
                else { ++p; ++q; }
            }
            if(q == x.end()) while(p != end()) _erase(p++, true);
            _update_size(_root);
            return *this;
        }
        set operator^(const set& x) const {
            std::vector<Key> v;
            std::set_symmetric_difference(begin(), end(), x.begin(), x.end(), std::inserter(v, v.end()), key_compare);
            return set(v.begin(), v.end());
        }
        set& operator^=(set&& x) {
            if(size() < x.size()) swap(x);
            operator^=(static_cast<const set&>(x));
            return *this;
        }
        set& operator^=(const set& x) {
            if(empty()) {
                operator=(set(x));
                return *this;
            }
            if(x.empty()) return *this;
            iterator p = x.begin();
            if(key_compare(*p, *begin())) {
                pointer val = traits::allocate(alloc, 1);
                traits::construct(alloc, val, *p);
                _begin = _begin->left = new node(_begin, LEFT_CHILD, val);
                ++p;
            }
            else while(!_root->is_nil() && p != x.end() && _equal(*begin(), *p)) {
                _erase(begin(), true);
                ++p;
            }
            if(empty()) {
                operator=(set(p, x.end()));
                return *this;
            }
            iterator l = begin(), r = ++begin();
            while(p != x.end()) {
                while(!r.base->is_nil() && !key_compare(*p, *r)) l = r++;
                if(!key_compare(*l, *p)) {
                    _erase(l--, true);
                }
                else if(l.base->right->is_nil()) {
                    pointer val = traits::allocate(alloc, 1);
                    traits::construct(alloc, val, *p);
                    l.base = l.base->right = new node(l.base, RIGHT_CHILD, val);
                }
                else {
                    pointer val = traits::allocate(alloc, 1);
                    traits::construct(alloc, val, *p);
                    l.base = r.base->left = new node(r.base, LEFT_CHILD, val);
                }
                ++p;
            }
            _update_size(_root);
            _update(_root);
            return *this;
        }
        set operator-(const set& x) const {
            std::vector<Key> v;
            std::set_difference(begin(), end(), x.begin(), x.end(), std::inserter(v, v.end()), key_compare);
            return set(v.begin(), v.end());
        }
        set& operator-=(const set& x) {
            iterator p = begin(), q = x.begin();
            while(p != end() && q != x.end()) {
                if(key_compare(*p, *q)) ++p;
                else if(key_compare(*q, *p)) ++q;
                else {
                    _erase(p++, true);
                    ++q;
                }
            }
            _update_size(_root);
            return *this;
        }
        
        struct node {
            pointer val;
            node *parent = NIL, *left = NIL, *right = NIL;
            size_type size = 0;
            int child = NIL_CHILD;
            node() {}
            node(node_ptr parent, int child, pointer val, size_type size = 0): parent(parent), val(val), child(child), size(size) {}
            ~node() { if(!is_nil()) { alloc.deallocate(val, 1); } }
            bool is_nil() const { return !child; }
        };
        
        struct iterator : public std::iterator<std::random_access_iterator_tag, Key> {
            using set_ptr = const set*;
            set_ptr parent;
            node_ptr base;
            iterator(set_ptr parent, node_ptr base): parent(parent), base(base) {}
            value_type& operator*() const { return *base->val; }
            pointer operator->() const noexcept { return base->val; }
            iterator& operator++() {
                if(base->right->is_nil()) {
                    while(base->child == RIGHT_CHILD) base = base->parent;
                    base = base->parent;
                }
                else {
                    base = base->right;
                    while(!base->left->is_nil()) base = base->left;
                }
                return *this;
            }
            iterator operator++(int) {
                iterator ans = *this;
                operator++();
                return ans;
            }
            iterator& operator--() {
                if(base->is_nil()) {
                    base = parent->_rbegin;
                    return *this;
                }
                if(base->left->is_nil()) {
                    while(base->child == LEFT_CHILD) base = base->parent;
                    base = base->parent;
                }
                else {
                    base = base->left;
                    while(!base->right->is_nil()) base = base->right;
                }
                return *this;
            }
            iterator operator--(int) {
                iterator ans = *this;
                operator--();
                return ans;
            }
            iterator& operator+=(difference_type n) {
                if(base->is_nil()) {
                    base = parent->_root;
                    n += base->right->size + 1;
                }
                while(n && !base->is_nil()) {
                    if(n > 0) {
                        if(n <= base->right->size) {
                            base = base->right;
                            n -= base->left->size + 1;
                        }
                        else {
                            n -= base->right->size + 1;
                            while(base->child == RIGHT_CHILD) base = base->parent;
                            base = base->parent;
                        }
                    }
                    else {
                        if(-n <= base->left->size) {
                            base = base->left;
                            n += base->right->size + 1;
                        }
                        else {
                            n += base->left->size + 1;
                            while(base->child == LEFT_CHILD) base = base->parent;
                            base = base->parent;
                        }
                    }
                }
                return *this;
            }
            iterator operator+(difference_type n) const {
                iterator ans = *this;
                return ans += n;
            }
            iterator& operator-=(difference_type n) { return operator+=(-n); }
            iterator operator-(difference_type n) const {
                iterator ans = *this;
                return ans += -n;
            }
            difference_type operator-(const iterator& it) const { return parent->order_of_key(*this) - parent->order_of_key(it); }
            bool operator==(const iterator& it) const { return base == it.base; }
            bool operator!=(const iterator& it) const { return base != it.base; }
            bool operator<(const iterator& it) const {
                if(base->is_nil()) return false;
                if(it.base->is_nil()) return true;
                return parent->key_compare(*this, *it);
            }
            bool operator>(const iterator& it) const { return it.operator<(*this); }
            bool operator<=(const iterator& it) const { return !it.operator<(*this); }
            bool operator>=(const iterator& it) const { return !operator<(it); }
        };
    };
    
    template <class Key, class Compare>
    typename set<Key, Compare>::node set<Key, Compare>::_NIL = set<Key, Compare>::node();
    template <class Key, class Compare>
    typename set<Key, Compare>::node_ptr set<Key, Compare>::NIL = &set<Key, Compare>::_NIL;
    template <class Key, class Compare>
    typename set<Key, Compare>::allocator_type set<Key, Compare>::alloc = set<Key, Compare>::allocator_type();
};

signed main(){
    LL(n,k);
    STR(s);
    ll c0=0,c1=0;
    rep(i,k,n)(s[i]&1?c1:c0)++;
    if(!c0||!c1)return out("tokitsukaze");
    rep(i,k,n){
        (s[i]&1?c1:c0)--;
        (s[i-k]&1?c1:c0)++;
        if(!c0||!c1)return out("tokitsukaze");
    }
    tatyam::set<ll>s0,s1;
    rep(i,k,n)(s[i]&1?s1:s0).insert(i);
    if(*s0.rbegin()-*s0.begin()+1>k)return out("once again");
    if(*s1.rbegin()-*s1.begin()+1>k)return out("once again");
    rep(i,k,n){
        (s[i]&1?s1:s0).erase(i);
        (s[i-k]&1?s1:s0).insert(i-k);
        if(*s0.rbegin()-*s0.begin()+1>k)return out("once again");
        if(*s1.rbegin()-*s1.begin()+1>k)return out("once again");
    }
    out("quailty");
}