#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

const int N = 100010;



int bcj[N];

map<int,int> conn[N];
set<int> cone[N];
set<int>::iterator it;
int fnd(int x){
	return bcj[x] == x?x:bcj[x] = fnd(bcj[x]);
}
void uni(int x,int y){
	if(fnd(x)==fnd(y))return;
	int obj1 = fnd(x),obj2 = fnd(y);
	if(cone[obj1].size()>cone[obj2].size())swap(obj1,obj2);
	for(it = cone[obj1].begin();it!=cone[obj1].end();it++) cone[obj2].insert(*it);
	cone[obj1].clear();
	bcj[obj1] = obj2;
}
int n,m,c,q;
void add(){
	int u,v,co;
	read(u);read(v);read(co);
	cone[fnd(u)].insert(v);
	cone[fnd(v)].insert(u);
	if(conn[u][co]) uni(conn[u][co],v);
	else conn[u][co] = v;
	if(conn[v][co]) uni(conn[v][co],u);
	else conn[v][co] = u;
}
void query(){
	int u,v;
	read(u);read(v);
	if(fnd(u) == fnd(v) || cone[fnd(u)].count(v)){
		cout<<"Yes\n";
	}else cout<<"No\n";
}
char op;
int main() {
	for(int i=0;i<N;i++){
		bcj[i] = i;
	}
	read(n);read(m);read(c);read(q);
	for(int i=0;i<m;i++){
		add();
	}
	for(int i=0;i<q;i++){
		cin>>op;
		if(op == '+'){
			add();
		}else{
			query();
		}
	}
	return 0;
}