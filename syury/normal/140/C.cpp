#include<bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg

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
			bool neg = start == '-';
			if(neg)
				readChar(start);
			ptr--;
			int flag = readUInteger(dest);
			if(neg)
				dest = -dest;
			return flag;
		}
		template<class T>
		inline bool readFloat(T & dest){
			char start = skipCharacters([](char c){return isDigit(c) || c == '-';});
			bool neg = start == '-';
			if(neg)
				readChar(start);
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

const int maxn = 1e5 + 5;

int n;
map<int, int> cnt;
vector<pair<pii, int> > out;
set<pii, greater<pii> > ind;

signed main(){
	sync;
//	FastIO::InputReader in(stdin);
//	FastIO::OutputWriter out(stdout);
	cin >> n;
	F(i, 0, n){
		int r;
		cin >> r;
		if(!cnt.count(r))cnt[r] = 1;
		else ++cnt[r];
	}
	I(c, cnt)ind.insert({c.Y, c.X});
	while(ind.size() > 2u){
		auto it = ind.begin();
		vector<pii> curr;
		F(c, 0, 3){
			curr.pb(*ind.begin());
			ind.erase(ind.begin());
		}
		int d = 1;
		vector<int> who;
		I(x, curr)who.pb(x.Y);
		sort(all(who));
		reverse(all(who));
		for(int i = 0; i < d; i++){
			out.pb({{who[0], who[1]}, who[2]});
		}
		I(x, curr)if(x.X > d)ind.insert({x.X - d, x.Y});
	}
	cout << out.size() << '\n';
	I(c, out)cout << c.X.X << ' ' << c.X.Y << ' ' << c.Y << '\n';
	ret 0;
}