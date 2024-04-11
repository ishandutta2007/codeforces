#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=100005,inf=1e9;
int n,m,k,c[N],ans[N],mx[3],mn[3],lim[3];
struct d1{
	int x[3],id;
}a[N],b[N];
vector<d1> v,q;
#define lowbit(i) i&-i
inline void change(int pos,int de){
	for(int i=pos+1;i<N;i+=lowbit(i))c[i]=min(c[i],de);
}
inline int ask(int pos){
	int ans=inf;
	for(int i=pos+1;i;i-=lowbit(i))ans=min(ans,c[i]);
	return ans;
}
bool check(){
	for(int i=1;i<=m;i++){
		int flag=1;
		for(int j=0;j<3;j++)if(mx[j]<a[i].x[j]||mn[j]>a[i].x[j])flag=0;
		if(flag)return 0;
	}
	return 1;
}
inline bool cmp(d1 a,d1 b){
	return a.x[0]<b.x[0];
}
signed main(){
	for(int i=0;i<3;i++){
		lim[i]=read();
		mx[i]=1; mn[i]=lim[i];
	}
	n=read(); m=read(); k=read();
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			int t=read();
			mx[j]=max(mx[j],t); mn[j]=min(mn[j],t);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<3;j++)a[i].x[j]=read();
	}
	if(!check()){
		puts("INCORRECT"); return 0;
	}else puts("CORRECT");
	for(int i=1;i<=k;i++){
		int flag=1;
		for(int j=0;j<3;j++)b[i].x[j]=read();
		for(int j=0;j<3;j++){
			if(mx[j]<b[i].x[j]||mn[j]>b[i].x[j])flag=0;
		}
		if(!flag)ans[i]=2;
	}
	int i[3];
	for(i[0]=0;i[0]<2;i[0]++){
		for(i[1]=0;i[1]<2;i[1]++){
			for(i[2]=0;i[2]<2;i[2]++){
				v.clear();
				for(int l=1;l<=m;l++){
					int flag=0;
					for(int j=0;j<3;j++)if((i[j]&&a[l].x[j]<mn[j])||(!i[j]&&a[l].x[j]>mx[j]))flag=1;
					if(flag)continue;
					d1 t;
					for(int j=0;j<3;j++)t.x[j]=i[j]?max(a[l].x[j]-mx[j],0):max(mn[j]-a[l].x[j],0);
					v.push_back(t);
				}
				q.clear();
				for(int l=1;l<=k;l++)if((ans[l]&1)==0&&(ans[l]>=2)){
					int flag=0;
					for(int j=0;j<3;j++)if((i[j]&&b[l].x[j]<mx[j])||(!i[j]&&b[l].x[j]>mx[j]))flag=1;
					if(flag)continue;
					d1 t; t.id=l; //if(l==2)cout<<b[l].x[1]-mx[1]<<endl;
					for(int j=0;j<3;j++)t.x[j]=i[j]?max(b[l].x[j]-mx[j],0):max(mn[j]-b[l].x[j],0);
					q.push_back(t);
				}
				sort(v.begin(),v.end(),cmp); sort(q.begin(),q.end(),cmp);
				unsigned l=0;
				for(int i=1;i<N;i++)c[i]=inf;
				for(unsigned j=0;j<q.size();j++){
					while(l<v.size()&&v[l].x[0]<=q[j].x[0]){
						//cout<<v[l].x[1]<<" "<<v[l].x[2]<<endl;
						change(v[l].x[1],v[l].x[2]); l++;
					}
					//if(v.size())cout<<q[j].x[0]<<" "<<q[j].x[1]<<" "<<q[j].x[2]<<" "<<l<<" "<<ask(q[j].x[1])<<endl;
					ans[q[j].id]|=ask(q[j].x[1])<=q[j].x[2];
				}
			}
		}
	}
	for(int i=1;i<=k;i++){
		ans[i]^=1;
		if(ans[i]==3)puts("UNKNOWN"); else if(ans[i]==1)puts("OPEN"); else puts("CLOSED");
	}
}