// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
#include<utility>
#include<cmath>
#include<random>
#include<cstring>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(long long i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define FOR(i,a) for(auto i:a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define show1d(v) {rep(_,v.size())cout<<" "<<v[_];cout<<endl;}
#define show2d(v) {rep(__,v.size())show1d(v[__]);}
using namespace std;
//kaewasuretyuui
typedef long long ll;
//#define int ll
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
#define mt make_tuple
typedef tuple<int,int,int,int> tp;
typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"

#define MAX 2
#define OFFSET '0'
struct Node{
	int nxt[2]; // alphabete
	int exist; // 
	Node() : exist(0){nxt[0]=nxt[1]=-1;}
};
string m,s;
struct Trie{
	vector<Node>nodes;
	int root;
	Trie() : root(0){nodes.push_back(Node());}

	void update_direct(int node){
		nodes[node].exist++;
	}
	void add(string str){
		int str_index=0,node_index=0;
		while(1){
			if(str_index==str.size()){
				nodes[node_index].exist++;
				break;
			}
			int c=str[str_index]-OFFSET;
			if(nodes[node_index].nxt[c] == -1) {
				nodes[node_index].nxt[c] = (int) nodes.size();
				nodes.push_back(Node());
			}
			nodes[node_index].exist++;
			str_index++;node_index=nodes[node_index].nxt[c];
		}
	}
	int size(){return (nodes[0].exist);}
	int nodesize(){return ((int) nodes.size());}
	
	int get(){
		int now=0,it=0;
		int out=0;

		while(1){
			if(now==-1)break;
			if(it>=s.size()){
				out+=nodes[now].exist;
				break;
			}
			int t=s[it]-'0';
			if(m[it]=='0'&&nodes[now].nxt[t^1]+1)out+=nodes[nodes[now].nxt[t^1]].exist;
			now=nodes[now].nxt[t^(m[it]-'0')],it++;
		}
		return out;
	}
};
string f(int a){
	string s="";
	for(int i=31;i>=0;i--)s+=(char)('0'+(a>>i&1));
	return s;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,M;
	cin>>n>>M;
	m=f(M);
	int t=0;
	ll out=0;
	Trie trie;
	trie.add(f(0));
	rep(i,n){
		int a;cin>>a;
		t^=a;
		s=f(t);
		out+=trie.get();
		trie.add(s);
	}
	cout<<out<<endl;
}