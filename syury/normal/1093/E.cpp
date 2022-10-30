#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

namespace FastIO{
	const unsigned BUFFER_SIZE = 1 << 12;
	class InputReader{
		protected:
		char buffer[BUFFER_SIZE];
		FILE * file = nullptr;
		size_t ptr = 0;
		size_t len = 0;
		bool isEnd = false;
		public:
		inline bool end(){return isEnd;}
		static inline bool isDigit(char c){return c >= '0' && c <= '9';}
		static inline bool isSpace(char c){return (unsigned char)(c - '\t') < 5 || c == ' ';}
		static inline bool isNotSpace(char c){return !isSpace(c);}
		static inline bool isUpper(char c){return (unsigned char)(c - 'A') < 26;}
 		static inline bool isLower(char c){return (unsigned char)(c - 'a') < 26;}
		static inline bool isAlpha(char c){return isUpper(c) || isLower(c);}
		static inline bool isNotEndl(char c){return c != '\n';}
		InputReader(){}
		InputReader(FILE * _file):file(_file){}
		inline bool readChar(char & dest){
			if(__builtin_expect(ptr == len, false)){
				len = fread((void*)buffer, 1, BUFFER_SIZE, file);
				ptr = 0;
			}
			if(__builtin_expect(ptr == len, false)){
				dest = '\0';
				isEnd = true;
				return false;
			}
			dest = buffer[ptr++];
			return true;
		}
		template<class F>
		inline char skipCharacters(F check){
			char c;
			do{
				if(__builtin_expect(!readChar(c), false))
					return '\0';
			}while(!check(c));
			return c;
		}
		template<class T>
		inline int readUInteger(T & dest){
			T value = 0;
			int length = 0;
			char start = skipCharacters(isDigit);
			if(__builtin_expect(start == '\0', false))
				return 0;
			while(isDigit(start)){
				++length;	
				start -= '0';
				value = value * 10 + start;
				readChar(start);
			}
			ptr--;
			dest = value;
			return length;
		}
		template<class T>
		inline int readInteger(T & dest){
			char start = skipCharacters([](char c){return isDigit(c) || c == '-';});	
			if(__builtin_expect(start == '\0', false))
				return 0;
			bool neg = start == '-';
			if(neg)
				readChar(start);
			if(__builtin_expect(start == '\0', false))
				return 0;
			ptr--;
			int flag = readUInteger(dest);
			if(neg)
				dest = -dest;
			return flag;
		}
		template<class T>
		inline bool readFloat(T & dest){
			char start = skipCharacters([](char c){return isDigit(c) || c == '-';});
			if(__builtin_expect(start == '\0', false))
				return 0;
			bool neg = start == '-';
			if(neg)
				readChar(start);
			if(__builtin_expect(start == '\0', false))
				return 0;
			ptr--;
			unsigned long long p;
			if(!readUInteger(p))return false;
			dest = static_cast<T>(p);
			char c;
			readChar(c);
			if(c == '.'){
				unsigned long long q;
				int l;
				l = readUInteger(q);
				if(l > 0){
					unsigned long long pw = 1;
					while(l){
						pw *= 10;
						--l;
					}
					dest += static_cast<T>(q)/pw;
				}
			}
			else --ptr;
			if(neg)
				dest = -dest;
			return true;
		}
		template<class F>
		inline int readString(string & dest, F check){
			dest.clear();
			char c = skipCharacters(check);
			if(__builtin_expect(c == '\0', false)){dest = ""; return 0;}
			int l = 0;
			while(check(c)){
				dest += c;
				++l;
				if(__builtin_expect(!readChar(c), false))
					break;
			}
			--ptr;
			return l;
		}
		inline int readString(string & dest){
			return readString(dest, isNotSpace);
		}
		template<class F>
		inline int readCString(char * dest, F check){
			char c = skipCharacters(check);
			if(__builtin_expect(c == '\0', false)){*dest = '\0'; return 0;}
			int l = 0;
			while(check(c)){
				*dest = c;
				++dest;
				++l;
				if(__builtin_expect(!readChar(c), false))
					break;
			}
			--ptr;
			*dest = '\0';
			return l;
		}
		inline int readCString(char * dest){
			return readCString(dest, isNotSpace);
		}
	};
	class OutputWriter{
		protected:
		char buffer[BUFFER_SIZE];
		char tmp[BUFFER_SIZE];
		FILE * file;
		size_t len = 0;
		int tptr = 0;
		unsigned long long basePw = 1;
		int prec = 0;
		template<class T>
		inline void processUInteger(T what){
			tptr = 0;
			while(what > 0){
				tmp[tptr++] = what % 10;
				what /= 10;
			}
		}
		public:
		OutputWriter():file(nullptr){}
		OutputWriter(FILE * _file):file(_file){}
		inline void flush(){
			fwrite((void*)buffer, 1, len, file);
			len = 0;
		}
		~OutputWriter(){flush();}
		inline void checkFlush(size_t space = 0){
			if(__builtin_expect(len + space >= BUFFER_SIZE, false))
				flush();
		}
		inline void precision(int val){
			basePw = 1;
			prec = 0;
			while(val > 0){
				basePw *= 10;
				--val;
				++prec;
			}
		}
		inline void writeChar(char c){
			checkFlush(1);
			buffer[len++] = c;
		}
		template<class T>
		inline void writeUInteger(T what){
			if(what == 0){
				writeChar('0');
				return;
			}
			processUInteger(what);
			checkFlush(tptr);
			for(int i = tptr - 1; i >= 0; i--)
				buffer[len++] = tmp[i] + '0';
		}
		template<class T>
		inline void writeUInteger(T what, char delim){
			writeUInteger(what);
			writeChar(delim);
		}
		template<class T>
		inline void writeInteger(T what){
			if(what < 0){
				writeChar('-');
				what = -what;
			}
			writeUInteger(what);
		}
		template<class T>
		inline void writeInteger(T what, char delim){
			writeInteger(what);
			writeChar(delim);
		}
		inline void writeString(const string & s){
			for(char c : s)
				writeChar(c);
		}
		inline void writeString(const string & s, char delim){
			writeString(s);
			writeChar(delim);
		}
		inline void writeCString(const char * s){
			while(*s != '\0')
				writeChar(*(s++));
		}
		inline void writeCString(const char * s, char delim){
			writeCString(s);
			writeChar(delim);
		}
		template<class T>
		inline void writeFloat(T what){
			bool neg = signbit(what);
			if(neg){
				what = -what;
				writeChar('-');
			}
			if(isnan(what)){
				writeChar('N'); writeChar('a'); writeChar('N');
				return;
			}
			if(isinf(what)){
				writeChar('I'); writeChar('n'); writeChar('f');
				return;
			}
			auto p = static_cast<unsigned long long>(what);
			auto q = static_cast<unsigned long long>((what - p) * basePw + T(0.5));
			if(q >= basePw){++p; q = 0;}
			writeUInteger(p);
			if(prec == 0)return;
			writeChar('.');
			processUInteger(q);
			for(int i = tptr; i < prec; i++)
				writeChar('0');
			checkFlush(tptr);
			for(int i = tptr - 1; i >= 0; i--)
				buffer[len++] = tmp[i] + '0';
		}
		template<class T>
		inline void writeFloat(T what, char delim){
			writeFloat(what);
			writeChar(delim);
		}
	};
}
const int N = (int)2e5 + 5;

struct StaticSolver{
	static const int SQRT = 1000;
	static const int CNT = N/SQRT + 2;
	struct block{
		int * p;
		int l, r;
	};
	int n;
	int * a;
	int * bpos;
	block b[CNT];
	int blocks = 0;
	void calc_block(block & kek, int l, int r){
		F(i, l, r + 1)
			kek.p[i - l] = bpos[a[i]];
		sort(kek.p, kek.p + r - l + 1);
	}
	block make_block(int l, int r){
		block kek;
		kek.l = l; kek.r = r;
		kek.p = new int[r - l + 1];
		calc_block(kek, l, r);
		return kek;
	}
	void recalc_bpos(int * b){
		F(i, 0, n)
			bpos[b[i]] = i;
	}
	void build(){
		int prv = 0;
		F(i, 0, n){
			if(i - prv >= SQRT){
				b[blocks++] = make_block(prv, i - 1);
				prv = i;
			}
		}
		b[blocks++] = make_block(prv, n - 1);
	}
	void rebuild(){
		blocks = 0;
		int prv = 0;
		F(i, 0, n){
			if(i - prv >= SQRT){
				calc_block(b[blocks++], prv, i - 1);
				prv = i;
			}
		}
		calc_block(b[blocks++], prv, n - 1);
	}
	int solve(int la, int ra, int lb, int rb){
		int ans = 0;
		F(j, 0, blocks){
			if(b[j].l > ra)
				break;
			if(b[j].r < la)
				cont;
			int l = max(la, b[j].l), r = min(ra, b[j].r);
			if(l == b[j].l && r == b[j].r){
				int cr = upper_bound(b[j].p, b[j].p + b[j].r - b[j].l + 1, rb) - b[j].p;
				int cl = lower_bound(b[j].p, b[j].p + b[j].r - b[j].l + 1, lb) - b[j].p;
				ans += cr - cl;
				continue;
			}
			F(i, l, r + 1)
				if(bpos[a[i]] >= lb && bpos[a[i]] <= rb)
					++ans;
		}
		ret ans;
	}
	StaticSolver(int * _a, int * b, int _n):n(_n){
		a = new int[n];
		bpos = new int[n];
		blocks = 0;
		memcpy(a, _a, n * sizeof(int));
		F(i, 0, n)
			bpos[b[i]] = i;
		build();
	}
};

struct query{
	int tp;
	int a, b, c, d;
};

const int SQRT = 800;

StaticSolver * s;
int n, q;
int a[N], b[N], oldb[N];
int pa[N], pb[N], opb[N];

void process(vector<query> & qs, FastIO::OutputWriter & out){
	set<int> used;
	memcpy(opb, pb, n * sizeof(int));
	F(i, 0u, qs.size()){
		if(qs[i].tp == 2){
			used.ins(b[qs[i].a]);
			used.ins(b[qs[i].b]);
			swap(pb[b[qs[i].a]], pb[b[qs[i].b]]);
			swap(b[qs[i].a], b[qs[i].b]);
			continue;
		}
		int ans = s->solve(qs[i].a, qs[i].b, qs[i].c, qs[i].d);
		I(x, used){
			if(pa[x] >= qs[i].a && pa[x] <= qs[i].b && opb[x] >= qs[i].c && opb[x] <= qs[i].d)
				--ans;
			if(pa[x] >= qs[i].a && pa[x] <= qs[i].b && pb[x] >= qs[i].c && pb[x] <= qs[i].d)
				++ans;
		}
		out.writeInteger(ans, '\n');
	}
	memcpy(oldb, b, n * sizeof(int));
	s->recalc_bpos(b);
	s->rebuild();
	F(i, 0, n)
		pb[b[i]] = i;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sync;
	FastIO::InputReader in(stdin);
	FastIO::OutputWriter out(stdout);
	in.readInteger(n);
	in.readInteger(q);
	F(i, 0, n){
		in.readInteger(a[i]);
		--a[i];
		pa[a[i]] = i;
	}
	F(i, 0, n){
		in.readInteger(b[i]);
		--b[i];
		pb[b[i]] = i;
	}
	s = new StaticSolver(a, b, n);
	memcpy(oldb, b, n * sizeof(int));
	vector<query> qs;
	F(k, 0, q){
		int tp;
		in.readInteger(tp);
		query curr;
		curr.tp = tp;
		if(tp == 1){
			in.readInteger(curr.a); --curr.a;
			in.readInteger(curr.b); --curr.b;
			in.readInteger(curr.c); --curr.c;
			in.readInteger(curr.d); --curr.d;
			qs.pb(curr);
		}
		else{
			in.readInteger(curr.a); --curr.a;
			in.readInteger(curr.b); --curr.b;
			qs.pb(curr);
		}
		if(qs.size() == SQRT || k == q - 1){
			process(qs, out);
			qs.clear();
		}
	}
	out.flush();
	return 0;
}