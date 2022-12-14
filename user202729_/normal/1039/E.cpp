/*
{}

Link cut tree is required. The alternative is not good enough
(although it (appears to be) good with random test cases)

Not proven that in this particular problem the other data structure has slower worst case complexity.

With link cut tree, the worst case complexity is at most (proven) n n log n. It could be better.
*/
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
namespace io{using namespace std;static const int buf_size=4096;static unsigned char buf[buf_size];static int buf_len=0,buf_pos=0;inline bool isEof(){if(buf_pos==buf_len){buf_pos=0,buf_len=fread(buf,1,buf_size,stdin);if(buf_pos==buf_len)return 1;}return 0;}inline int getChar(){return isEof()?-1:buf[buf_pos++];}inline int peekChar(){return isEof()?-1:buf[buf_pos];}inline bool seekEof(){int c;while((c=peekChar())!=-1&&c<=32)buf_pos++;return c==-1;}inline void skipBlanks(){while(!isEof()&&buf[buf_pos]<=32U)buf_pos++;}inline int readChar(){int c=getChar();while(c!=-1&&c<=32)c=getChar();return c;}inline int readUInt(){int c=readChar(),x=0;while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return x;}template<class T=int>inline T readInt(){int s=1,c=readChar();T x=0;if(c=='-')s=-1,c=getChar();else if(c=='+')c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return s==1?x:-x;}inline double readDouble(){int s=1,c=readChar();double x=0;if(c=='-')s=-1,c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();if(c=='.'){c=getChar();double coef=1;while('0'<=c&&c<='9')x+=(c-'0')*(coef*=1e-1),c=getChar();}return s==1?x:-x;}inline void readWord(char*s){int c=readChar();while(c>32)*s++=c,c=getChar();*s=0;}inline bool readLine(char*s){int c=getChar();while(c!='\n'&&c!=-1)*s++=c,c=getChar();*s=0;return c!=-1;}static int write_buf_pos=0;static char write_buf[buf_size];inline void writeChar(int x){if(write_buf_pos==buf_size)fwrite(write_buf,1,buf_size,stdout),write_buf_pos=0;write_buf[write_buf_pos++]=x;}inline void flush(){if(write_buf_pos){fwrite(write_buf,1,write_buf_pos,stdout),write_buf_pos=0;fflush(stdout);}}template<class T>inline void writeInt(T x,char end=0,int output_len=-1){if(x<0)writeChar('-'),x=-x;char s[24];int n=0;while(x||!n)s[n++]='0'+x%10,x/=10;while(n<output_len)s[n++]='0';while(n--)writeChar(s[n]);if(end)writeChar(end);}inline void writeWord(const char*s){while(*s)writeChar(*s++);}inline void writeDouble(double x,int output_len=0){if(x<0)writeChar('-'),x=-x;int t=(int)x;writeInt(t),x-=t;writeChar('.');for(int i=output_len-1;i>0;i--){x*=10;t=std::min(9,(int)x);writeChar('0'+t),x-=t;}x*=10;t=std::min(9,(int)(x+0.5));writeChar('0'+t);}static struct buffer_flusher_t{~buffer_flusher_t(){flush();}}buffer_flusher;};
#pragma GCC diagnostic pop


template<class T,auto f>
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

template int const& std::min<int>(int const&,int const&);
RMQ<int, (int const&(*)(int const&,int const&))std::min<int>> rmqmin;

template int const& std::max<int>(int const&,int const&);
RMQ<int, (int const&(*)(int const&,int const&))std::max<int>> rmqmax;

std::vector<int> x;




struct LinkCutTree{
	/*
	std::vector<int> par; // splay tree parent if not splay tree root, otherwise
	// tree parent, or-1 if not exist
	std::vector<int> subtreeSize; // for splay tree
	std::vector<std::array<int,2>> child; // for splay tree. -1 if not exist
	*/

	struct data{
		int par;
		std::array<int,2> child;
		int subtreeSize;
		int nextGap; // of the edge(node->par)
		int minNextGap; // of all nodes int the splay subtree
	};
	std::vector<data> nodes;

	auto& par(auto x){ return nodes[x].par; }
	std::array<int,2>& child(auto x){ return nodes[x].child; }
	auto& subtreeSize(auto x){ return nodes[x].subtreeSize; }
	auto& nextGap(auto x){ return nodes[x].nextGap; }
	auto& minNextGap(auto x){ return nodes[x].minNextGap; }

#define DEF_CONST(method) \
	auto method(auto x)const{ return const_cast<LinkCutTree*>(this)->method(x); }
	DEF_CONST(par)
	DEF_CONST(child)
	DEF_CONST(subtreeSize)
	DEF_CONST(nextGap)
	DEF_CONST(minNextGap)
#undef DEF_CONST

	//auto par(auto x)const{ return nodes[x].par; }
	//std::array<int,2> child(auto x)const{ return nodes[x].child; }
	//auto subtreeSize(auto x)const{ return nodes[x].subtreeSize; }

	auto numNode()const{ return (int)nodes.size(); }

	LinkCutTree(int n):
		//par (n,-1), child (n,{-1,-1}), subtreeSize(n, 1)
		nodes(n,{
			-1, // par
			{-1,-1}, // child
			1, // subtreeSize
			-1, // nextGap
			-1 // minNextGap
		})
		{
		checkConsistency();
	}
	void link(int node,int newpar){
		checkConsistency();
		assert(par(node)<0);
		par(node)=newpar;
		checkConsistency();
	}
	bool cut(int node) {
		checkConsistency();
		makeSplayRoot(node);
		auto leftChild=child(node)[0];
		if(leftChild<0){
			if(par(node)<0) return false;
			par(node)=-1;
		} else {
			 par(leftChild)=par(node);
			 child(node)[0]=par(node)=-1;
			 recalculate(node);
		}
		checkConsistency();
		return true;
	}
	bool isSplayRoot(int node) const {
		auto Pa=par(node);
		return Pa<0 or (child(Pa)[0]!=node and child(Pa)[1]!=node);
	}
	int childIndex(int node) const {
		assert(not isSplayRoot(node));
		return child(par(node))[1]==node;
	}

	void recalculate(int node){
		subtreeSize(node)=1+
				(child(node)[0]>=0 ? subtreeSize(child(node)[0]): 0)+
				(child(node)[1]>=0 ? subtreeSize(child(node)[1]): 0)
			  ;
		minNextGap(node)=std::min({
			nextGap(node),
				child(node)[0]>=0 ? minNextGap(child(node)[0]): INT_MAX,
				child(node)[1]>=0 ? minNextGap(child(node)[1]): INT_MAX
		});
	}

	template<bool indexMustBe0=false>
	void rotate(int node) {
		checkConsistency();
		assert(not isSplayRoot(node));
		auto index=indexMustBe0 ? 0 : childIndex(node);
		assert(index==childIndex(node));
		auto Pa=par(node);
		auto grandPar=par(Pa);
		auto oldParIsSplayRoot=isSplayRoot(Pa);
		int oldParIndex;
		if(not oldParIsSplayRoot) oldParIndex=childIndex(Pa);

		child(Pa)[index]=child(node)[not index];
		if(0<=child(node)[not index])
			par(child(node)[not index])=Pa;
		child(node)[not index]=Pa;
		par(Pa)=node;
		par(node)=grandPar;
		if(not oldParIsSplayRoot) child(grandPar)[oldParIndex]=node;

		recalculate(Pa);
		recalculate(node);
		checkConsistency();
	}
	void makeSplayRoot(int node){
		checkConsistency();
		while(not isSplayRoot(node)) {
			auto Pa=par(node);
			if(not isSplayRoot(Pa)){
				if(childIndex(Pa)==childIndex(node))
					rotate(Pa);
				else
					rotate(node);
				rotate(node);
			}else{
				rotate(node);
				assert(isSplayRoot(node));
			}
		}
		checkConsistency();
	}
	void access(int node) {
		makeSplayRoot(node);
		checkConsistency();
		while(par(node)>=0) {
			assert(isSplayRoot(node));
			auto Pa=par(node);
			assert(Pa>node); // for this problem. Not true for link cut tree int general
			makeSplayRoot(Pa);
			assert(isSplayRoot(node));
			if(child(Pa)[1]>=0) {
				auto ch=child(Pa)[1];
				assert(par(ch)==Pa);
				subtreeSize(Pa)-=subtreeSize(ch);
				child(Pa)[1]=-1;
			}
			child(Pa)[1]=node;
			subtreeSize(Pa)+=subtreeSize(node);
			rotate(node);
		}
		checkConsistency();
	}
	void checkConsistency(){
		for(int node=0;node<numNode();++node) {
			assert(subtreeSize(node)==1+
					(child(node)[0]>=0 ? subtreeSize(child(node)[0]): 0)+
					(child(node)[1]>=0 ? subtreeSize(child(node)[1]): 0)
				  );
			assert(minNextGap(node)==std::min({
				nextGap(node),
					child(node)[0]>=0 ? minNextGap(child(node)[0]): INT_MAX,
					child(node)[1]>=0 ? minNextGap(child(node)[1]): INT_MAX
			}));
			if(isSplayRoot(node)){
				// this is not true int the general	case, but for this problem it is
				assert(par(node)<0 or par(node)>node);
			}
			assert(child(node)[1]<node);
			assert(child(node)[0]==-1 or child(node)[0]>=node);

			int x=node;
			for(int _=0;_<numNode();++_) {
				x=par(x);
				if(x<0) break;
			}
			assert(x==-1);

		}
	}
};



struct step_t{
	int nextGap,nexti;
};

step_t next(int const l,int const maxGap){
	if(l==(int)x.size()) return {INT_MAX,INT_MAX};
	assert((std::size_t)l<x.size());
	int r=l+1;
	int curmin=x[l],curmax=x[l];
	assert(rmqmin.d.size()==rmqmax.d.size());
	for(auto layer=rmqmin.d.size();layer--;){
		assert(rmqmin.d[layer].size()==rmqmax.d[layer].size());
		if(r<(int)rmqmin.d[layer].size() and
				std::max(curmax,rmqmax.d[layer][r])-
				std::min(curmin,rmqmin.d[layer][r])<=maxGap){
			curmax=std::max(curmax,rmqmax.d[layer][r]);
			curmin=std::min(curmin,rmqmin.d[layer][r]);
			r+=1<<layer;
		}
	}

	assert(curmax>=curmin and curmax-curmin<=maxGap);
	int nextGap=INT_MAX;
	if(r!=(int)x.size()){
		int nextmax=std::max(curmax,x[r]);
		int nextmin=std::min(curmin,x[r]);
		assert(nextmax-nextmin>maxGap);
		nextGap=nextmax-nextmin;
	}

	/*
	static struct A{
		std::array<int,100000> cnt;
		~A(){ 
			for(unsigned i=0;i<cnt.size();++i) if(cnt[i])
				std::cerr<<i<<' '<<cnt[i]<<'\n';
			std::cerr<<"total "<<std::accumulate(begin(cnt),end(cnt),0LL)<<'\n';
		}
	} a;
	++a.cnt[r-l];
	*/


	return {nextGap,r};
}


int main(){
	using io::readUInt;
	using io::writeInt;
	using io::writeChar;
	int n=readUInt(),w=readUInt(),nquery=readUInt();

	x.resize(n);
	// std::copy_n(std::ostream_iterator<int>(std::cin),begin(x),n);
	for(auto& xi:x) xi = readUInt();

	rmqmin.assign(x);
	rmqmax.assign(x);

	struct query{ int maxGap /* w-k */ ,ind; };
	std::vector<query> qs;
	qs.resize(nquery);
	std::generate(begin(qs),end(qs),[i=0,w]() mutable { int k = readUInt();return query{w-k,i++}; });

	std::sort(begin(qs),end(qs),[](auto a,auto b){ return a.maxGap<b.maxGap; });
	std::vector<int> out_nsegment(nquery);

	LinkCutTree tree(n);

	for(auto const [maxGap,queryind]:qs){
		//int i=0; // need to recompute fi
		//while(f[i].nextGap<=maxGap){

		/*
		if(0){
			int l=0;
			while(1){
				compute<1>(l,maxGap);
				int r=f[l].jump[0].nexti;
				if(r==INT_MAX) break;
				std::cerr<<r-l<<' ';
				l=r;
			}
			std::cerr<<'\n';
		}
		*/

		int node=0;
		auto& out=out_nsegment[queryind]=0;
		tree.access(node);
		while(node<n){
			auto const leftChild=tree.child(node)[0];
			if(tree.nextGap(node)>maxGap and (
				leftChild<0 or tree.minNextGap(leftChild)>maxGap)){
				out+=1+(leftChild<0 ? 0: tree.subtreeSize(leftChild));
				break;
			}
			auto other=node;
			if(tree.nextGap(node)>maxGap){
				++out;
				other=leftChild;
				assert(tree.minNextGap(other)<=maxGap);
				while(true){
					auto const child=tree.child(other);
					if(child[1]>=0 and tree.minNextGap(child[1])<=maxGap)
						other=child[1];
					else if(tree.nextGap(other)<=maxGap){
						out+=child[1]>=0 ? tree.subtreeSize(child[1]) : 0;
						break;
					}else{
						out+=child[1]>=0 ? tree.subtreeSize(child[1]) : 0;
						++out;
						other=child[0];
					}
				}
			}
			// other=last node not after(node) with nextGap<=maxGap

			tree.makeSplayRoot(other);
			auto const otherNext=next(other, maxGap);
			assert(otherNext.nexti!=tree.par(other));
			tree.cut(other);
			if(otherNext.nexti!=n){
				tree.link(other, otherNext.nexti);
			}

			tree.makeSplayRoot(other);
			tree.nextGap(other)=otherNext.nextGap;
			tree.recalculate(other);

			node=other;
			tree.access(node);
		}
	}

	for(auto x:out_nsegment)  {
		writeInt(unsigned(x-1));
		writeChar('\n');
	}
}