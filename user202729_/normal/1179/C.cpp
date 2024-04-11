#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<climits>
#include<array>
#include<vector>

namespace io{ // https://codeforces.com/contest/1179/submission/55932144

using namespace std;
 
/** Fast input-output */
 
template <class T = int> inline T readInt();						
inline double readDouble();
inline int readUInt();					 
inline int readChar(); // first non-blank character
inline void readWord(char *s); 
inline bool readLine(char *s); // do not save '\n'
inline bool isEof();
inline int getChar(); 
inline int peekChar();
inline bool seekEof();
inline void skipBlanks();
 
template <class T> inline void writeInt(T x, char end = 0, int len = -1);
inline void writeChar(int x); 
inline void writeWord(const char *s);
inline void writeDouble(double x, int len = 0);
inline void flush();
 
static struct buffer_flusher_t {
	~buffer_flusher_t() {
		flush();
	}
} buffer_flusher;
 
/** Read */
 
static const int buf_size = 4096;
 
static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;
 
inline bool isEof() {
	if (buf_pos == buf_len) {
		buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
		if (buf_pos == buf_len)
			return 1;
	}
	return 0;
}
 
inline int getChar() { 
	return isEof() ? -1 : buf[buf_pos++];
}
 
inline int peekChar() { 
	return isEof() ? -1 : buf[buf_pos];
}
 
inline bool seekEof() { 
	int c;
	while ((c = peekChar()) != -1 && c <= 32)
		buf_pos++;
	return c == -1;
}
 
inline void skipBlanks() {
	while (!isEof() && buf[buf_pos] <= 32U)
		buf_pos++;
}
 
inline int readChar() {
	int c = getChar();
	while (c != -1 && c <= 32)
		c = getChar();
	return c;
}
 
inline int readUInt() {
	int c = readChar(), x = 0;
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return x;
}
 
template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	else if (c == '+')
		c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}
 
inline double readDouble() {
	int s = 1, c = readChar();
	double x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	if (c == '.') {
		c = getChar();
		double coef = 1;
		while ('0' <= c && c <= '9')
			x += (c - '0') * (coef *= 1e-1), c = getChar();
	}
	return s == 1 ? x : -x;
}
 
inline void readWord(char *s) { 
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}
 
inline bool readLine(char *s) { 
	int c = getChar();
	while (c != '\n' && c != -1)
		*s++ = c, c = getChar();
	*s = 0;
	return c != -1;
}
 
/** Write */
 
static int write_buf_pos = 0;
static char write_buf[buf_size];
 
inline void writeChar(int x) {
	if (write_buf_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
	write_buf[write_buf_pos++] = x;
}
 
inline void flush() {
	if (write_buf_pos) {
		fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
		fflush(stdout);
	}
}
 
template <class T> 
inline void writeInt(T x, char end, int output_len) {
	if (x < 0)
		writeChar('-'), x = -x;
 
	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n < output_len)
		s[n++] = '0';
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}
 
inline void writeWord(const char *s) {
	while (*s)
		writeChar(*s++);
}
 
inline void writeDouble(double x, int output_len) {
	if (x < 0)
		writeChar('-'), x = -x;
	int t = (int)x;
	writeInt(t), x -= t;
	writeChar('.');
	for (int i = output_len - 1; i > 0; i--) {
		x *= 10;
		t = std::min(9, (int)x);
		writeChar('0' + t), x -= t;
	}
	x *= 10;
	t = std::min(9, (int)(x + 0.5));
	writeChar('0' + t);
}
};

struct ST{
	struct node{
		int lazy,min;
		int getmin()const{
			// real min value after pushing lazy, assume ancestor lazy values = 0
			return lazy+min;
		}
	};
	std::vector<node> d;
	ST(int n):d(2*n){}

	void add(int l,int r,int delta){
		if(l==r)return;
		assert(l<r);

		l+=int(d.size()/2);
		r+=int(d.size()/2);
		std::array<int,2> stored_endpts{{l,r-1}};
		while(l<r){
			if(l&1) d[l++].lazy+=delta;
			if(r&1) d[--r].lazy+=delta;
			l>>=1;r>>=1;
		}
		for(int x:stored_endpts)
			for(int y=x>>1;y;y>>=1)
				d[y].min=std::min(d[y*2].getmin(),d[y*2+1].getmin());
	}

	void pushlazy(int node){
		if(d[node].lazy){
			d[node].min+=d[node].lazy;
			d[node*2].lazy+=d[node].lazy;
			d[node*2+1].lazy+=d[node].lazy;
			d[node].lazy=0;
		}
	}

	int prevlt(int x,int val){
		assert(x>=0 and x<int(d.size()/2));

		int l=int(d.size()/2),r=int(d.size()/2)+x+1;
		for(int y:{l,r-1})
			for(int sh=31^__builtin_clz(x);sh;--sh)
				pushlazy(y>>sh);

		x=-1;
		while(l<r){
			if(l&1){
				if(d[l].getmin()<val)x=l;
				++l;
			}
			if(r&1){
				--r;
				if(d[r].getmin()<val){ x=r;break; }
			}
			l>>=1;r>>=1;
		}
		if(x<0)return -1;

		while(x<int(d.size()/2)){
			pushlazy(x);
			x=x*2;
			if(d[x+1].getmin()<val) ++x;
			assert(d[x].getmin()<val);
		}

		return x-int(d.size()/2);
	}
};

int main(){
	int ndish=io::readUInt(),npupil=io::readUInt();
	int constexpr TSIZE=1000003;
	ST t(TSIZE);

	std::vector<int> dishv(ndish),pupilv(npupil);
	// internal access to the segment tree data array (not recommended)
	for(int& ai:dishv){
		ai=io::readUInt();
		++t.d[t.d.size()/2+ai].min;
	}
	for(int& bi:pupilv){
		bi=io::readUInt();
		--t.d[t.d.size()/2+bi].min;
	}
	for(auto x=t.d.size()/2;x<t.d.size()-1;++x)
		t.d[x+1].min+=t.d[x].min;
	for(auto x=t.d.size()/2;--x;)
		t.d[x].min=std::min(t.d[x*2].min,t.d[x*2+1].min);


	int nq=io::readUInt();
	while(nq--){
		char type=io::readChar();int i=io::readUInt();
		--i;

		if(type=='1'){
			auto& ai=dishv[i];
			auto old=ai;
			ai=io::readUInt();
			if(old<ai) t.add(old,ai,-1);
			else if(old>ai) t.add(ai,old,1);
		}else{
			assert(type=='2');
			auto& bi=pupilv[i];
			auto old=bi;
			bi=io::readUInt();
			if(old<bi) t.add(old,bi,1);
			else if(old>bi) t.add(bi,old,-1);
		}

		assert(t.prevlt(TSIZE-1,ndish-npupil+1)==TSIZE-1);
		int out=t.prevlt(TSIZE-1,ndish-npupil);
		assert(out<TSIZE-1);
		if(out<0){
			assert(out==-1);
			io::writeChar('-');
			io::writeChar('1');
			io::writeChar('\n');
		}else{
			io::writeInt(out+1);
			io::writeChar('\n');
		}
	}
}