// fast io.
// + restructure the data types
// + some other optimizations.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
namespace io{using namespace std;static const int buf_size=4096;static unsigned char buf[buf_size];static int buf_len=0,buf_pos=0;inline bool isEof(){if(buf_pos==buf_len){buf_pos=0,buf_len=fread(buf,1,buf_size,stdin);if(buf_pos==buf_len)return 1;}return 0;}inline int getChar(){return isEof()?-1:buf[buf_pos++];}inline int peekChar(){return isEof()?-1:buf[buf_pos];}inline bool seekEof(){int c;while((c=peekChar())!=-1&&c<=32)buf_pos++;return c==-1;}inline void skipBlanks(){while(!isEof()&&buf[buf_pos]<=32U)buf_pos++;}inline int readChar(){int c=getChar();while(c!=-1&&c<=32)c=getChar();return c;}inline int readUInt(){int c=readChar(),x=0;while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return x;}template<class T=int>inline T readInt(){int s=1,c=readChar();T x=0;if(c=='-')s=-1,c=getChar();else if(c=='+')c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return s==1?x:-x;}inline double readDouble(){int s=1,c=readChar();double x=0;if(c=='-')s=-1,c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();if(c=='.'){c=getChar();double coef=1;while('0'<=c&&c<='9')x+=(c-'0')*(coef*=1e-1),c=getChar();}return s==1?x:-x;}inline void readWord(char*s){int c=readChar();while(c>32)*s++=c,c=getChar();*s=0;}inline bool readLine(char*s){int c=getChar();while(c!='\n'&&c!=-1)*s++=c,c=getChar();*s=0;return c!=-1;}static int write_buf_pos=0;static char write_buf[buf_size];inline void writeChar(int x){if(write_buf_pos==buf_size)fwrite(write_buf,1,buf_size,stdout),write_buf_pos=0;write_buf[write_buf_pos++]=x;}inline void flush(){if(write_buf_pos){fwrite(write_buf,1,write_buf_pos,stdout),write_buf_pos=0;fflush(stdout);}}template<class T>inline void writeInt(T x,char end=0,int output_len=-1){if(x<0)writeChar('-'),x=-x;char s[24];int n=0;while(x||!n)s[n++]='0'+x%10,x/=10;while(n<output_len)s[n++]='0';while(n--)writeChar(s[n]);if(end)writeChar(end);}inline void writeWord(const char*s){while(*s)writeChar(*s++);}inline void writeDouble(double x,int output_len=0){if(x<0)writeChar('-'),x=-x;int t=(int)x;writeInt(t),x-=t;writeChar('.');for(int i=output_len-1;i>0;i--){x*=10;t=std::min(9,(int)x);writeChar('0'+t),x-=t;}x*=10;t=std::min(9,(int)(x+0.5));writeChar('0'+t);}static struct buffer_flusher_t{~buffer_flusher_t(){flush();}}buffer_flusher;};
#pragma GCC diagnostic pop


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
	};
	std::vector<data> nodes;

	auto& par(auto x){ return nodes[x].par; }
	std::array<int,2>& child(auto x){ return nodes[x].child; }
	auto& subtreeSize(auto x){ return nodes[x].subtreeSize; }

	auto par(auto x)const{ return nodes[x].par; }
	std::array<int,2> child(auto x)const{ return nodes[x].child; }
	auto subtreeSize(auto x)const{ return nodes[x].subtreeSize; }

	auto numNode()const{ return (int)nodes.size(); }

	LinkCutTree(int n):
		//par (n,-1), child (n,{-1,-1}), subtreeSize(n, 1)
		nodes(n,{-1,{-1,-1},1})
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
			 subtreeSize(node)-=subtreeSize(leftChild);
			 child(node)[0]=par(node)=-1;
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

		subtreeSize(node)=subtreeSize(Pa);
		subtreeSize(Pa)-=child(node)[index]>=0 ? subtreeSize(child(node)[index]): 0;
		subtreeSize(Pa)-=1;
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

int main(){
	int n=io::readUInt(), numQuery=io::readUInt();
	LinkCutTree tree(n);
	for(int node=0;node<n;++node) {
		int Pa=io::readUInt(); 
		Pa+=node;
		if(Pa<n) tree.link(node,Pa);
	}
	for(int query=0;query<numQuery;++query){
		char type=(char)io::readChar();
		if(type=='0'){
			int node=io::readUInt(), newPar=io::readUInt(); 
			--node; newPar+=node;
			tree.makeSplayRoot(node);
			tree.cut(node);
			if(newPar<n)
				tree.link(node,newPar);
		}else{
			assert(type=='1');
			int node=io::readUInt()-1;
			tree.access(node);
			auto leftChild=tree.child(node)[0];
			if(leftChild<0){
				io::writeInt(unsigned(node+1)); io::writeWord(" 1\n");
			}else{
				auto numJump=tree.subtreeSize(leftChild)+1;

				auto leftmost=leftChild;
				int leftmostDepth=1;
				while(tree.child(leftmost)[0]>=0){
					++leftmostDepth;
					leftmost=tree.child(leftmost)[0];
				}

				/*
				tree.makeSplayRoot(leftmost);

				NOTE If I understood correctly, the currently-fastest solution 47725097 does not make `leftmost`
				the splay tree root (in the `find` function), which makes the worst case time complexity is O(n^2).
				*/

				// replacement for `makeSplayRoot` (but faster).
				for(int _=0;_<leftmostDepth/2;++_) {
					tree.rotate<true>(tree.par(leftmost));
					tree.rotate<true>(leftmost);
				}
				if (leftmostDepth%2!=0){
					tree.rotate<true>(leftmost);
				}
				assert(tree.isSplayRoot(leftmost));


				io::writeInt(unsigned(leftmost+1));
				io::writeChar(' ');
				io::writeInt(unsigned(numJump));
				io::writeChar('\n');
			}
		}
	}
}