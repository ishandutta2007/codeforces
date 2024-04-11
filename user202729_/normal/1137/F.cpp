/*
<deleted deleted>

Split on demand. Locally with a test with all update queries, the time taken is 3.6s.
However, I'm afraid that some pathological test cases may still make this code exhibit its worst
run time.

TODO avoid using dynamic tree.
TODO special-case the processing of the initial value computation. currently it takes half the run time already.
	-> done. The run time on that test reduces to 2.1s.
	However I removed the optimization that stores the iterator with interval_.
TODO "compress" multiple update queries into one.
*/

#ifdef LOCAL
#include<iostream>
#else
#define NDEBUG
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<queue>
#include<cassert>
#include<climits>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cassert>
#include<tuple>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
namespace io{using namespace std;static const int buf_size=4096;static unsigned char buf[buf_size];static int buf_len=0,buf_pos=0;inline bool isEof(){if(buf_pos==buf_len){buf_pos=0,buf_len=fread(buf,1,buf_size,stdin);if(buf_pos==buf_len)return 1;}return 0;}inline int getChar(){return isEof()?-1:buf[buf_pos++];}inline int peekChar(){return isEof()?-1:buf[buf_pos];}inline bool seekEof(){int c;while((c=peekChar())!=-1&&c<=32)buf_pos++;return c==-1;}inline void skipBlanks(){while(!isEof()&&buf[buf_pos]<=32U)buf_pos++;}inline int readChar(){int c=getChar();while(c!=-1&&c<=32)c=getChar();return c;}inline int readUInt(){int c=readChar(),x=0;while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return x;}template<class T=int>inline T readInt(){int s=1,c=readChar();T x=0;if(c=='-')s=-1,c=getChar();else if(c=='+')c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return s==1?x:-x;}inline double readDouble(){int s=1,c=readChar();double x=0;if(c=='-')s=-1,c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();if(c=='.'){c=getChar();double coef=1;while('0'<=c&&c<='9')x+=(c-'0')*(coef*=1e-1),c=getChar();}return s==1?x:-x;}inline void readWord(char*s){int c=readChar();while(c>32)*s++=c,c=getChar();*s=0;}inline bool readLine(char*s){int c=getChar();while(c!='\n'&&c!=-1)*s++=c,c=getChar();*s=0;return c!=-1;}static int write_buf_pos=0;static char write_buf[buf_size];inline void writeChar(int x){if(write_buf_pos==buf_size)fwrite(write_buf,1,buf_size,stdout),write_buf_pos=0;write_buf[write_buf_pos++]=x;}inline void flush(){if(write_buf_pos){fwrite(write_buf,1,write_buf_pos,stdout),write_buf_pos=0;fflush(stdout);}}template<class T>inline void writeInt(T x,char end=0,int output_len=-1){if(x<0)writeChar('-'),x=-x;char s[24];int n=0;while(x||!n)s[n++]='0'+x%10,x/=10;while(n<output_len)s[n++]='0';while(n--)writeChar(s[n]);if(end)writeChar(end);}inline void writeWord(const char*s){while(*s)writeChar(*s++);}inline void writeDouble(double x,int output_len=0){if(x<0)writeChar('-'),x=-x;int t=(int)x;writeInt(t),x-=t;writeChar('.');for(int i=output_len-1;i>0;i--){x*=10;t=std::min(9,(int)x);writeChar('0'+t),x-=t;}x*=10;t=std::min(9,(int)(x+0.5));writeChar('0'+t);}static struct buffer_flusher_t{~buffer_flusher_t(){flush();}}buffer_flusher;};
#pragma GCC diagnostic pop

std::vector<std::vector<int>> ad;

std::vector<int> depth,par,subtree_size;
int dd(int x){ // dfs compute depth, par and subtree_size, prepare for init_jt
	subtree_size[x]=1;
	for(int y:ad[x]){
		ad[y].erase(std::find(begin(ad[y]),end(ad[y]),x));
		par[y]=x;
		depth[y]=depth[x]+1;
		subtree_size[x]+=dd(y);
	}
	return subtree_size[x];
}

struct interval{
	int64_t l,r;
	int size()const{
		assert(l<=r and r-l<=INT_MAX);
		return int(r-l);
	}
	int64_t operator[](int64_t x)const{
		assert(x>=0 and l+x<r);
		return l+x;
	}
	bool operator==(interval x)const{ return std::tie(l,r)==std::tie(x.l,x.r); }
	bool operator<(interval x)const{
		assert(x==*this or std::max(l,x.l)>=std::min(r,x.r));
		return l<x.l;
	}
};

auto& operator<<(std::ostream& str,interval x){
	return str<<'('<<x.l<<' '<<x.r<<')';
}

template<class Const_Node_Iterator,
	 class Node_Iterator,
	 class Cmp_Fn,
	 class Allocator>
struct intervals_node_update
{
public:
	using metadata_type=int64_t; // total size of intervals

	int64_t sum_suffix(int64_t x)const{
		//Const_Node_Iterator nd_it = node_begin();
		//Const_Node_Iterator end_it = node_end();

		// The time difference should be negligible anyway (most of the time is spent int the update_not_insert_st function)
		Const_Node_Iterator nd_it=((__gnu_pbds::tree<interval, __gnu_pbds::null_type, std::less<interval>, __gnu_pbds::rb_tree_tag, intervals_node_update>*)this)->node_begin();
		Const_Node_Iterator end_it=((__gnu_pbds::tree<interval, __gnu_pbds::null_type, std::less<interval>, __gnu_pbds::rb_tree_tag, intervals_node_update>*)this)->node_end();

		int64_t out=0;

		while (nd_it != end_it)
		{
			auto const [l,r]=**nd_it;
			assert(l<r);

			if(nd_it.get_r_child()!=end_it) assert(**nd_it < **nd_it.get_r_child());
			if(nd_it.get_l_child()!=end_it) assert(**nd_it.get_l_child() < **nd_it);

			if(x<=r){
				out+=r-std::max(l,x);
				if(nd_it.get_r_child()!=end_it)
					out+=nd_it.get_r_child().get_metadata();
				if(x>=l)
					break;
				else
					nd_it = nd_it.get_l_child();
			}else{
				nd_it = nd_it.get_r_child();
			}
		}

		return out;
	}

protected:
	// Update predicate: nd_it is a node iterator to the node currently
	// updated; end_nd_it is a const node iterator to a just-after leaf
	// node.
	void operator()(Node_Iterator nd_it, Const_Node_Iterator end_nd_it)const{
		auto const [l,r]=**nd_it;
		assert(l<r);
		const_cast<metadata_type&>(nd_it.get_metadata()) =
			r-l +
			(nd_it.get_l_child() == end_nd_it? 0 : nd_it.get_l_child().get_metadata()) +
			(nd_it.get_r_child() == end_nd_it? 0 : nd_it.get_r_child().get_metadata());
	}

	virtual Const_Node_Iterator
	node_begin() const = 0;

	virtual Const_Node_Iterator
	node_end() const = 0;

	virtual
	~intervals_node_update()
	{ }
};

__gnu_pbds::tree<interval, __gnu_pbds::null_type, std::less<interval>, __gnu_pbds::rb_tree_tag, intervals_node_update
> st;
// Contains all intervals that appear int any chain, may be compressed (but not fragmented)
// TODO: make r the value instead of the key.

void st_erase(interval x){
	assert(x.l<x.r);
	auto iter=st.lower_bound(interval{x.r,x.r});
	assert(iter!=st.begin()); --iter;
	// iter: max segment with l < x.r
	auto const [il,ir]=*iter;
	assert(il<=x.l and x.r<=ir);
	st.erase(iter);
	if(il<x.l) st.insert({il,x.l});
	if(x.r<ir) st.insert({x.r,ir});
}

struct chain{ // HLD chain
	struct interval_{
		interval val;
		bool reverse;

		auto operator[](int64_t x)const{
			return val[reverse?val.size()-x-1:x];
		}

		std::pair<interval_,interval_> split(int firstsize)const{
			auto const [first,last]=val;
			assert(0<firstsize and firstsize<last-first);
			if(reverse)
				return {{{last-firstsize,last},true},
					{{first,last-firstsize},true}};
			else
				return {{{first,first+firstsize},false},
					{{first+firstsize,last},false}};
		}
	};
	std::map<int, // min depth of a segment
		interval_> d;
	int firstdepth;
	int lastdepth; // exclusive
	int parroot;

	void update_not_insert_st(int depth,interval_ i){
		assert(depth>=firstdepth);
		assert(d.begin()->first==firstdepth);
		assert(d.rbegin()->first+d.rbegin()->second.val.size()==lastdepth);

		auto iter=--d.upper_bound(depth);
		assert(iter->first<=depth);
		if(iter->first<depth){
			auto [prev_depth,old_interval]=*iter;

			auto [a,b]=old_interval.split(depth-prev_depth);
			st_erase(b.val);
			iter=d.erase(iter);

			assert(not d.count(prev_depth));
			iter=d.insert(iter,{prev_depth,a});

			// TODO: it's better to store the iterator with interval_ instead of looking it up?
			++iter;
		}

		assert(iter==end(d) or iter->first>=depth);
		int const lastdepth=depth+i.val.size();
		while(iter!=end(d) and iter->first<lastdepth){
			auto const [dd,old_interval]=*iter;
			if(dd+old_interval.val.size()>lastdepth){ // split
				auto [a,b]=old_interval.split(lastdepth-dd);
				st_erase(a.val);
				iter=d.erase(iter);

				assert(not d.count(lastdepth));
				iter=d.insert(iter,{lastdepth,b});

				break;
			}

			iter=d.erase(iter);
			st_erase(old_interval.val);
		}

		d.insert(iter,{depth,i});
	}

	int64_t get(int depth)const{
		assert(firstdepth<=depth and depth<lastdepth);
		auto [i_firstdepth,i]=*--d.upper_bound(depth);
		return i[depth-i_firstdepth];
	}
};
std::vector<chain> chains;
std::vector<int> chainof;

void dd2(int node,int chain_node){ // construct HLD
	chainof[node]=chain_node;
	if(ad[node].empty()){
		chains[chain_node].lastdepth=depth[node]+1;
		return;
	}
	auto bigchild=*std::max_element(begin(ad[node]),end(ad[node]),[](int a,int b){
			return subtree_size[a]<subtree_size[b];
			});
	for(int child:ad[node])
		if(child==bigchild)
			dd2(child,chain_node);
		else{
			chains.push_back({});
			chains.back().firstdepth=depth[child];
			chains.back().parroot=node;
			dd2(child,int(chains.size()-1));
		}
}

int main(){
	int nnode=io::readUInt(),nquery=io::readUInt();
	ad.resize(nnode);
	depth.resize(nnode);
	par.resize(nnode);
	subtree_size.resize(nnode);
	for(int z=nnode;--z;){
		int u=io::readUInt(),v=io::readUInt();
		--u;--v;
		ad[u].push_back(v);ad[v].push_back(u);
	}

	std::vector<int> initial_node_val(nnode); // need to compute this before dd removes the edges to parent.
	{
		std::priority_queue<int,std::vector<int>,std::greater<int>> q; // contain priority == node
		std::vector<int> deg(nnode);
		for(int node=nnode;node--;)
			if((deg[node]=int(ad[node].size()))==1)
				q.push(node);

		int lastval=nnode;
		while(not q.empty()){
			int node=q.top();q.pop();
			initial_node_val[node]=--lastval;
			for(int adn:ad[node]){
				if((--deg[adn])==1)
					q.push(adn);
			}
		}
		assert(lastval==0);
	}


	dd(0);

	chains.push_back({});
	assert(chains.back().firstdepth==0 and depth[0]==0);
	chainof.resize(nnode);
	// chains.back().firstdepth=depth[0];
	chains.back().parroot=-1;
	dd2(0,0);

	int oldroot=int(std::find(begin(initial_node_val),end(initial_node_val),0)-begin(initial_node_val));

	for(int node=nnode;node--;)
		chains[chainof[node]].d.insert({depth[node],
				{interval{initial_node_val[node],initial_node_val[node]+1},/*reverse*/false}});

	int64_t minval=0;
	st.insert({0,nnode});

	initial_node_val.clear();

	auto const up_query=[&](int const node){
		if(node==oldroot)return;
		// fill (node, ..., oldroot) with increasing values < minval
		// in particular:
		//   node .. lca <- l .. l+something;
		//   lca .. oldroot <- r-something .. r
		// the numbers in l+something .. r-something won't be used, but that's not a problem.
		auto l=minval-nnode,r=minval;


		int x=node,y=oldroot;
		while(true){
			if(chainof[x]==chainof[y]){ // includes the case when x = y.
				auto& c=chains[chainof[x]];
				if(depth[x]>depth[y]){
					int upd_size=depth[x]-depth[y]+1;
					c.update_not_insert_st(depth[y],{{l,l+upd_size},true});
					l+=upd_size;
				}else{
					int upd_size=depth[y]-depth[x]+1;
					c.update_not_insert_st(depth[x],{{r-upd_size,r},false});
					r-=upd_size;
				}
				break;
			}

			if(chains[chainof[x]].firstdepth>
					chains[chainof[y]].firstdepth){
				auto& c=chains[chainof[x]];
				int upd_size=depth[x]-c.firstdepth+1;
				c.update_not_insert_st(c.firstdepth,{{l,l+upd_size},true});
				l+=upd_size;
				x=c.parroot;
			}else{
				auto& c=chains[chainof[y]];
				int upd_size=depth[y]-c.firstdepth+1;
				c.update_not_insert_st(c.firstdepth,{{r-upd_size,r},false});
				r-=upd_size;
				y=c.parroot;
			}
		}

		if(r<minval)
			st.insert({r,minval});
		if(minval-nnode<l)
			st.insert({minval-nnode,l});
		minval-=nnode;

		oldroot=node;
	};

	for(int z=nquery;z--;){
		std::array<char,10> word;
		io::readWord(word.data());
		int const node=io::readUInt()-1;
		switch(word[0]){
			case 'w':
				io::writeInt(st.sum_suffix(chains[chainof[node]].get(depth[node])));
				io::writeChar('\n');
				break;
			case 'u':
				up_query(node);
				break;
			case 'c':
				{
					int node2=io::readUInt()-1;
					if(
							chains[chainof[node]].get(depth[node])
							>
							chains[chainof[node2]].get(depth[node2])
					  )
						io::writeInt(node+1);
					else
						io::writeInt(node2+1);
				}
				io::writeChar('\n');
				break;
			default:
				assert(0); __builtin_unreachable();
		}
	}
}