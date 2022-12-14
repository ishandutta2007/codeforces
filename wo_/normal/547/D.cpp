#include<cstdio>
#include<set>
#include<utility>
#include<cassert>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

const int MA=200000;

int xs[200200],ys[200200];

set<int> odd;
set<int> to[400400];
set<int> nonzero;

struct P:pair<int,int>{
	P(int a,int b){
		if(a>b) swap(a,b);
		this->first=a,this->second=b;
	}
};

map<P,int> ans;
int cnt[400400];

int N;

void flip(int x){
	if(odd.find(x)==odd.end()){
		odd.insert(x);
	}
	else odd.erase(x);
}

vector<P> vec;

void er(int u,int v){
	to[u].erase(v);
	to[v].erase(u);
	flip(u);
	flip(v);
	if(to[u].empty()) nonzero.erase(u);
	if(to[v].empty()) nonzero.erase(v);
}

P get(){
	if(!odd.empty()){
		int v=*odd.begin();
		int u=*to[v].begin();
		er(u,v);
		return P(u,v);
	}else{
		int v=*nonzero.begin();
		int u=*to[v].begin();
		er(u,v);
		return P(u,v);
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",xs+i,ys+i);
		xs[i]--;ys[i]--;
	}
	for(int i=0;i<N;i++){
		int x=xs[i];
		int y=ys[i]+MA;
		to[x].insert(y);
		to[y].insert(x);
		nonzero.insert(x);
		nonzero.insert(y);
		flip(x);
		flip(y);
	}
	for(int i=0;i<N;i++){
		P p=get();
		vec.push_back(p);
	}
	for(int i=N-1;i>=0;i--){
		P p=vec[i];
		int u=p.first;
		int v=p.second;
		int cur;
		if(cnt[u]>0||cnt[v]>0) cur=-1;
		else cur=1;
		ans[p]=cur;
		cnt[u]+=cur;
		cnt[v]+=cur;
	}
	for(int i=0;i<N;i++){
		P p=P(xs[i],ys[i]+MA);
		int cur=ans[p];
		char ch=cur==1?'b':'r';
		printf("%c",ch);
	}
	printf("\n");
	return 0;
}