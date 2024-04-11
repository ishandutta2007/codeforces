#include"bits/stdc++.h"
#define F(i,l,r) for(register int i=l;i<=r;i++)
#define D(i,r,l) for(register int i=r;i>=l;i--)
using namespace std;
namespace IO{
	#define gch getchar()
	template<class mi>inline void readi(mi&x){
		x=0;int f=1;char ch=gch;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gch;}
		while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=gch;x*=f;	
	}inline void readC(char&x){do x=gch;while(x!='t'&&x!='x');}
} ;
using namespace IO;
typedef long long ll;
const int N=100005;
int n,a[N],b[N],c[N],ans,id1,id2;
struct node {
	int x,y;
	node (int _=0,int __=0){
		x=min(_,__),y=_+__-x;
	}
	bool operator ==(node a){
		return x==a.x&&y==a.y;
	}
} ;
bool operator <(node a,node b){
	return a.y==b.y?a.x<b.x:a.y<b.y;
}
#define mp make_pair
#define mmap map< node,pair<node,node> > ::iterator
map <node,pair<node,node> > sr;
void ins(node x,node y){
	mmap i=sr.find(x);
	if(i==sr.end())
		sr.insert(mp(x,mp(y,node(0,0))));
	else{
		if(i->second.first < y)
			i->second.second=i->second.first,i->second.first=y;
		else if(i->second.second < y&&y.x!=i->second.first.x)
			i->second.second=y;
	}
}
int main(){
	readi(n);
	F(i,1,n){
		readi(a[i]),readi(b[i]),readi(c[i]);
		if(min(min(a[i],b[i]),c[i])>ans)
			ans=min(min(a[i],b[i]),c[i]),id1=i;
		ins(node(a[i],b[i]),node(c[i],-i));
		ins(node(a[i],c[i]),node(b[i],-i));
		ins(node(b[i],c[i]),node(a[i],-i));
	}
	for(mmap p=sr.begin();p!=sr.end();p++){
		int dx=min(p->first.x,p->second.first.y+p->second.second.y); 
		if(dx>ans)ans=dx,id1=-p->second.first.x,id2=-p->second.second.x;
	}
	if(id2) printf("2\n%d %d\n",id1,id2);
	else printf("1\n%d",id1);
	return 0;
}