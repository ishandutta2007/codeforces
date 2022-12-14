#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

map<string,int> mp;

struct node{
	int id;
	int r;
	int len;
	node(){}
	node(int a,int b,int c):id(a),r(b),len(c){}
};

vector<node> nodes;
int rev[300300];

bool cmp(const node &n1,const node &n2){
	if(n1.r!=n2.r) return n1.r<n2.r;
	if(n1.len!=n2.len) return n1.len<n2.len;
	return n1.id<n2.id;
}

vector<int> rG[300300];
int best[300300];

void bfs(int v){
	queue<int> que;
	que.push(v);
	best[v]=v;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int i=0;i<rG[u].size();i++){
			int nv=rG[u][i];
			if(best[nv]!=-1) continue;
			best[nv]=v;
			que.push(nv);
		}
	}
}

vector<int> ini;

string tolower(string str){
	for(int i=0;i<str.size();i++){
		if('A'<=str[i]&&str[i]<='Z'){
			str[i]-='A';
			str[i]+='a';
		}
	}
	return str;
}

int main(){
	int N,M;
	cin>>M;
	for(int i=0;i<M;i++){
		string str;
		cin>>str;
		str=tolower(str);
		if(mp.count(str)!=0){
			ini.push_back(mp[str]);
		}else{
			int n=mp.size();
			mp[str]=n;
			ini.push_back(n);
		}
	}
	cin>>N;
	for(int i=0;i<N;i++){
		string from,to;
		cin>>from;
		from=tolower(from);
		if(mp.count(from)==0){
			int n=mp.size();
			mp[from]=n;
		}
		cin>>to;
		to=tolower(to);
		if(mp.count(to)==0){
			int n=mp.size();
			mp[to]=n;
		}
		if(from==to) continue;
		rG[mp[to]].push_back(mp[from]);
	}
	map<string,int>::iterator it=mp.begin();
	for(;it!=mp.end();it++){
		string str=it->first;
		int id=it->second;
		int ln=str.size();
		int r=0;
		for(int i=0;i<ln;i++) if(str[i]=='r'||str[i]=='R') r++;
		nodes.push_back(node(id,r,ln));
	}
	sort(nodes.begin(),nodes.end(),cmp);
	for(int i=0;i<nodes.size();i++) rev[nodes[i].id]=i;
	for(int i=0;i<nodes.size();i++) best[i]=-1;
	for(int i=0;i<nodes.size();i++){
		int id=nodes[i].id;
		if(best[id]!=-1) continue;
		bfs(id);
	}
	long long ansL=0,ansR=0;
	for(int i=0;i<ini.size();i++){
		int id=ini[i];
		int to=best[id];
		to=rev[to];
		ansR+=nodes[to].r;
		ansL+=nodes[to].len;
	}
	cout<<ansR<<" "<<ansL<<"\n";
	return 0;
}