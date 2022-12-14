#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

std::vector<int> a;
std::vector<int> pre,nxt;

struct Counter:std::unordered_map<int,int>{
	void inc(int x){
		++(*this)[x];
	}
	void dec(int x){
		auto iter=this->find(x);
		if(0==--iter->second)
			this->erase(iter);
	}
};


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	a.resize(n);
	for(int& x:a)std::cin>>x;
	int const old_n=n;
	n=-1;
	a.erase(std::unique(begin(a),end(a)),end(a));

	pre.resize(a.size());
	nxt.resize(a.size(),a.size());
	{
		std::unordered_map<int,int> last;
		for(unsigned i=0;i<a.size();++i){
			auto iter=last.find(a[i]);
			if(iter==end(last)){
				pre[i]=-1;
				last.insert({a[i],i});
			}else{
				pre[i]=iter->second;
				nxt[pre[i]]=i;
				iter->second=i;
			}
		}
	}

	struct Range{
		int l,r;
	private:
		int size_;
	public:
		Range():size_{}{}
		int size()const{return size_;}
		void clear(){l=r=size_=0;}
		bool have_new_r()const{
			return pre[r]<l;
		}
		void incr(){
			if(have_new_r())
				++size_;
			++r;
		}
		void incl(){
			if(nxt[l]>=r)
				--size_;
			++l;
		}
	};

	std::vector<Range> t(a.size());
	for(unsigned i=0;i<a.size();++i){
		t[i].l=i;
		t[i].r=i;
		t[i].incr();
	}
	for(int i=1;;){
		std::cout<<t.size()<<' ';
		if(i==old_n)
			break;

		++i;
		for(unsigned j=0;;++j){
			auto& x=t[j];
			while(true){
				if(x.r==(int)a.size()){
					t.erase(begin(t)+j+1,end(t)); // invalidates x
					goto break_outer;
				}
				if((int)x.size()==i&&x.have_new_r())
					break;
				x.incr();
			}

			auto& y=t[j+1];
			if(x.r>=y.r){
				y.clear();
				y.l=y.r=x.r;
			}else{
				while(y.l<x.r)
					y.incl();
			}
		}
break_outer:;
	}
	std::cout<<'\n';
}