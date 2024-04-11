#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=605;
int n,tong[N],q[N];
map<vector<int>,int> M;
int ask(vector<int> v){
	if(v.size()==0)return 0;
	if(M.count(v))return M[v];
	cout<<"? "<<v.size()<<endl;
	for(auto i:v)wri(i); cout<<endl;
	return M[v]=read();
}
int ask(int p,vector<int> v){
	int t=ask(v); v.push_back(p); return ask(v)-t;
}
vector<int> v[2];
int cal(int p){
	int tot=0;
	vector<int> v;
	for(int i=1;i<=n;i++)if(tong[i])v.push_back(q[++tot]=i); 
	int jb=ask(p,v);
	if(jb==0)return 0;
	int l=1,r=tot;
	while(l<r){
		int mid=(l+r)>>1;
		v.clear(); for(int j=l;j<=mid;j++)v.push_back(q[j]);
		if(ask(p,v))r=mid; else l=mid+1;
	}
	tong[q[l]]=0;
	return q[l];
}
int father[N];
void dfs(int p,int dep){
	v[dep].push_back(p); //cout<<p<<" "<<tong[p]<<endl;
	while(1){int t=cal(p); father[t]=p;
	//cout<<p<<" wzp "<<t<<endl;
	if(t)dfs(t,dep^1); else return;}
}
int vis[N];
int qiu(int a,int b){
	vector<int> ans1,ans2;
	for(int i=a;i;i=father[i])vis[i]=1;
	for(int i=b;i;i=father[i])if(vis[i]){
		for(int j=a;;j=father[j]){ans1.push_back(j); if(j==i)break;}
		for(int j=b;j!=i;j=father[j]){ans2.push_back(j);}
		reverse(ans2.begin(),ans2.end());
		cout<<"N "<<ans1.size()+ans2.size()<<endl;
		for(auto i:ans1)wri(i);
		for(auto i:ans2)wri(i); cout<<endl;
	}
}
void find(vector<int> v){
	if(v.size()==2){
		qiu(v[0],v[1]); exit(0);
	}else{
		while(1){
			random_shuffle(v.begin(),v.end());
			int mid=(v.size()+1)/2;
			vector<int> vv=v;
			vv.resize(mid);
			if(ask(vv)){find(vv); return;}
		}
		
	}
}
int main(){
	n=read();
	for(int i=2;i<=n;i++)tong[i]=1;
	dfs(1,0);
	if(ask(v[0])){
		find(v[0]);
	}else if(ask(v[1])){
		find(v[1]);
	}else {cout<<"Y "<<v[0].size()<<endl; for(auto i:v[0])wri(i); cout<<endl;}
}