#pragma GCC optimize ("O3")
// see note about O3 int previous submission.
// Remark: compiling with -m32 is slower, but reflect the real performance when run on Codeforces machine.

#include<array>
#include<algorithm>
#include<functional>
#include<cstdio>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
namespace io{using namespace std;static const int buf_size=4096;static unsigned char buf[buf_size];static int buf_len=0,buf_pos=0;inline bool isEof(){if(buf_pos==buf_len){buf_pos=0,buf_len=fread(buf,1,buf_size,stdin);if(buf_pos==buf_len)return 1;}return 0;}inline int getChar(){return isEof()?-1:buf[buf_pos++];}inline int peekChar(){return isEof()?-1:buf[buf_pos];}inline bool seekEof(){int c;while((c=peekChar())!=-1&&c<=32)buf_pos++;return c==-1;}inline void skipBlanks(){while(!isEof()&&buf[buf_pos]<=32U)buf_pos++;}inline int readChar(){int c=getChar();while(c!=-1&&c<=32)c=getChar();return c;}inline int readUInt(){int c=readChar(),x=0;while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return x;}template<class T=int>inline T readInt(){int s=1,c=readChar();T x=0;if(c=='-')s=-1,c=getChar();else if(c=='+')c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return s==1?x:-x;}inline double readDouble(){int s=1,c=readChar();double x=0;if(c=='-')s=-1,c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();if(c=='.'){c=getChar();double coef=1;while('0'<=c&&c<='9')x+=(c-'0')*(coef*=1e-1),c=getChar();}return s==1?x:-x;}inline void readWord(char*s){int c=readChar();while(c>32)*s++=c,c=getChar();*s=0;}inline bool readLine(char*s){int c=getChar();while(c!='\n'&&c!=-1)*s++=c,c=getChar();*s=0;return c!=-1;}static int write_buf_pos=0;static char write_buf[buf_size];inline void writeChar(int x){if(write_buf_pos==buf_size)fwrite(write_buf,1,buf_size,stdout),write_buf_pos=0;write_buf[write_buf_pos++]=x;}inline void flush(){if(write_buf_pos){fwrite(write_buf,1,write_buf_pos,stdout),write_buf_pos=0;fflush(stdout);}}template<class T>inline void writeInt(T x,char end=0,int output_len=-1){if(x<0)writeChar('-'),x=-x;char s[24];int n=0;while(x||!n)s[n++]='0'+x%10,x/=10;while(n<output_len)s[n++]='0';while(n--)writeChar(s[n]);if(end)writeChar(end);}inline void writeWord(const char*s){while(*s)writeChar(*s++);}inline void writeDouble(double x,int output_len=0){if(x<0)writeChar('-'),x=-x;int t=(int)x;writeInt(t),x-=t;writeChar('.');for(int i=output_len-1;i>0;i--){x*=10;t=std::min(9,(int)x);writeChar('0'+t),x-=t;}x*=10;t=std::min(9,(int)(x+0.5));writeChar('0'+t);}static struct buffer_flusher_t{~buffer_flusher_t(){flush();}}buffer_flusher;};
#pragma GCC diagnostic pop

uint64_t constexpr INV5=0xCCCCCCCCCCCCCCCDULL;
static_assert(INV5*5==1,"");

struct Num{ // element of the ring Z/2^64 Z [ii]
	std::array<uint64_t,4> d;
	// value: d[0] + d[1]*ii + d[2]*ii**2 + d[3]*ii**3 where ii is a 10th root of unity
	// such that ii**4 = ii**3 - ii**2 + ii - 1

	Num constexpr mulii()const{
		return {-d[3],d[0]+d[3],d[1]-d[3],d[2]+d[3]};
	}
	Num constexpr& operator+=(Num x){
		for(int i=0;i<4;++i) d[i]+=x.d[i];
		return *this;
	}
	Num constexpr& operator-=(Num x){
		for(int i=0;i<4;++i) d[i]-=x.d[i];
		return *this;
	}
	Num constexpr& operator*=(uint64_t x){
		for(int i=0;i<4;++i) d[i]*=x;
		return *this;
	}
	friend Num constexpr operator+(Num a,Num b){return a+=b;}
	friend Num constexpr operator-(Num a,Num b){return a-=b;}
	friend Num constexpr operator*(Num a,uint64_t b){return a*=b;}

	friend Num constexpr operator*(Num a,Num const b){
		Num out{};
		for(int i=0;;++i,a=a.mulii()){
			out+=a*b.d[i];
			if(i==3)return out;
		}
	}
	Num constexpr& operator*=(Num b){ return *this = *this * b; }

	friend Num constexpr pow(Num x,int e){
		Num out=x;--e;
		while(true){
			if(e&1) out*=x;
			if((e>>=1)==0) return out;
			x*=x;
		}
	}

	static Num const ii;
};
const Num Num::ii {0,1,0,0};

auto constexpr powii=[]{
	std::array<Num,10> powii{};
	powii[0]={1,0,0,0};
	for(int i=1;i<10;++i) powii[i]=powii[i-1].mulii();
	return powii;
}();

template<bool reverse=false,class Iter>
void constexpr slowft(Iter first,int step){ // 10 elements: first[0], first[step], ..., first[9*step]
	std::array<Num,10> out{};

#if SLOWER
	Num powii_i{1,0,0,0};
	for(int i=0;i<10;++i,powii_i=powii_i.mulii()){
		Num powii_ij{1,0,0,0};
		for(int j=0;j<10;++j,powii_ij*=powii_i)
		{
			auto tmp=first[step*i];
			//tmp*=powii[i*j%10]; // SLOWER! (why? powii is constexpr...)
			for(auto z=i*j%10;z--;) tmp=tmp.mulii();
			out[j]+=tmp;
		}
	}
#else
#	if SLOWER
	for(int i=0;i<10;++i){
	for(int startj=((i&1) ? 5 : 0),j=startj;j<startj+5;++j){
#	else
	for(int j=0;j<10;++j){
	for(int i=(j>=5);i<10;i+=2){
#	endif
		auto tmp=first[step*i];
		for(auto z=i*j%10;z--;) tmp=tmp.mulii();
		out[j]+=tmp;
	}
	}
	for(int i=0;i<5;++i){
		auto x=out[i],y=out[i+5];
		out[i]=x-y;
		out[i+5]=x+y;
	}
#endif

	if(reverse) // does not divide by 10!
		std::reverse(begin(out)+1,end(out));
	for(int i=0;i<10;++i)
		first[step*i]=out[i];
}

template<bool reverse=false>
void slowft(std::array<Num,100000>& a){
	for(int dim=0,pow10dim=1;dim<5;++dim,pow10dim*=10)
		for(int base_l=0;base_l<pow10dim;++base_l)
			for(int base_h=0;base_h<(int)a.size();base_h+=10*pow10dim)
				slowft<reverse>(begin(a)+base_l+base_h,pow10dim);
}

int main(){
	std::array<Num,100000> a{};
	int n=io::readUInt();
	for(int i=0;i<n;++i){
		++a[io::readUInt()].d[0];
	}

	slowft(a);
	for(auto& x:a)
		x=pow(x,n);
	slowft<true>(a);

	for(int i=0;i<n;++i){
		auto x=a[i].d[0];
		for(int z=5;z--;) x*=INV5;
		x>>=5;
		io::writeInt(x%(1ULL<<58));
		io::writeChar('\n');
	}
}