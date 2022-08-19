/**
 *    author:  tourist
 *    created: 02.09.2018 18:26:55       
**/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000010;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// http://e-maxx.ru/algo/ukkonen

string s;
int n;
 
struct node {
	int l, r, par, link;
	map<char,int> next;
 
	node (int l=0, int r=0, int par=-1)
		: l(l), r(r), par(par), link(-1) {}
	int len()  {  return r - l;  }
	int &get (char c) {
		if (!next.count(c))  next[c] = -1;
		return next[c];
	}
};
node t[MAXN];
int sz;
 
struct state {
	int v, pos;
	state (int v, int pos) : v(v), pos(pos)  {}
};
state ptr (0, 0);
 
state go (state st, int l, int r) {
	while (l < r)
		if (st.pos == t[st.v].len()) {
			st = state (t[st.v].get( s[l] ), 0);
			if (st.v == -1)  return st;
		}
		else {
			if (s[ t[st.v].l + st.pos ] != s[l])
				return state (-1, -1);
			if (r-l < t[st.v].len() - st.pos)
				return state (st.v, st.pos + r-l);
			l += t[st.v].len() - st.pos;
			st.pos = t[st.v].len();
		}
	return st;
}
 
int split (state st) {
	if (st.pos == t[st.v].len())
		return st.v;
	if (st.pos == 0)
		return t[st.v].par;
	node v = t[st.v];
	int id = sz++;
	t[id] = node (v.l, v.l+st.pos, v.par);
	t[v.par].get( s[v.l] ) = id;
	t[id].get( s[v.l+st.pos] ) = st.v;
	t[st.v].par = id;
	t[st.v].l += st.pos;
	return id;
}
 
int get_link (int v) {
	if (t[v].link != -1)  return t[v].link;
	if (t[v].par == -1)  return 0;
	int to = get_link (t[v].par);
	return t[v].link = split (go (state(to,t[to].len()), t[v].l + (t[v].par==0), t[v].r));
}
 
void tree_extend (int pos) {
	for(;;) {
		state nptr = go (ptr, pos, pos+1);
		if (nptr.v != -1) {
			ptr = nptr;
			return;
		}
 
		int mid = split (ptr);
		int leaf = sz++;
		t[leaf] = node (pos, n, mid);
		t[mid].get( s[pos] ) = leaf;
 
		ptr.v = get_link (mid);
		ptr.pos = t[ptr.v].len();
		if (!mid)  break;
	}
}
 
void build_tree() {
	sz = 1;
	for (int i=0; i<n; ++i)
		tree_extend (i);
}

struct stateX {
  int v;
  int l;
  int r;

  stateX() {
    v = 0;
    l = r = 0;
  }

  void go(char c) {
    if (l == r) {
      if (t[v].next.find(c) == t[v].next.end()) {
        v = -1;
      } else {
        v = t[v].next[c];
        l = t[v].l + 1;
        r = t[v].r;
      }
    } else {
      if (s[l] != c) {
        v = -1;
      } else {
        l++;
      }
    }
  }
};

struct query {
  int from;
  int to;
  int id;
  int pos;
  char ch;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  s = s + "$";
  n = (int) s.size();
  build_tree();
  int m;
  cin >> m;
  vector<string> xs(m);
  vector<int> change_pos(m, -1);
  vector<char> change_char(m, '.');
  auto update = [&](int id, int pos, char ch) {
    if (pos > change_pos[id] || (pos == change_pos[id] && ch < change_char[id])) {
      change_pos[id] = pos;
      change_char[id] = ch;
    }
  };
  vector<vector<query>> qs(sz);
  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to >> xs[i];
    from--; to--;
    int len = to - from + 1;
    stateX st;
    for (int j = 0; j <= (int) xs[i].size(); j++) {
      if (j + 1 > len) {
        break;
      }
      char start = (j < (int) xs[i].size() ? (char) (xs[i][j] + 1) : 'a');
      for (char c = start; c <= 'z'; c++) {
        stateX st2 = st;
        st2.go(c);
        if (st2.v == -1) {
          continue;
        }
        qs[st2.v].push_back({from, to - j, i, j, c});
      }
      if (j == (int) xs[i].size()) {
        break;
      }
      st.go(xs[i][j]);
      if (st.v == -1) {
        break;
      }
    }
  }
  vector<set<int>> leafs(sz);
  vector<int> depth(sz, 0);
  function<void(int)> dfs = [&](int v) {
    if (t[v].next.empty()) {
      leafs[v].insert(n - depth[v]);
    }
    for (auto &p : t[v].next) {
      int u = p.second;
      depth[u] = depth[v] + (t[u].r - t[u].l);
      dfs(u);
      if (leafs[u].size() > leafs[v].size()) {
        swap(leafs[u], leafs[v]);
      }
      for (int x : leafs[u]) {
        leafs[v].insert(x);
      }
      set<int>().swap(leafs[u]);
    }
    for (auto &q : qs[v]) {
      auto it = leafs[v].lower_bound(q.from);
      if (it != leafs[v].end() && *it <= q.to) {
        update(q.id, q.pos, q.ch);
      }
    }
  };
  dfs(0);
  for (int i = 0; i < m; i++) {
    if (change_pos[i] == -1) {
      cout << -1 << '\n';
    } else {
      cout << xs[i].substr(0, change_pos[i]) << change_char[i] << '\n';
    }
  }
  return 0;
}