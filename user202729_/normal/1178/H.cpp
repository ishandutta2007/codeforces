#ifndef LOCAL
#define NDEBUG 1
#pragma GCC optimize "O3" // for memset optimization
#endif
#include<bits/stdc++.h>


// The input/output size of this problem is small, but just in case.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
namespace io{using namespace std;static const int buf_size=4096;static unsigned char buf[buf_size];static int buf_len=0,buf_pos=0;inline bool isEof(){if(buf_pos==buf_len){buf_pos=0,buf_len=fread(buf,1,buf_size,stdin);if(buf_pos==buf_len)return 1;}return 0;}inline int getChar(){return isEof()?-1:buf[buf_pos++];}inline int peekChar(){return isEof()?-1:buf[buf_pos];}inline bool seekEof(){int c;while((c=peekChar())!=-1&&c<=32)buf_pos++;return c==-1;}inline void skipBlanks(){while(!isEof()&&buf[buf_pos]<=32U)buf_pos++;}inline int readChar(){int c=getChar();while(c!=-1&&c<=32)c=getChar();return c;}inline int readUInt(){int c=readChar(),x=0;while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return x;}template<class T=int>inline T readInt(){int s=1,c=readChar();T x=0;if(c=='-')s=-1,c=getChar();else if(c=='+')c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();return s==1?x:-x;}inline double readDouble(){int s=1,c=readChar();double x=0;if(c=='-')s=-1,c=getChar();while('0'<=c&&c<='9')x=x*10+c-'0',c=getChar();if(c=='.'){c=getChar();double coef=1;while('0'<=c&&c<='9')x+=(c-'0')*(coef*=1e-1),c=getChar();}return s==1?x:-x;}inline void readWord(char*s){int c=readChar();while(c>32)*s++=c,c=getChar();*s=0;}inline bool readLine(char*s){int c=getChar();while(c!='\n'&&c!=-1)*s++=c,c=getChar();*s=0;return c!=-1;}static int write_buf_pos=0;static char write_buf[buf_size];inline void writeChar(int x){if(write_buf_pos==buf_size)fwrite(write_buf,1,buf_size,stdout),write_buf_pos=0;write_buf[write_buf_pos++]=x;}inline void flush(){if(write_buf_pos){fwrite(write_buf,1,write_buf_pos,stdout),write_buf_pos=0;fflush(stdout);}}template<class T>inline void writeInt(T x,char end=0,int output_len=-1){if(x<0)writeChar('-'),x=-x;char s[24];int n=0;while(x||!n)s[n++]='0'+x%10,x/=10;while(n<output_len)s[n++]='0';while(n--)writeChar(s[n]);if(end)writeChar(end);}inline void writeWord(const char*s){while(*s)writeChar(*s++);}inline void writeDouble(double x,int output_len=0){if(x<0)writeChar('-'),x=-x;int t=(int)x;writeInt(t),x-=t;writeChar('.');for(int i=output_len-1;i>0;i--){x*=10;t=std::min(9,(int)x);writeChar('0'+t),x-=t;}x*=10;t=std::min(9,(int)(x+0.5));writeChar('0'+t);}static struct buffer_flusher_t{~buffer_flusher_t(){flush();}}buffer_flusher;};
#pragma GCC diagnostic pop


template<class cap_t=int,class cost_t=int>
struct MCMF{
	std::vector<std::vector<int>> ad;
	struct edge{
		int v;
		cap_t residual;
		cost_t cost;
	};
	std::vector<edge> edges;

	MCMF(int n):ad(n){}
	void addedge(int a,int b,cap_t cap,cost_t cost){
		ad[a].push_back((int)edges.size());
		edges.push_back({b,cap,cost});
		ad[b].push_back((int)edges.size());
		edges.push_back({a,(cap_t)0,-cost});
	}

	std::pair<cap_t,cost_t> run(int source,int sink){
		// "slow" algorithm. Does not work properly when there's any negative cycle.
		cap_t total_flow=0;cost_t total_cost=0;

		std::vector<char> inq;
		std::vector<cost_t> dist(ad.size());
		std::vector<int> q(ad.size()+1);
		std::vector<int> pre(ad.size());

		while(true){
			inq.assign(ad.size(),false);

			static_assert(sizeof(cost_t)==4,"");
			cost_t constexpr INF=0x3f3f3f3f;

			dist.assign(ad.size(),INF);
			auto qfront=begin(q),qback=begin(q);

			auto const qempty=[&]{ return qfront==qback; };
			auto const qpush=[&](int x){
				*qback++=x;
				if(qback==q.end()) qback=q.begin();
				assert(not qempty());
			};
			auto const qpop=[&]{
				assert(not qempty());
				++qfront;
				if(qfront==q.end()) qfront=q.begin();
			};

			dist[source]=0;
			qpush(source);
			inq[source]=true;

			while(not qempty()){
				int x=*qfront;qpop();
				inq[x]=false;
				auto dx=dist[x];
				for(int edgeid:ad[x]){
					edge& e=edges[edgeid];
					if(e.residual){
						auto nd=e.cost+dx;
						if(nd<dist[e.v]){
							dist[e.v]=nd;
							pre[e.v]=edgeid;
							if(not inq[e.v]){
								inq[e.v]=true;
								qpush(e.v);
							}
						}
					}
				}
			}

			if(dist[sink]==INF)
				return {total_flow,total_cost};

			int x=sink;
			cap_t f=std::numeric_limits<cap_t>::max();
			while(x!=source){
				f=std::min(f,edges[pre[x]].residual);
				x=edges[pre[x]^1].v;
			}

			x=sink;
			while(x!=source){
				edges[pre[x]].residual-=f;
				edges[pre[x]^1].residual+=f;
				x=edges[pre[x]^1].v;
			}

			total_flow+=f;
			total_cost+=f*dist[sink];
		}
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n=io::readUInt();
	struct pt{ int64_t x,y; int id; };
	std::vector<pt> ps(n*2); // points
	for(int id=0;id<2*n;++id){
		ps[id].x=io::readInt<int64_t>();
		ps[id].y=io::readInt<int64_t>();
		ps[id].id=id;
	}

	std::vector<pt> pd; // distorted points

	auto const distort_points=[&](int time){
		pd.resize(ps.size());
		std::transform(begin(ps),end(ps),begin(pd),[&](pt a){ return pt{time*a.x+a.y, a.y, a.id}; });
		// after distortion, movement at time t is transformed to movement int decreasing x direction
	};

	auto const check=[&](int time){
		distort_points(time);

		// now find the point with maximum x coordinate that is reachable from each point (only move downwards)
		std::sort(begin(pd),end(pd),[](pt a,pt b){ return a.y!=b.y ? a.y<b.y : a.x>b.x; });
		// TODO move this sort outside?
		auto maxx=pd[0].x;
		for(pt& p:pd){
			maxx=std::max(p.x,maxx);
			if(p.id<n){
				p.x=maxx;
			}
		} // now the x value of points with id < n are maximum reachable x

		std::sort(begin(pd),end(pd),[](pt a,pt b){ return a.x<b.x; });
		auto lastx=pd[0].x-1;
		int deg=0;
		for(pt& p:pd){ // check if there exists a perfect matching
			if(p.x!=lastx){
				if(deg<0) return false;
				lastx=p.x;
			}
			if(p.id<n) --deg; else ++deg;
		}
		assert(deg==0);
		return true;
	};

	int time=2000000000;
	if(not check(time)){ std::cout<<"-1\n"; return 0; }
	for(int step=1<<30;step;step>>=1)
		if(time-step>=0 and check(time-step)) time-=step;


	distort_points(time);

	int nxval,nyval;
	for(auto const member:{ &pt::x, &pt::y }){ // compress coordinates
		std::vector<int64_t> vals(pd.size());
		std::transform(begin(pd),end(pd),begin(vals),[&](pt a){ return a.*member; });
		std::sort(begin(vals),end(vals));
		vals.erase(std::unique(begin(vals),end(vals)),end(vals));

		(member==&pt::x ? nxval : nyval)=(int)vals.size();
		for(pt& a:pd)
			a.*member=std::lower_bound(begin(vals),end(vals),a.*member)-begin(vals);
	}

	int const xbase=0;
	int const ybase=xbase+nxval;
	int const ptbase=ybase+nyval;
	int const source=ptbase+(int)pd.size();
	int const sink=source+1;
	MCMF flow(sink+1);

	for(int i=0;i<int(pd.size()/2);++i){
		assert(pd[i].id==i);
		flow.addedge(source,ptbase+i,1,0);
		flow.addedge(ptbase+i,xbase+(int)pd[i].x,1,1);
		flow.addedge(ptbase+i,ybase+(int)pd[i].y,1,1);

		auto const j=i+int(pd.size()/2);
		assert(pd[j].id==j);
		flow.addedge(ptbase+j,sink,1,0);
		flow.addedge(xbase+(int)pd[j].x,ptbase+j,1,0);
		flow.addedge(ybase+(int)pd[j].y,ptbase+j,1,0);
	}

	for(int x=1;x<nxval;++x) flow.addedge(xbase+x,xbase+x-1,(int)pd.size() /* INF cap */,0);
	for(int y=1;y<nyval;++y) flow.addedge(ybase+y,ybase+y-1,(int)pd.size(),0);


	{ // NOTE partially copied from above
		// now find the point with maximum x coordinate that is reachable from each point (only move downwards)
		std::sort(begin(pd),end(pd),[](pt a,pt b){ return a.y!=b.y ? a.y<b.y : a.x>b.x; });
		// TODO move this sort outside?
		auto maxx=pd[0].x;
		for(pt& p:pd){
			maxx=std::max(p.x,maxx);
			if(p.id<n)
				flow.addedge(ptbase+p.id,xbase+(int)maxx,1,2);
		} // now the x value of points with id < n are maximum reachable x
	}

	auto [flowvalue,mincost]=flow.run(source,sink);
	assert(flowvalue==int(pd.size()/2));

	std::cout<<time<<' '<<mincost<<'\n';
}