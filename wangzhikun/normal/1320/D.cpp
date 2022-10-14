#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
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

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
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

#define all(x) x.begin(),x.end()
#define set0(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair
#define FF first
#define SS second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ldb;

template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

const int N = 200020;
int n0[N],l0[N],cont[N],l,r,len;
char s[N];

typedef uint64_t ull;
template<int M, class B>
struct A {
	int x; B b; A(int x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() { return x ^ (ull) b << 21; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

static const H C = 1919810;

vector<H> hsh(N),pw(N);
vector<int> V;

H mhsh(int l,int len){
	if(cont[l+len-1]-cont[l-1] == 0)return H(1);
	int b= lower_bound(all(V),l+1)-V.begin(),e = lower_bound(all(V),l+len)-V.begin()-1;
	if(e!=0 && n0[V[e]]>=l+len)e-=1;
	H ans;
	int clen;
	if(e<b){
		ans = H(cont[l+len-1]-cont[l-1]+1);
		clen = 1;
	}else{
		ans = hsh[e-1]-hsh[b-1]*pw[e-b];
		clen = e-b;
		ans = ans+H(cont[V[b]]-cont[l-1]+1)*pw[clen];
		clen+=1;
		ans = ans*C+H(cont[l+len-1]-cont[V[e]]+1);
		clen+=1;
	}
	if(s[l] == '1' && (n0[l]-l)%2 == 1){
		ans = H(1)*pw[clen]+ans;
		clen+=1;
	}
	if(s[l+len-1] == '1' && (l+len-1-l0[l+len-1])%2 == 1){
		ans = ans*C+H(1);
	}
	return ans;
}
int n,q;
int main() {
	read(n);
	cin>>(s+1);
	s[0] = '0';
	n0[n+1] = n+1;
	for(int i=1;i<=n;i++){
		cont[i] = cont[i-1];
		if(s[i] == '0')cont[i]++;
		if(s[i] == '0')l0[i] = i;
		else l0[i] = l0[i-1];
	}
	for(int i=n;i>=1;i--){
		if(s[i] == '0')n0[i] = i;
		else n0[i] = n0[i+1];
	}
	cont[n+1] = cont[n];
	V.push_back(-666);
	for(int i=1;i<=n;i++){
		if(s[i] == '1' && s[i-1] == '0' && (n0[i]-i)%2 == 1) V.push_back(i);
	}
	pw[0] = 1;
	for(int i=1;i<V.size()-1;i++) hsh[i] = hsh[i-1]*C+(cont[V[i+1]]-cont[V[i]]+1);
	for(int i=1;i<N;i++)pw[i] = pw[i-1]*C;
	V.push_back(1e9);
	read(q);
	for(int ech=1;ech<=q;ech++){
		read(l,r,len);
		if((ull)mhsh(l,len) == (ull)mhsh(r,len)){
			puts("Yes");
		}else{
			puts("No");
		}
	}
	return 0;
}