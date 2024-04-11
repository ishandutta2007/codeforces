//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

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

FastIO::InputReader in(stdin);

bool good_col[2222];
int bnd[1<<13];
int ans[1<<13];
int used[1<<13];
int msum[1<<13];
int dp[2][2][666][1<<13];
int a[20][2222];
pii b[20][2222];
int LM[1<<7], RM[1<<7];
int n, m;

void solve(){
    in.readInteger(n);
    in.readInteger(m);
    F(i, 0, n)
        F(j, 0, m){
            in.readInteger(a[i][j]);
            b[i][j] = {a[i][j], j};
        }
    memset(good_col, 0, sizeof(good_col));
    F(i, 0, n){
        sort(b[i], b[i] + m);
        reverse(b[i], b[i] + m);
        F(j, 0, min(m, 30))
            good_col[b[i][j].Y] = 1;
    }
    int ptr = 0;
    F(j, 0, m){
        if(!good_col[j])cont;
        if(ptr < j){
            F(i, 0, n)
                a[i][ptr] = a[i][j];
        }
        ++ptr;
    }
    m = ptr;
    if(m == 1){
        int ans = 0;
        F(i, 0, n)
            ans += a[i][0];
        cout << ans << '\n';
        ret;
    }
    int half = m/2;
    int tc = 0;
    memset(dp, 0, sizeof(dp));
    F(j, 0, m){
        if(j){
            memcpy(dp[1][0][j], dp[0][0][j - 1], sizeof(dp[0][0][j - 1]));
            memcpy(dp[0][0][j], dp[0][0][j - 1], sizeof(dp[0][0][j]));
        }
        F(shift, 0, n){
            memcpy(dp[0][1][j], dp[0][0][j], sizeof(dp[0][0][j]));
            int tmp = a[0][j];
            F(i, 0, n - 1)
                a[i][j] = a[i + 1][j];
            a[n - 1][j] = tmp;
            F(who, 0, n){
                F(mask, 0, 1<<n){
                    if(mask&(1<<who))cont;
                    dp[0][1][j][mask|(1<<who)] = max(dp[0][1][j][mask|(1<<who)], dp[0][1][j][mask] + a[who][j]);
                }
            }
            F(mask, 0, 1<<n)
                dp[1][0][j][mask] = max(dp[1][0][j][mask], dp[0][1][j][mask]);
        }
        memcpy(dp[0][0][j], dp[1][0][j], sizeof(dp[0][0][j]));
    }
    cout << dp[0][0][m - 1][(1<<n)-1] << '\n';
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int T;
    in.readInteger(T);
    while(T--)
        solve();
    return 0;
}