// :!
// Misread the problem statement.
// Fortunately most of the existing code can be reused.
// 
// UPD: Finally got accepted.
// {I was surprised that the time limit is so large (7s), then even more surprised that
// my solution takes so long to run, but it's still the almost-fastest solution.}
// Let's generate some large test and benchmark, as usual.
//
// Initial run time: ~880ms.
// With fast IO: 830ms.
// Adaptive binary search: 700ms.
// {accidentally delete the slow test case}
//
// {recalculated the time complexity and realize that it's O(n log^3 n). That's why it's slow.
// It can be improved to O(n log^2 n).}

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
namespace io{using namespace std;static const int buf_size=4096;static unsigned char buf[buf_size];static int buf_len=0,buf_pos=0;inline bool isEof(){if(buf_pos==buf_len){buf_pos=0,buf_len=fread(buf,1,buf_size,stdin);if(buf_pos==buf_len)return 1;}return 0;}inline int getChar(){return isEof()?-1:buf[buf_pos++];}inline int peekChar(){return isEof()?-1:buf[buf_pos];}inline bool seekEof(){int c;while((c=peekChar())!=-1&&c<=32)buf_pos++;return c==-1;}inline void skipBlanks(){while(!isEof()&&buf[buf_pos]<=32U)buf_pos++;}inline int readChar(){int c=getChar();while(c!=-1&&c<=32)c=getChar();return c;}inline int readUInt(){int c=readChar(),x=0;while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return x;}template<class T=int>inline T readInt(){int s=1,c=readChar();T x=0;if(c=='-')s=-1,c=getChar();else if(c=='+')c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return s==1?x:-x;}inline double readDouble(){int s=1,c=readChar();double x=0;if(c=='-')s=-1,c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();if(c=='.'){c=getChar();double coef=1;while('0'<=c&&c<='9')x+=(c-'0')*(coef*=1e-1),c=getChar();}return s==1?x:-x;}inline void readWord(char*s){int c=readChar();while(c>32)*s++=c,c=getChar();*s=0;}inline bool readLine(char*s){int c=getChar();while(c!='\n'&&c!=-1)*s++=c,c=getChar();*s=0;return c!=-1;}static int write_buf_pos=0;static char write_buf[buf_size];inline void writeChar(int x){if(write_buf_pos==buf_size)fwrite(write_buf,1,buf_size,stdout),write_buf_pos=0;write_buf[write_buf_pos++]=x;}inline void flush(){if(write_buf_pos){fwrite(write_buf,1,write_buf_pos,stdout),write_buf_pos=0;fflush(stdout);}}template<class T>inline void writeInt(T x,char end=0,int output_len=-1){if(x<0)writeChar('-'),x=-x;char s[24];int n=0;while(x||!n)s[n++]='0'+x%10,x/=10;while(n<output_len)s[n++]='0';while(n--)writeChar(s[n]);if(end)writeChar(end);}inline void writeWord(const char*s){while(*s)writeChar(*s++);}inline void writeDouble(double x,int output_len=0){if(x<0)writeChar('-'),x=-x;int t=(int)x;writeInt(t),x-=t;writeChar('.');for(int i=output_len-1;i>0;i--){x*=10;t=std::min(9,(int)x);writeChar('0'+t),x-=t;}x*=10;t=std::min(9,(int)(x+0.5));writeChar('0'+t);}static struct buffer_flusher_t{~buffer_flusher_t(){flush();}}buffer_flusher;};
#pragma GCC diagnostic pop

template int const& std::min<int>(int const&,int const&);

template<class T=int,auto f=(T const&(*)(T const&,T const&))std::min<T>>
struct RMQ{
	std::vector<std::vector<T>> d;
	RMQ():d(){}
	RMQ(std::vector<T> x):d(){
		assign(std::move(x));
	}
	void assign(std::vector<T> x){
		d.assign(1,std::move(x));
		for(int step=1;step<(int)d.back().size();step<<=1){
			std::vector<T> const& a=d.back();
			std::vector<T> b(begin(a),end(a)-step);
			std::transform(begin(b),end(b),begin(a)+step,begin(b),f);
			d.push_back(std::move(b));
		}
	}
	T operator[](int i)const{ return d[0][i]; }
	T get(int l,int r)const{
		assert(l<r);
		int layer=std::__lg(r-l);
		return f(d[layer][l],d[layer][r-(1<<layer)]);
	}
	template<class U> T get(U lr)const{
		auto [l,r]=lr;
		return get(l,r);
	}
	T getrange(int l,int r)const{
		return get(std::minmax(l,r));
	}

};

struct suffixarray_t{
	std::vector<int> rankof;
	std::vector<int> order;// list of start indices sorted by order
};
suffixarray_t suffixarray(std::string const& s){
	suffixarray_t out{std::vector<int>(s.size()+1),std::vector<int>(s.size()+1)};
	auto& [rankof,order]=out;

	std::copy(begin(s),end(s),begin(rankof));

	std::vector<int> cnt; // temporary array for counting sort
	std::vector<std::vector<int>::iterator> it;

	std::vector<int> newrank,oldorder;

	unsigned prefix_len=1,nrank=128;
	while(true){
		// sort order by second half
		cnt.assign(nrank,0);
		for(unsigned x=0;x<order.size();++x)
			++cnt[x+prefix_len>=rankof.size() ? 0 : rankof[x+prefix_len]]; // TODO inefficient branch/cmov

		it.resize(nrank);
		it[0]=begin(order);
		for(unsigned i=1;i<nrank;++i)
			it[i]=it[i-1]+cnt[i-1];

		for(unsigned x=0;x<rankof.size();++x)
			*it[x+prefix_len>=rankof.size() ? 0 : rankof[x+prefix_len]]++=x;

		// stable sort order by first half
		cnt.assign(nrank,0);
		for(int x:rankof)++cnt[x];

		std::swap(order,oldorder);
		order.resize(oldorder.size());

		it.resize(nrank);
		it[0]=begin(order);
		for(unsigned i=1;i<nrank;++i)
			it[i]=it[i-1]+cnt[i-1];

		for(auto x:oldorder)
			*it[rankof[x]]++=x;

		// recalculate rank
		newrank.resize(rankof.size());
		nrank=1;
		newrank[order[0]]=0;
		for(unsigned i=1;i<order.size();++i){
			auto a=order[i-1],b=order[i];
			if(rankof[a]!=rankof[b] or rankof[a+prefix_len]!=rankof[b+prefix_len])
				++nrank;
			newrank[b]=nrank-1;
		}

		prefix_len*=2;
		std::swap(rankof,newrank);
		if(nrank==rankof.size())
			break;
	}

	return out;
}

std::vector<int> lcp(std::string const& s,std::vector<int> const& rankof,std::vector<int> const& order){
	assert(rankof.size()==s.size()+1);
	assert(rankof.size()==order.size());
	std::vector<int> out(s.size());
	int minlcp=0;
	for(unsigned i=0;i<s.size();++i){
		unsigned r=rankof[i];
		assert(order[r]==(int)i);
		if(r+1==order.size()){
			assert(minlcp==0);
			continue;
		}
		unsigned j=order[r+1];

		while(s[i+minlcp]==s[j+minlcp]) ++minlcp;

		out[r]=minlcp;
		if(minlcp) --minlcp;
	}
	return out;
}



struct ST{
	using node=std::vector<int>;

	std::vector<node> d;

	ST(){}
	void reset(std::vector<int> const& data){
		auto const n=(int)data.size();
		d.resize(n*2);
		for(int i=n;i--;)d[i+n].assign(1, data[i]);
		for(int i=n;--i;){
			d[i].resize(d[i*2].size()+d[i*2+1].size());
			auto iter=std::merge(begin(d[i*2]),end(d[i*2]),
					begin(d[i*2+1]),end(d[i*2+1]),
					begin(d[i]));
			assert(iter==end(d[i]));
		}
	}

	private:
	static bool evaluates_to_true(auto const& fn){ // fn is evaluated in any case
		if constexpr(std::is_same_v<decltype(fn()),void>){
			fn(); return false;
		}else{
			return fn();
		}
	}
#define IS_TRUE(expr...) evaluates_to_true([&]{ return (expr); })

	public:
	static void foreach_strict_ancestors_down(int x,auto const& fn){ // fn returns true to break loop
		for(int shift=31^__builtin_clz(x);shift;--shift)
			if(IS_TRUE(fn(x>>shift))) break;
	}

	static void foreach_strict_ancestors_up(int x,auto const& fn){
		for(int y=x>>1;y;y>>=1)
			if(IS_TRUE(fn(y))) break;
	}

	static void foreach_range(int l,int r,auto const& leftfn,auto const& rightfn){
		// leftfn is called from left to right on left nodes
		// rightfn is called from right to left on right nodes
		while(l<r){
			if(l&1) if(IS_TRUE(leftfn(l++))) break;
			if(r&1) if(IS_TRUE(rightfn(--r))) break;
			l>>=1;r>>=1;
		}
	}

	int offset()const{ return int(d.size()/2u); }

	void foreach_range(int l,int r,auto const& fn){
		foreach_range(l,r,fn,fn);
	}

	template<bool larger>
	int get(int l,int r, int value){
		int out=larger? INT_MAX : -1;
		foreach_range(offset()+l,offset()+r,[&](int node){
			auto iter=std::lower_bound(begin(d[node]),end(d[node]), value);
			if(larger){
				if(iter!=end(d[node])) out=std::min(out,*iter);
			}else{
				if(iter!=begin(d[node])) out=std::max(out, iter[-1]);
			}
		});
		if(larger) assert(out>=value);
		else assert(out<value);
		return out;
	}
};

std::vector<int> z(auto first, auto last){
	std::vector<int> out(last-first);
	out[0]=int(last-first);
	int left=1, right=1;
	for(int index=1;index<(int)out.size();++index) {
		out[index]=std::max(0,std::min(int(right-index),out[index-left]));
		if(out[index]+index>=right){
			left=index; right=index+out[index];
			while(right<(int)out.size() and first[right]==first[right-left])++right;
			out[index]=right-index;
		}
	}
	return out;
}

auto z(auto const & string){
	return z(begin(string), end(string));
}

std::vector<std::vector<int>> leftTandem, rightTandem,
	// minimum length of tandem repeats (half) that has left/right at (index)
	midTandem; // [left] = minimum value of(right) of tandem repeats that does not start at (left)
	// update similar to sparse table

	// NOTE midTandem could be han=ed more efficiently
std::string string;

void process(int const left, int const right){ // find all tandem repeat
	if(right-left==1) return;
	assert(right-left>1);
	auto const mid=(left+right)>>1;

	process(left, mid);
	process(mid, right);

	std::string temp;temp.reserve(right-left+1);
	temp.assign(begin(string)+mid, begin(string)+right);
	temp+=char(-1);
	assert(std::find(begin(string), end(string), -1)==end(string));
	temp.insert(end(temp), begin(string)+left, begin(string)+mid);

	auto const update=[&](auto & array, int left, int numValue, int updateValue){
		int const layer=31^__builtin_clz(numValue);
		array[layer][left]=std::min(array[layer][left], updateValue);
		array[layer][left+numValue-(1<<layer)]=std::min(array[layer][left+numValue-(1<<layer)], updateValue);
	};

	auto const process=[&](int leftmost, int numValue, int len /* half */){
		// fount a sequence of tandem repeats
		update(leftTandem, leftmost, numValue, len);
		update(rightTandem, leftmost+2*len, numValue, len);
		if(leftmost) update(midTandem, 0, leftmost, leftmost+2*len);
	};

	auto one=z(temp);
	auto two=z(string.rend()-mid, string.rend()-left);
	for(int len=1;len<(int)two.size();++len) {
		auto a=std::min(len,two[len]), b=end(one)[-len]; // maximum possible value
		assert(b<=len);
		if(a+b>=len){
			auto numValue=a+b-len+1;
			process(mid-a-len, numValue, len);
		}
	}

	one=z(temp.rbegin(), temp.rend());
	two=z(begin(string)+mid, begin(string)+right);
	for(int len=1;len<(int)two.size();++len) {
		auto a=std::min(len,two[len]), b=end(one)[-len];
		assert(b<=len);
		if(a+b>=len){
			auto numValue=a+b-len+1;
			process(mid-b, numValue, len);
		}
	}
}

int main(){
	int len=io::readUInt();

	std::vector<std::vector<int>> primeFactors(len+1);
	for(int i=2;i<=len;++i) if(primeFactors[i].empty())
		for(int j=i;j<=len;j+=i) primeFactors[j].push_back(i);

	string.resize(len+1);
	io::readWord(string.data());
	string.resize(len);
	auto [rank, order]=suffixarray(string);
	auto lcpString=lcp(string, rank, order);
	RMQ<> rmq(lcpString);

	for(auto &c: string) c=char(c-'a');

	int numQuery=io::readUInt();

	std::array<std::vector<int>, 26> suffixSum;
	for(int c=0;c<26;++c) {
		suffixSum[c].resize(len+1);
		int cur=0;
		for(auto index=len; index--;) suffixSum[c][index]=cur+=(string[index]==c);
	}

	auto const rangeByPrefix=[&](auto item, auto left, auto right, auto len){
		// assumes that resultLeft<=left and resultRight>=right.
		// (currently not used)
		auto const process=[&](auto tryExtend){
			unsigned layer=0;
			while(layer<rmq.d.size()){
				if(tryExtend(layer)) ++layer;
				else break;
			}
			for(; layer--;)
				tryExtend(layer);
		};

		process([&](auto layer){
			bool okay=false;
			if(right-1<(int)rmq.d[layer].size() and rmq.d[layer][right-1]>=len){
				okay=true;
				right+=1<<layer;
			}
			if(left>=(1<<layer) and rmq.d[layer][left-(1<<layer)]>=len){
				okay=true;
				left-=1<<layer;
			}
			return okay;
		});
		/* // Try expand left and right separately. For some reason this is slightly slower.
		process([&](auto layer){
			if(right-1<(int)rmq.d[layer].size() and rmq.d[layer][right-1]>=len){
				right+=1<<layer;
				return true;
			}
			return false;
		});
		process([&](auto layer){
			if(left>=(1<<layer) and rmq.d[layer][left-(1<<layer)]>=len){
				left-=1<<layer;
				return true;
			}
			return false;
		});
		*/
		return std::make_pair(left, right);
	};

	/*
	auto const rangeByPrefixShrink=[&](auto item, auto left, auto right, auto len){
		// assumes that resultLeft>=left and resultRight<=right.
		unsigned layer=0;
		auto const tryShrink=[&](auto layer){
			bool okay=false;
			if(right-1<(int)rmq.d[layer].size() and rmq.d[layer][right-1]>=len){
				okay=true;
				right+=1<<layer;
			}
			if(left>=(1<<layer) and rmq.d[layer][left-(1<<layer)]>=len){
				okay=true;
				left-=1<<layer;
			}
			return okay;
		};
		while(layer<rmq.d.size()){
			if(tryShrink(layer)) ++layer;
			else break;
		}
		for(; layer--;)
			tryShrink(layer);
		return std::make_pair(left, right);
	};
	*/

	for(auto dataPointer:{&leftTandem, &rightTandem, &midTandem}){
		auto& data=*dataPointer;
		data.emplace_back(len+1, INT_MAX);
		for(int step=1;step<(int)data.back().size();step<<=1)
			data.emplace_back(data.back().size()-step, INT_MAX);
	}
	process(0, len);
	for(auto dataPointer:{&leftTandem, &rightTandem, &midTandem}){
		auto& data=*dataPointer;
		for(auto layer=data.size();--layer;){
			for(int i=0;i<(int)data[layer].size();++i) {
				auto cur=data[layer][i];
				data[layer-1][i]=std::min(data[layer-1][i], cur);
				data[layer-1][i+(1<<(layer-1))]=std::min(data[layer-1][i+(1<<(layer-1))], cur);
			}
		}
	}

	std::vector<int> nextEqual(len), prevEqual(len)
		//, nextDup(len)
		;
	{
		std::array<int, 26> previous;
		std::fill(begin(previous),end(previous), -1);
		for(int i=0;i<len;++i) {
			prevEqual[i]=previous[string[i]];
			previous[string[i]]=i;
		}

		std::array<int, 26> nextOf;
		std::fill(begin(nextOf),end(nextOf), len);
		for(int index=len
				//, nextDupAfterIndex=len
				; index--;){
			//if(index+1<len and string[index]==string[index+1])
			//	nextDupAfterIndex=index;
			//nextDup[index]=nextDupAfterIndex;
			nextEqual[index]=nextOf[string[index]];
			nextOf[string[index]]=index;
		}
	}

	ST segmentTree; segmentTree.reset(order);

	while(numQuery--){
		int left=io::readUInt(); int right=io::readUInt();
		--left;
		if([&]{
			for(int c=0;c<26;++c)
				if(suffixSum[c][left]-suffixSum[c][right]>=2)
					return false;
			return true;
		}()){
			io::writeWord("-1\n");
continue_outer:
			continue;
		}

		if(std::any_of(begin(primeFactors[right-left]),end(primeFactors[right-left]),[&](int prime){
			return rmq.getrange(rank[left],rank[left+(right-left)/prime])>=right-left-(right-left)/prime;
		})){
			io::writeWord("1\n");
			continue;
		}

		if(std::min(leftTandem[0][left], rightTandem[0][right])<=((right-left)>>1)){
			io::writeWord("2\n");
			continue;
		}

		int len=1;
		int lastPosLeft=rank[left], lastPosRight=rank[left]+1;
		while(true){
			// Find the shortest prefix of string[left...right] equal to some suffix.
			// Only works efficiently if there's no tandem repeat start at left or end at right.
			auto [posLeft, posRight]=rangeByPrefix(rank[left], rank[left], rank[left]+1, len); // accounts for 1/5 of the run time (int a random large test case I generated.)
			lastPosLeft=posLeft; lastPosRight=posRight;

			auto index=segmentTree.get<false>(posLeft, posRight, right-len+1); // accounts for 1/3 of the run time
			assert(index<=right-len);
			assert(index>=left);
			if(index==left){
				break;
			}else if(index==right-len){ // prefix and suffix with length (len) are equal
				io::writeWord("2\n");
				goto continue_outer;
			}
			assert(len<right-index);
			len=right-index;
		}

		if(prevEqual[right-1]>=left or nextEqual[left]<right or midTandem[0][left]<=right){
			io::writeWord("3\n");
		}else{
			io::writeWord("4\n");
		}
	}
}