#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int n,m,cnt;
map<pair<int,int>,bool> is;
set<int> s;
inline void dfs(int x){
	vector<int> v;v.clear();set<int> tmp;
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		if(!is[make_pair(x,*it)])
			v.push_back(*it);
		else
			tmp.insert(*it);
	}
	s=tmp;
	for(int i=0;i<v.size();i++)	dfs(v[i]);
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)	s.insert(i);
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		is[{u,v}]=1;
		is[{v,u}]=1;
	}
	while(!s.empty()){
		cnt++;
		int x=*s.begin();
		s.erase(s.find(x));
		dfs(x);
	}
	print(cnt-1);
	return 0;
}