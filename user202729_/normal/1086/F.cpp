#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#define MEMO 1

#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>

struct tree{int x,y;};
std::vector<tree> trees;

#if MEMO
#include<unordered_map>
std::unordered_map<int,int64_t> totalarea_memo;
#endif

int64_t totalarea(int t){
	// compute total number of lattice points in the union of rectangles
	// [x-t..x+t, y-t..y+t]
	if(t<0)return 0; // ...
	if(t==0)return trees.size();

#if MEMO
	auto iter=totalarea_memo.find(t);
	if(iter!=totalarea_memo.end())return iter->second;
#endif

	struct rect{int firstx,lastx,firsty,lasty;};
	std::vector<rect> rects(trees.size());
	std::transform(trees.begin(),trees.end(),rects.begin(),
	[t](tree a){return rect{a.x-t,a.x+t+1,a.y-t,a.y+t+1};});

	std::vector<int> xcoord,ycoord;
	xcoord.reserve(trees.size()*2);
	ycoord.reserve(trees.size()*2);
	for(auto r:rects){
		xcoord.push_back(r.firstx);
		xcoord.push_back(r.lastx);
		ycoord.push_back(r.firsty);
		ycoord.push_back(r.lasty);
	}
	std::sort(xcoord.begin(),xcoord.end());
	std::sort(ycoord.begin(),ycoord.end());
	xcoord.erase(std::unique(xcoord.begin(),xcoord.end()),xcoord.end());
	ycoord.erase(std::unique(ycoord.begin(),ycoord.end()),ycoord.end());
	std::vector<std::vector<int>> acm(xcoord.size(),std::vector<int>(ycoord.size()));
#define FIND(x,vec) (int(std::lower_bound(vec.begin(),vec.end(),x)-vec.begin()))
	for(auto r:rects){
		r.firstx=FIND(r.firstx,xcoord);
		r.lastx=FIND(r.lastx,xcoord);
		r.firsty=FIND(r.firsty,ycoord);
		r.lasty=FIND(r.lasty,ycoord);
		++acm[r.firstx][r.firsty];
		--acm[r.firstx][r.lasty];
		--acm[r.lastx][r.firsty];
		++acm[r.lastx][r.lasty];
	}
#undef FIND

	for(unsigned row=1;row<xcoord.size();++row)
		for(unsigned col=0;col<ycoord.size();++col)
			acm[row][col]+=acm[row-1][col];
	for(unsigned row=0;row<xcoord.size();++row)
		for(unsigned col=1;col<ycoord.size();++col)
			acm[row][col]+=acm[row][col-1];
	int64_t ans=0;
	for(unsigned row=0;row<xcoord.size()-1;++row)
		for(unsigned col=0;col<ycoord.size()-1;++col){
			if(acm[row][col])
				ans+=(xcoord[row+1]-xcoord[row])*int64_t(ycoord[col+1]-ycoord[col]);
		}

#if MEMO
	totalarea_memo.emplace(t,ans);
#endif

	return ans;
}

// a piecewise linear function with (time)
int64_t ncellwithval(int time){
	return totalarea(time)-totalarea(time-1);
}

int constexpr MOD=998244353;

template<class T,T f>
int sumfn(int min,int max,int64_t fmin,int64_t fmax){
	// compute sum(f(i)*i for integer i, min<=i<=max)%MOD
	// assume it's linear over the range
	if(min>max)return 0;
	if(min==max)return fmin%MOD*min%MOD;
	auto const d=fmax-fmin;
	auto const q=d/(max-min),r=d%(max-min);

	// formula from Mathematica :)
	int64_t ans = ((1 + max - min)*((
		3*fmin%MOD*(max + min) + 
		(max + 2LL*max*max - max*(int64_t)min - min*(1LL + min))%MOD*(q%MOD)%MOD)
			%MOD));
	ans=ans%MOD*166374059 /* 1/6 */ %MOD;
	if(ans<0)ans+=MOD;
	return ans;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntree,time;std::cin>>ntree>>time;
	trees.resize(ntree);for(auto& t:trees)std::cin>>t.x>>t.y;
	if(time==0){std::cout<<"0\n";return 0;}

	std::vector<int> splitpts;splitpts.push_back(0);
	// split point x : x | (x+1)
	for(auto t:trees)
		for(auto t2:trees){
			if(t.x==t2.x&&t.y==t2.y)break;
			int dist=std::max(std::abs(t.x-t2.x),std::abs(t.y-t2.y));
			splitpts.push_back(dist/2);
			splitpts.push_back((dist-1)/2);
		}
	std::sort(splitpts.begin(),splitpts.end());
	while(splitpts.back()>time)
		splitpts.pop_back();
	splitpts.push_back(time);
	int64_t ans=0;
	for(unsigned i=1;i<splitpts.size();++i){
#define f ncellwithval
		auto a=splitpts[i-1]+1;
		auto b=splitpts[i];
		ans+=sumfn<decltype(&f),f>(a,b,f(a),f(b));
	}
	std::cout<<ans%MOD<<'\n';
}