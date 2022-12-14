#include<iostream>
#include<vector>
#include<deque>
#include<cassert>

struct shelf{
	int size,count_noinvert;
	bool invert;
	std::vector<bool> has_book;

	shelf(int size):size(size),count_noinvert(),invert(false),has_book(size){}
	bool set(int index,bool val){
		// return the original value
		val^=invert;
		bool prev_val=has_book[index];
		has_book[index]=val;
		count_noinvert+=val-prev_val;
		return prev_val^invert;
	}
	void flip(){
		invert^=true;
	}
	int count()const{
		return invert?size-count_noinvert:count_noinvert;
	}
};

struct query{
	char type; // '1' .. '4'
	int a,b; // parameters
};

struct bookcase{
	std::vector<shelf> data;
	int count;
	void reset(int n,int m){
		count=0;
		data.assign(n,m);
	}
	query apply(query q){
		// return the reverse query
		count-=data[q.a].count();
		query inv=q;
		switch(q.type){
		case '1':
			inv.type=data[q.a].set(q.b,true)?'1':'2';
			break;
		case '2':
			inv.type=data[q.a].set(q.b,false)?'1':'2';
			break;
		case '3':
			data[q.a].flip();
			break;
		}
		count+=data[q.a].count();
		return inv;
	}
};

std::istream& operator>>(std::istream& stream,query& q){
	stream>>q.type;
	switch(q.type){
	case '1':
	case '2':
		stream>>q.a>>q.b;
		--q.a;--q.b;
		break;
	case '3':
		stream>>q.a;
		--q.a;
		break;
	case '4':
		stream>>q.a;
		break;
	}
	return stream;
}

// global state
struct state;
// std::vector<state> states;
bookcase bc;

struct state;
struct state_edge;
struct state{
	// bookcase state
	int index,answer;
	std::deque<state_edge> edges; // avoid ptr invalidation
	state(int index):index(index),answer(-1){}
	state(state&)=delete;
	state(state&&)=default;

	void solve();
	state* add_edge(query q,int i);
};
struct state_edge{
	state next;
	query q;
};

void state::solve(){
	answer=bc.count;
	for(state_edge& e:edges){
		query inv=bc.apply(e.q);
		e.next.solve();
		bc.apply(inv);
	}
}

state* state::add_edge(query q,int i){
	edges.push_back({state(i),q});
	return &edges.back().next;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	state root(0);

	int n,m,nquery;std::cin>>n>>m>>nquery;
	bc.reset(n,m);
	std::vector<state*> states(nquery+1);
	states[0]=&root;
	for(int i=1;i<=nquery;++i){
		query q;std::cin>>q;
		if(q.type=='4')
			states[i]=states[q.a];
		else
			states[i]=states[i-1]->add_edge(q,i);
	}

	root.solve();
	for(int i=1;i<=nquery;++i){
		assert(states[i]->answer>=0);
		std::cout<<states[i]->answer<<'\n';
	}
}