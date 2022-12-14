// Caching the results of the unchanged blocks.
// On my machine the previous hack test only take <4s to run.
//
// Also special-case some cases int get function so the time complexity is only O(1), not O(log n).
// I don't know if this is an optimization or deoptimization.
//
// ^ (more special case = more bug.)

#ifndef LOCAL
#define NDEBUG
#endif
#include<numeric>
#include<array>
#include<cassert>
#include<algorithm>
#include<climits>
#include<cstdio>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
namespace io{using namespace std;static const int buf_size=4096;static unsigned char buf[buf_size];static int buf_len=0,buf_pos=0;inline bool isEof(){if(buf_pos==buf_len){buf_pos=0,buf_len=fread(buf,1,buf_size,stdin);if(buf_pos==buf_len)return 1;}return 0;}inline int getChar(){return isEof()?-1:buf[buf_pos++];}inline int peekChar(){return isEof()?-1:buf[buf_pos];}inline bool seekEof(){int c;while((c=peekChar())!=-1&&c<=32)buf_pos++;return c==-1;}inline void skipBlanks(){while(!isEof()&&buf[buf_pos]<=32U)buf_pos++;}inline int readChar(){int c=getChar();while(c!=-1&&c<=32)c=getChar();return c;}inline int readUInt(){int c=readChar(),x=0;while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return x;}template<class T=int>inline T readInt(){int s=1,c=readChar();T x=0;if(c=='-')s=-1,c=getChar();else if(c=='+')c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return s==1?x:-x;}inline double readDouble(){int s=1,c=readChar();double x=0;if(c=='-')s=-1,c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();if(c=='.'){c=getChar();double coef=1;while('0'<=c&&c<='9')x+=(c-'0')*(coef*=1e-1),c=getChar();}return s==1?x:-x;}inline void readWord(char*s){int c=readChar();while(c>32)*s++=c,c=getChar();*s=0;}inline bool readLine(char*s){int c=getChar();while(c!='\n'&&c!=-1)*s++=c,c=getChar();*s=0;return c!=-1;}static int write_buf_pos=0;static char write_buf[buf_size];inline void writeChar(int x){if(write_buf_pos==buf_size)fwrite(write_buf,1,buf_size,stdout),write_buf_pos=0;write_buf[write_buf_pos++]=x;}inline void flush(){if(write_buf_pos){fwrite(write_buf,1,write_buf_pos,stdout),write_buf_pos=0;fflush(stdout);}}template<class T>inline void writeInt(T x,char end=0,int output_len=-1){if(x<0)writeChar('-'),x=-x;char s[24];int n=0;while(x||!n)s[n++]='0'+x%10,x/=10;while(n<output_len)s[n++]='0';while(n--)writeChar(s[n]);if(end)writeChar(end);}inline void writeWord(const char*s){while(*s)writeChar(*s++);}inline void writeDouble(double x,int output_len=0){if(x<0)writeChar('-'),x=-x;int t=(int)x;writeInt(t),x-=t;writeChar('.');for(int i=output_len-1;i>0;i--){x*=10;t=std::min(9,(int)x);writeChar('0'+t),x-=t;}x*=10;t=std::min(9,(int)(x+0.5));writeChar('0'+t);}static struct buffer_flusher_t{~buffer_flusher_t(){flush();}}buffer_flusher;};
#pragma GCC diagnostic pop

#include<vector>

int const BLOCKSIZE=1000;

struct block{
	struct interval{ // inclusive
		int l,r;
	};
	std::vector<interval> d;
	int min,max;

	template<class Iter>
	void recompute(Iter first,Iter last){
		assert(last-first<=BLOCKSIZE+1);
		assert(last-first>=2);

		std::array<int,BLOCKSIZE+1> minpre,maxsuf;
		d.reserve(last-first-1);
		d.clear();

		min=*first;
		for(int i=0;first+i!=last;++i)
			minpre[i]=min=std::min(min,first[i]);

		max=last[-1];
		for(auto i=last-first;i--;)
			maxsuf[i]=max=std::max(max,first[i]);

		for(auto i=last-first-1;i;--i){
			assert(minpre[i-1]!=maxsuf[i]);
			if(minpre[i-1]>maxsuf[i])
				d.push_back({maxsuf[i],minpre[i-1]});
		}

		assert(std::is_sorted(begin(d),end(d),[](interval x,interval y){
					return x.l<y.l;
					}));
	} // only O(n)

	int get(int minpre,int maxsuf)const{
		if(minpre<maxsuf or d.empty())return 0;
		assert(minpre>maxsuf);
		auto const cond1=[](interval x,int y){return x.l<=y;};
		auto max_iter=cond1(d.back(),minpre) ? end(d) : std::lower_bound(begin(d),end(d),minpre,cond1);

		auto const cond2=[](interval x,int y){return x.r<y;};
		auto min_iter=cond2(d[0],maxsuf) ? std::lower_bound(begin(d),max_iter,maxsuf,cond2) : begin(d);

		return max_iter-min_iter;
		// number of segments that intersect [maxsuf..minpre]
	}
};

int main(){
	int n=io::readUInt();
	int nquery=io::readUInt();
	std::vector<int> a(n);
	std::generate(begin(a),end(a),io::readUInt);

	std::vector<block> blocks;
	for(int i=0;n-i*BLOCKSIZE>=2;++i){
		blocks.emplace_back();
		blocks[i].recompute(begin(a)+i*BLOCKSIZE,
				begin(a)+std::min((int)a.size(),i*BLOCKSIZE+BLOCKSIZE+1));
	}
	// NOTE one update may modify at most 2 block


	std::vector<int> maxsuf(blocks.size()+1);

	std::vector<int> minpre(blocks.size()+1); // exclusive

	auto const recompute_minmax=[&](){
		maxsuf.back()=INT_MIN;
		for(auto blocki=blocks.size();blocki--;)
			maxsuf[blocki]=std::max(maxsuf[blocki+1],blocks[blocki].max);

		minpre[0]=INT_MAX;
		for(auto blocki=1;blocki<=blocks.size();++blocki)
			minpre[blocki]=std::min(minpre[blocki-1],blocks[blocki-1].min);
	};
	recompute_minmax();

	std::vector<int> getval(blocks.size());
	for(unsigned blocki=0;blocki<blocks.size();++blocki)
		getval[blocki]=blocks[blocki].get(minpre[blocki],maxsuf[blocki+1]);

	while(nquery--){
		int pos=io::readUInt()-1;
		int x=io::readUInt();

		assert(x!=a[pos]);
		a[pos]=x;

		auto mincblock=pos==0 ? 0 : (pos-1)/BLOCKSIZE;
		auto maxcblock=std::min(int(blocks.size()-1),pos/BLOCKSIZE);

		auto const old_minpre=minpre;
		auto const old_maxsuf=maxsuf;

		for(int blocki=mincblock;blocki<=maxcblock;++blocki)
			blocks[blocki].recompute(begin(a)+blocki*BLOCKSIZE,
					begin(a)+std::min((int)a.size(),blocki*BLOCKSIZE+BLOCKSIZE+1));

		recompute_minmax();

		for(int blocki=0;blocki<(int)blocks.size();++blocki)
			if(old_minpre[blocki]!=minpre[blocki] or old_maxsuf[blocki+1]!=maxsuf[blocki+1] or
					(mincblock<=blocki and blocki<=maxcblock))
				getval[blocki]=blocks[blocki].get(minpre[blocki],maxsuf[blocki+1]);

		io::writeInt(std::accumulate(begin(getval),end(getval),1));
		io::writeChar('\n');
	}
}