#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C&a4, C b4){a4=min(a4,b4);}
template<class C> void maxi(C&a4, C b4){a4=max(a4,b4);}

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA...a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1,a...);
}

template<class T> ostream&operator<<(ostream&os, vector<T> V) {
  os<<"[";
  for (auto v : V)os<<v<<",";
  return os << "]";
}
template<class L, class R> ostream&operator<<(ostream&os, pair<L,R> P) {
  return os<<"("<<P.st<<","<<P.nd<<")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

set<string> reserved;
int max_reserved;

vector<string> Parse(string s) {
  const int len = SZ(s);
  s += " ";
  int ptr = 0;
  vector<string> tokens;
  
  while (ptr < len) {
    if (s[ptr] == ' ') { ++ptr; continue; }
    
    //debug(ptr, s[ptr]);
    string max_res;
    for (int tlen = 1; tlen <= max_reserved && ptr + tlen <= len; ++tlen) {
      const string token_opt = s.substr(ptr, tlen);
      //debug(token_opt);
      if (reserved.count(token_opt))
        max_res = token_opt;
    }
    
    string token;
    
    int old_ptr = ptr;
    
    if (isdigit(s[ptr])) {
      while (isdigit(s[ptr])) {
        token += s[ptr];
        ++ptr;
      }
    } else if (isalpha(s[ptr]) || s[ptr] == '_' || s[ptr] == '$') {
      while (isalnum(s[ptr]) || s[ptr] == '_' || s[ptr] == '$') {
        token += s[ptr];
        ++ptr;
      }
    }
    
    if (SZ(max_res) > SZ(token))
      token = max_res;
    if (SZ(token) == 0)
      return {};
    tokens.PB(token);
    ptr = old_ptr + SZ(token);
  }
  
  return tokens;
}

string code;

void Input() {
  int N, M;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    reserved.insert(s);
    maxi(max_reserved, SZ(s));
  }
  
  cin >> M;
  string line;
  while (getline(cin, line)) {
    int ptr = 0;
    while (ptr < SZ(line) && line[ptr] != '#' && line[ptr] != '\n' && line[ptr] != '\r')
      ++ptr;
    line = line.substr(0, ptr);
    code += line + " ";
  }
}

vector<string> names;

void AddName(string s) {
  if (!reserved.count(s))
    names.PB(s);
}

void GenNames() {
#define REPCH(name) for (char name = 'a'; name <= 'z'; ++name)
  REPCH (a) {
    const string sa(1, a);
    AddName(sa);
    REPCH (b) {
      AddName(sa + b);
      REPCH (c) {
        AddName(sa + b + c);
      }
    }
  }
#undef REPCH
  sort(ALL(names), [&](const string &lhs, const string &rhs) {
    return MP(SZ(lhs), lhs) < MP(SZ(rhs), rhs);
  });
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  Input();
  debug(vector<string>(ALL(reserved)), code);
  vector<string> tokens = Parse(code);
  assert(SZ(tokens) > 0);
  debug(tokens);
  
  string out;
  
  map<string, string> var_mapping;
  vector<int> last_starts;
  vector<string> out_tokens;
  int name_ptr = 0;
  GenNames();
  
  for (string token : tokens) {
    const bool is_name = !reserved.count(token) && !isdigit(token[0]);
    string new_name;
    
    if (is_name) {
      if (var_mapping.count(token)) {
        new_name = var_mapping[token];
      } else {
        new_name = names[name_ptr++];
        var_mapping[token] = new_name;
      }
    } else {
      new_name = token;
    }
    
    bool needs_space = false;
    
    int sptr = SZ(last_starts) - 1;
    bool next_break = false;
    while (sptr >= 0) {
      const int pos = last_starts[sptr];
      const string check = out.substr(pos) + new_name;
      if (SZ(check) - SZ(new_name) - 6 > max_reserved) { next_break = true; }
      auto parse_nospace = Parse(check);
      vector<string> expected;
      for (int i = sptr; i < SZ(last_starts); ++i)
        expected.PB(out_tokens[i]);
      expected.PB(new_name);
      
      if (expected != parse_nospace) {
        needs_space = true;
        break;
      }
      
      if (next_break) { break; }
      
      --sptr;
    }
    
    if (needs_space)
      out += " ";
    
    out_tokens.PB(new_name);
    last_starts.PB(SZ(out));
    out += new_name;
  }
  cout << out << "\n";
}