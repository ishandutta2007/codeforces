#include <bits/stdc++.h>

using namespace std;

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
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; i++)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; i--)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

#define at fjfj

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;


const int N = (int)3e3 + 3;

int n;
bool bad[N];
string s[N];
string t[N];
int L[N], R[N];
int z[2*N];

int findsub(string s, string t){
	int K = t.length() + 1;
	t += '#';
	t += s;
	z[0] = 0;
	for(int i = 1, l = 0, r = 0; i < (int)t.length(); i++){
		z[i] = 0;
		if(r >= i)
			z[i] = min(z[i - l], r - i + 1);
		while(i + z[i] < (int)t.length() && t[z[i]] == t[i + z[i]])++z[i];
		if(i+ z[i] - 1 > r){r = i + z[i] - 1; l = i;}
		if(i >= K && z[i] >= K - 1)return i - K;
	}
	return -1;
}

inline void fail(){
	cout << "NO";
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	FastIO::InputReader in(stdin);
	in.readInteger(n);
	F(i, 0, n)in.readString(s[i]);
	F(i, 0, n)in.readString(t[i]);
	string must = "";
	F(i, 0, n){
		L[i] = 0;
		R[i] = (int)s[i].length() - 1;
		while(L[i] < (int)s[i].length() && s[i][L[i]] == t[i][L[i]])++L[i];
		if(L[i] == (int)s[i].length()){
			bad[i] = 1;
			cont;
		}
		while(s[i][R[i]] == t[i][R[i]])
			--R[i];
		string cu = s[i].substr(L[i], R[i] - L[i] + 1);
		if(must.empty())must = cu;
		else if(must != cu)fail();
	}
	while(1){
		bool g = 1;
		F(i, 0, n)if(!bad[i])if(L[i] == 0)g = 0;
		if(!g)brk;
		char c = 0;
		F(i, 0, n)if(!bad[i]){if(c != 0 && s[i][L[i] - 1] != c)g = 0;c = s[i][L[i]-1];}
		if(!g)brk;
		F(i, 0, n)if(!bad[i])--L[i];
	}
	while(1){
		bool g = 1;
		F(i, 0, n)if(!bad[i])if(R[i] == (int)s[i].length() - 1)g = 0;
		if(!g)brk;
		char c = 0;
		F(i, 0, n)if(!bad[i]){if(c != 0 && s[i][R[i] + 1] != c)g = 0; c = s[i][R[i]+1];}
		if(!g)brk;
		F(i, 0, n)if(!bad[i])++R[i];
	}
	string rep;
	F(i, 0, n)if(!bad[i])rep = s[i].substr(L[i], R[i] - L[i] + 1);
	F(i, 0, n){
		if(bad[i])L[i] = -1;
		if(findsub(s[i], rep) != L[i])fail();
	}
	string got;
	F(i, 0, n)if(!bad[i])got = t[i].substr(L[i], R[i] - L[i] + 1);
	F(i, 0, n)
		if(!bad[i] && got != t[i].substr(L[i], R[i] - L[i] + 1))fail();
	cout << "YES\n";
	cout << rep << '\n';
	cout << got << '\n';
	return 0;
}