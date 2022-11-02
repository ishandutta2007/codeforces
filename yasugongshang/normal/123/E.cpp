#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int,int>
#define mp make_pair
inline ll read(){
	bool pos=1; ll x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')pos=0;
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	return pos?x:-x;
}
void write(ll x){
	if(x<0){
		x=-x; putchar('-');
	}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
void writeln(ll x){
	write(x); puts("");
}
const int N=100005;
vector<int> v[N];
int n;
ll ans,dq,x[N],y[N],sz[N],sumx,sumy,dep[N],peo[N];
void dfs(int p,int fa){
	sz[p]=y[p]; peo[p]=1;
	for(unsigned i=0;i<v[p].size();i++)if(v[p][i]!=fa){
		dep[v[p][i]]=dep[p]+1; dfs(v[p][i],p);
		sz[p]+=sz[v[p][i]]; peo[p]+=peo[v[p][i]]; 
	} 
	dq+=y[p]*(n-peo[p]); 
}
void solve(int p,int fa){
	ans+=x[p]*dq; ll zs=dq; //cout<<dq<<" "<<p<<endl;
	for(unsigned i=0;i<v[p].size();i++)if(v[p][i]!=fa){
		dq=zs; //dq+=(sz[1]-sz[v[p][i]])-sz[v[p][i]]; 
		dq-=(n-peo[v[p][i]])*y[v[p][i]]-peo[v[p][i]]*y[p];
		//dq+=(sz[p]-sz[v[p][i]])*((ll)v[v[p][i]].size()-2)-sz[v[p][i]]*((ll)v[p].size()-2);
		solve(v[p][i],p);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	for(int i=1;i<=n;i++){
		x[i]=read(); y[i]=read();
		sumx+=x[i]; sumy+=y[i];
	}
	dfs(1,0);
	solve(1,0); 
	double t=(long double)ans/sumx/sumy;
	printf("%.12lf",t);
}