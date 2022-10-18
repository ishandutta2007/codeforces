#include<cstdio>
#include<algorithm>
#include<vector>
#define N 200005

int n,a[N<<1][2];

int pos[2][N],e[N<<1][2];

std::vector<int> ver;
bool del[N<<1];

struct node{
	node *pre,*suf;
	int val[2];
	
	node(int v0=0,int v1=0){
		pre=suf=0;
		val[0]=v0,val[1]=v1;
	}
};
struct edge{
	node *st,*ed;
	
	edge(node *st_=0,node *ed_=0){
		st=st_,ed=ed_;
	}
	
	inline void wr(){
		for(node *u=st;u;u=u->suf)
			printf("%d %d\n",u->val[0],u->val[1]);
	}
};
edge operator + (edge x,edge y){
	if(!x.st&&!x.ed)
		return y;
	x.ed->suf=y.st;
	y.st->pre=x.ed;
	return edge(x.st,y.ed);
}

node b[N<<1];
edge l[N<<1],ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n+n;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
		for(int o=0;o<2;o++)
			if(a[i][o]>0)
				pos[o][a[i][o]]=i;
		if((a[i][0]<0)+(a[i][1]<0)==1)
			ver.push_back(i);
		b[i]=node(a[i][0],a[i][1]);
		l[i]=edge(&b[i],&b[i]);
	}
	for(int i=1;i<=n+n;i++)
		for(int o=0;o<2;o++)
			if(a[i][o]<0){
				e[i][o]=pos[o][-a[i][o]];
				e[pos[o][-a[i][o]]][o]=i;
			}
	while(ver.size()){
		int u=ver.back();
		ver.pop_back();
		if(del[u])
			continue;
		if(e[u][0]==e[u][1]){
			puts("NO");
			return 0;
		}
		int te[2],ta[2];
		for(int o=0;o<2;o++){
			int v=e[u][o];
			del[v]=1;
			if(a[u][o]<0)
				l[u]=l[v]+l[u];
			else
				l[u]=l[u]+l[v];
			ta[o^1]=a[v][o^1];
			e[e[v][o^1]][o^1]=u;
			te[o^1]=e[v][o^1];
		}
		for(int o=0;o<2;o++){
			a[u][o]=ta[o];
			e[u][o]=te[o];
		}
		if((a[u][0]<0)+(a[u][1]<0)==1)
			ver.push_back(u);
	}
	for(int i=1;i<=n+n;i++)
		if(!del[i]&&a[i][0]<0){
			if(e[i][0]!=e[i][1]){
				puts("NO");
				return 0;
			}
			ans=ans+l[e[i][0]];
			ans=ans+l[i];
		}
	puts("YES");
	ans.wr();
}