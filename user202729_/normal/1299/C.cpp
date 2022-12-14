// /me should not try to solve D before C
// (classic mistake :()
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
namespace io{using namespace std;static const int buf_size=4096;static unsigned char buf[buf_size];static int buf_len=0,buf_pos=0;inline bool isEof(){if(buf_pos==buf_len){buf_pos=0,buf_len=fread(buf,1,buf_size,stdin);if(buf_pos==buf_len)return 1;}return 0;}inline int getChar(){return isEof()?-1:buf[buf_pos++];}inline int peekChar(){return isEof()?-1:buf[buf_pos];}inline bool seekEof(){int c;while((c=peekChar())!=-1&&c<=32)buf_pos++;return c==-1;}inline void skipBlanks(){while(!isEof()&&buf[buf_pos]<=32U)buf_pos++;}inline int readChar(){int c=getChar();while(c!=-1&&c<=32)c=getChar();return c;}inline int readUInt(){int c=readChar(),x=0;while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return x;}template<class T=int>inline T readInt(){int s=1,c=readChar();T x=0;if(c=='-')s=-1,c=getChar();else if(c=='+')c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return s==1?x:-x;}inline double readDouble(){int s=1,c=readChar();double x=0;if(c=='-')s=-1,c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();if(c=='.'){c=getChar();double coef=1;while('0'<=c&&c<='9')x+=(c-'0')*(coef*=1e-1),c=getChar();}return s==1?x:-x;}inline void readWord(char*s){int c=readChar();while(c>32)*s++=c,c=getChar();*s=0;}inline bool readLine(char*s){int c=getChar();while(c!='\n'&&c!=-1)*s++=c,c=getChar();*s=0;return c!=-1;}static int write_buf_pos=0;static char write_buf[buf_size];inline void writeChar(int x){if(write_buf_pos==buf_size)fwrite(write_buf,1,buf_size,stdout),write_buf_pos=0;write_buf[write_buf_pos++]=x;}inline void flush(){if(write_buf_pos){fwrite(write_buf,1,write_buf_pos,stdout),write_buf_pos=0;fflush(stdout);}}template<class T>inline void writeInt(T x,char end=0,int output_len=-1){if(x<0)writeChar('-'),x=-x;char s[24];int n=0;while(x||!n)s[n++]='0'+x%10,x/=10;while(n<output_len)s[n++]='0';while(n--)writeChar(s[n]);if(end)writeChar(end);}inline void writeWord(const char*s){while(*s)writeChar(*s++);}inline void writeDouble(double x,int output_len=0){if(x<0)writeChar('-'),x=-x;int t=(int)x;writeInt(t),x-=t;writeChar('.');for(int i=output_len-1;i>0;i--){x*=10;t=std::min(9,(int)x);writeChar('0'+t),x-=t;}x*=10;t=std::min(9,(int)(x+0.5));writeChar('0'+t);}static struct buffer_flusher_t{~buffer_flusher_t(){flush();}}buffer_flusher;};
#pragma GCC diagnostic pop

template<class T,class U>
struct point{
	T x,y;
	point constexpr operator+(point p)const{return {x+p.x,y+p.y};}
	point constexpr operator-(point p)const{return {x-p.x,y-p.y};}
	point constexpr operator*(T f)const{return {x*f,y*f};}

	point constexpr& operator+=(point p){return *this=*this+p;}
	point constexpr& operator-=(point p){return *this=*this-p;}
	point constexpr& operator*=(T f    ){return *this=*this*f;}

	template<class T1,class U1>
	constexpr operator point<T1,U1>() const {return {(T1)x,(T1)y};}

#define COMPAREOP(OP) bool constexpr operator OP(point p) const {return std::tie(x,y) OP std::tie(p.x,p.y);}
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	U constexpr cross(point p)const{return x*(U)p.y-y*(U)p.x;}
	U constexpr dot  (point p)const{return x*(U)p.x+y*(U)p.y;}
	U constexpr sqrlen()const{return dot(*this);}

	friend U cross(point a,point b,point c){
		return (b-a).cross(c-a);
	} // >0: ccw

	friend std::istream& operator>>(std::istream& str,point& p){
		return str>>p.x>>p.y;
	}
};

using pt=point<int64_t,int64_t>;

int main(){
	unsigned n=io::readUInt();
	std::vector<pt> pts{{0,0}};
	int64_t cursum=0;
	for(int i=1;i<=n;++i){
		cursum+=io::readUInt();
		pt cur{i,cursum};
		while(pts.size()>=2 and (cur-pts.back()).cross(cur-pts.end()[-2])>=0)
			pts.pop_back();
		pts.push_back(cur);
	}

	std::stringstream ss;
	ss<<std::setprecision(9)<<std::fixed;

	for(unsigned i=1;i<pts.size();++i){
		auto delta=pts[i]-pts[i-1];
		ss.clear();ss.str("");
		ss<<delta.y/(double)delta.x<<'\n';
		auto str=ss.str();

		for(unsigned z=(unsigned)delta.x;z--;)
			io::writeWord(str.c_str());
	}
}