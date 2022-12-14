// Unproven time complexity. May get TLE.
// UPD: Typo...
// UPD: "Constant factor" optimization.
// UPD: Yet another "typo". This time I just generate a test case with gcd=10**12.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
namespace io{using namespace std;static const int buf_size=4096;static unsigned char buf[buf_size];static int buf_len=0,buf_pos=0;inline bool isEof(){if(buf_pos==buf_len){buf_pos=0,buf_len=fread(buf,1,buf_size,stdin);if(buf_pos==buf_len)return 1;}return 0;}inline int getChar(){return isEof()?-1:buf[buf_pos++];}inline int peekChar(){return isEof()?-1:buf[buf_pos];}inline bool seekEof(){int c;while((c=peekChar())!=-1&&c<=32)buf_pos++;return c==-1;}inline void skipBlanks(){while(!isEof()&&buf[buf_pos]<=32U)buf_pos++;}inline int readChar(){int c=getChar();while(c!=-1&&c<=32)c=getChar();return c;}
	template<class T=unsigned>inline T readUInt(){int c=readChar();T x=0;while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return x;}
	template<class T=int>inline T readInt(){int s=1,c=readChar();T x=0;if(c=='-')s=-1,c=getChar();else if(c=='+')c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return s==1?x:-x;}inline double readDouble(){int s=1,c=readChar();double x=0;if(c=='-')s=-1,c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();if(c=='.'){c=getChar();double coef=1;while('0'<=c&&c<='9')x+=(c-'0')*(coef*=1e-1),c=getChar();}return s==1?x:-x;}inline void readWord(char*s){int c=readChar();while(c>32)*s++=c,c=getChar();*s=0;}inline bool readLine(char*s){int c=getChar();while(c!='\n'&&c!=-1)*s++=c,c=getChar();*s=0;return c!=-1;}static int write_buf_pos=0;static char write_buf[buf_size];inline void writeChar(int x){if(write_buf_pos==buf_size)fwrite(write_buf,1,buf_size,stdout),write_buf_pos=0;write_buf[write_buf_pos++]=x;}inline void flush(){if(write_buf_pos){fwrite(write_buf,1,write_buf_pos,stdout),write_buf_pos=0;fflush(stdout);}}template<class T>inline void writeInt(T x,char end=0,int output_len=-1){if(x<0)writeChar('-'),x=-x;char s[24];int n=0;while(x||!n)s[n++]='0'+x%10,x/=10;while(n<output_len)s[n++]='0';while(n--)writeChar(s[n]);if(end)writeChar(end);}inline void writeWord(const char*s){while(*s)writeChar(*s++);}inline void writeDouble(double x,int output_len=0){if(x<0)writeChar('-'),x=-x;int t=(int)x;writeInt(t),x-=t;writeChar('.');for(int i=output_len-1;i>0;i--){x*=10;t=std::min(9,(int)x);writeChar('0'+t),x-=t;}x*=10;t=std::min(9,(int)(x+0.5));writeChar('0'+t);}static struct buffer_flusher_t{~buffer_flusher_t(){flush();}}buffer_flusher;};
#pragma GCC diagnostic pop

int main(){
	int n=io::readUInt();int64_t maxdiv=io::readUInt<int64_t>();
	struct judge{
		int64_t a;
		//uint16_t mask;
		int64_t e;
	};
	std::vector<judge> jj(n);
	int64_t gcda=0;
	for(auto& [a,e]:jj){
		a=io::readUInt<int64_t>();
		gcda=std::gcd(gcda,a);
	}
	if(gcda==1){
		io::writeWord("0\n");
		return 0;
	}

	struct factor_t{ int64_t prime; int exp; };
	std::vector<factor_t> factors;
	{
		auto x=gcda;
		if(not(x&1)){
			factors.push_back({2,__builtin_ctzll(x)});
			x>>=__builtin_ctzll(x);
		}
		for(int i=3;i*(int64_t)i<=x;i+=2)if(x%i==0){
			x/=i; factors.push_back({i,1});
			while(x%i==0){
				x/=i; ++factors.back().exp;
			}
		}
		if(x>1) factors.push_back({x,1});
	}

	for(auto& [a,e]:jj){
		e=io::readUInt<int64_t>();

		assert(a%gcda==0);
		{
			int64_t a1=1;
			for(auto [p,e]:factors){
				int64_t power_of_p_in_a=1;
				assert(a%p==0);
				do{
					a/=p;
					power_of_p_in_a*=p;
					if(power_of_p_in_a>maxdiv) break;
				}while(a%p==0);
				a1*=power_of_p_in_a;
			}
			a=a1;
		} // only keep prime factors of gcda & normalize too large prime powers. Doesn't change the result.
		if(a<=maxdiv) a=gcda;
	}
	std::sort(begin(jj),end(jj),[](auto p,auto q){return p.a!=q.a ? p.a<q.a : p.e<q.e;});
	// for each a take factors.size() smallest e values
	{
		auto out=begin(jj);
		int64_t cura=-1; unsigned cura_cnt=0;
		for(auto [a,e]:jj){
			if(a!=cura){
				cura=a;
				cura_cnt=0;
			}
			if(cura_cnt>=factors.size()) continue;
			*out++={a,e};
			++cura_cnt;
		}
		jj.erase(out,end(jj));
	}

	// is jj.size() small enough now?...

	assert(factors.size()<12);
	// [mask][njudge] = min sum e value
	std::vector<std::array<int64_t,12>> dp(1<<factors.size());
	for(auto& a:dp) for(auto& b:a) b=INT64_MAX;
	dp[0][0]=0;

	std::vector<int64_t> val(1<<factors.size());

	for(auto& [a,e]:jj){
		std::array<int64_t,12> facta;
		{
			auto x=a;
			for(unsigned i=0;i<factors.size();++i) {
				facta[i]=1;
				auto const p=factors[i].prime;
				while(x%p==0){ facta[i]*=p; x/=p; }
				assert(facta[i]!=1);
			}
		}

		val[0]=1;
		for(int mask=1;mask<(1<<factors.size());++mask)
			val[mask]=val[mask-(mask&-mask)]*facta[__builtin_ctz(mask)];


		for(auto njudge=factors.size();njudge--;){
			for(int mask1=1<<factors.size();--mask1;)
			if(val[mask1]<=maxdiv){
				int invmask1=((1<<factors.size())-1)^mask1;
				for(int mask=invmask1;;){
					assert((mask&mask1)==0);
					if(dp[mask][njudge]!=INT64_MAX)
						dp[mask|mask1][njudge+1]=std::min(dp[mask|mask1][njudge+1],
								dp[mask][njudge]+e);

					if(mask==0) break;
					mask=(mask-1)&invmask1;
				}
			}
		}
	}

	int64_t out=INT64_MAX;
	for(unsigned njudge=1;njudge<=factors.size();++njudge)
		if(dp.back()[njudge]!=INT64_MAX)
			out=std::min(out,dp.back()[njudge]*njudge);
	io::writeInt(out==INT64_MAX ? -1 : out); io::writeChar('\n');
}