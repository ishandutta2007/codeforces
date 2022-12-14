// TODO is there an easier way to implement (without 5 DFS functions)?
// Total impl time: approx 45+25 min

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct linearfn{
	int64_t a,b;
	int64_t operator()(int64_t x)const{ return a*x+b; }
	linearfn operator+(linearfn x)const{ return {a+x.a,b+x.b}; }
	linearfn operator-(linearfn x)const{ return {a-x.a,b-x.b}; }
	linearfn slice(int64_t x)const{
		// (*this)(x+d) = this->slice(x)(d)
		return {a,a*x+b};
	}
};


struct edge{
	int node;
	linearfn len;
};
std::vector<std::vector<edge>> ad;

void addfakenode(int node){
	for(auto [child,len]:ad[node]){
		ad[child].erase(std::find_if(begin(ad[child]),end(ad[child]),
					[&](edge e){ return e.node==node; }));
		addfakenode(child);
	}
	while(ad[node].size()>2){
		auto edge1=ad[node].back();ad[node].pop_back();
		auto edge2=ad[node].back();
		auto newn=(int)ad.size();
		ad[node].back()={newn,0};
		ad.push_back({edge1,edge2});
	}
}

void restoreparedge(int node){
	for(auto [child,len]:ad[node]){
		restoreparedge(child);
		ad[child].push_back({node,len});
	}
}

std::vector<int> stsize;

int cpustsize(int node,int par=-1){
	stsize[node]=1;
	for(auto [child,len]:ad[node])if(child!=par){
		stsize[node]+=cpustsize(child,node);
	}
	return stsize[node];
}

int curcompsize;
int curmin;
std::pair<int,int> curedgecentroid;

void findedgecentroid_impl(int node,int par=-1){
	for(auto [child,len]:ad[node])if(child!=par){
		assert(stsize[child]>0);
		auto curval=std::max(stsize[child],curcompsize-stsize[child]);
		if(curval<curmin){ curmin=curval; curedgecentroid={node,child}; }
		findedgecentroid_impl(child,node);
	}
}
auto findedgecentroid(int node){
	curcompsize=cpustsize(node);
	assert(curcompsize>1);
	curmin=curcompsize+1;
	findedgecentroid_impl(node);
	assert(curmin<curcompsize+1);
	return curedgecentroid;
}

std::vector<linearfn> maxdists;

void findmaxdists(int node,int par=-1,linearfn dist={}){
	bool isleaf=true;
	for(auto [child,len]:ad[node])if(child!=par){
		isleaf=false;
		auto curval=std::max(stsize[child],curcompsize-stsize[child]);
		if(curval<curmin){ curmin=curval; curedgecentroid={node,child}; }
		findmaxdists(child,node,dist+len);
	}

	if(isleaf){ // requires all edge lengths are >= 0
		maxdists.push_back(dist);
		return;
	}
}

struct linearfnseg{
	linearfn val;
	int64_t startx;
};
using piecewiselinearfn=std::vector<linearfnseg>;
piecewiselinearfn max(std::vector<linearfn> fns){
	assert(not fns.empty());

	std::sort(begin(fns),end(fns),[](auto p,auto q){ return p.a!=q.a ? p.a<q.a : p.b>q.b; });
	fns.erase(
			std::unique(begin(fns),end(fns),[](auto p,auto q){ return p.a==q.a; }),
			end(fns));
	piecewiselinearfn out;
	for(linearfn f:fns){
		auto const [a2,b2]=f;
		while(not out.empty() and out.back().val.b<=f.b)
			out.pop_back();
		if(out.empty()){
			out.push_back({f,0});
			continue;
		}
		while(true){
			auto [a1,b1]=out.back().val;
			assert(b1-b2>=0 and a2-a1>0);
			auto const startx=(b1-b2)/(a2-a1)+1;
			if(startx<=out.back().startx)
				out.pop_back();
			else{
				out.push_back({f,startx});
				break;
			}
		}
	}
	return out;
}

piecewiselinearfn add(piecewiselinearfn f,piecewiselinearfn g){
	assert(not f.empty() and f[0].startx==0);
	assert(not g.empty() and g[0].startx==0);
	piecewiselinearfn out;out.reserve(f.size()+g.size());

	auto iter1=begin(f),iter2=begin(g);
	auto last1=iter1->val,last2=iter2->val;
	++iter1;++iter2;
	out.push_back({last1+last2,f[0].startx});
	while(iter1!=end(f) or iter2!=end(g)){
		int64_t startx;
		if(iter1!=end(f) and (iter2==end(g) or iter1->startx<iter2->startx)){
			last1=iter1->val;
			startx=iter1->startx;
			++iter1;
		}else{
			last2=iter2->val;
			startx=iter2->startx;
			++iter2;
		} // NOTE is this correct in the == case?

		assert(startx>=out.back().startx);
		if(startx==out.back().startx) out.pop_back();
		out.push_back({last1+last2,startx});
	}
	return out;
}

std::vector<linearfn> allfs;
void solve(int node){
	if(ad[node].empty()) return;
	auto [a,b]=findedgecentroid(node);
	linearfn edgecentroidlen;
	{
		auto iter=std::find_if(begin(ad[a]),end(ad[a]),[&](edge e){ return e.node==b; });
		edgecentroidlen=iter->len;
		ad[a].erase(iter);
		ad[b].erase(std::find_if(begin(ad[b]),end(ad[b]),[&](edge e){ return e.node==a; }));
	}

	maxdists.clear();
	findmaxdists(a);
	auto f1=max(std::move(maxdists));

	maxdists.clear();
	findmaxdists(b);
	auto f2=max(std::move(maxdists));

	f1=add(std::move(f1),std::move(f2));
	
	if (allfs.size()+f1.size()>allfs.capacity())
		allfs.reserve(allfs.capacity()*2);
	allfs.resize(allfs.size()+f1.size());
	std::transform(begin(f1),end(f1),end(allfs)-f1.size(),[&](auto seg){
		return seg.val+edgecentroidlen;
	});

	solve(a);
	solve(b);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnode,time;std::cin>>nnode>>time;

	if(nnode==1){
		for(int t=0;t<time;++t)std::cout<<"0 ";
		std::cout<<'\n';
		return 0;
	}

	ad.resize(nnode);
	for(int z=nnode;--z;){
		int u,v,a,b;std::cin>>u>>v>>a>>b;
		--u;--v;
		ad[u].push_back({v,{a,b}});
		ad[v].push_back({u,{a,b}});
		assert(a>=0 and b>=0);
	}

	nnode=-1;
	addfakenode(0);
	restoreparedge(0);

	stsize.resize(ad.size());
	allfs.clear();
	solve(0);

	auto tmp=max(allfs);
	tmp.push_back({{},time /* Infinity */});
	auto iter=begin(tmp);
	for(int t=0;t<time;++t){
		while(iter[1].startx<=t) ++iter;
		std::cout<<iter->val(t)<<' ';
	}
	std::cout<<'\n';
}