#include<bits/stdc++.h>
#define ll long long
#define N 105
#define M 55

int G,n,m;

std::pair<int,std::vector<int>> A[N];

struct P{
	ll val;
	P(ll x=-1){
		val=x;
	}
};
P operator + (P x,P y){
	if(x.val==-1||y.val==-1)
		return x.val==-1?y:x;
	return P(std::min(x.val,y.val));
}
P operator * (P x,P y){
	if(x.val==-1||y.val==-1)
		return -1;
	return P(x.val+y.val);
}

struct node{
	int fa,ch[2];
	bool ed;
}t[M];
int _t;
inline void init(){
	std::queue<int> q;
	for(int i=0;i<2;i++)
		if(t[0].ch[i])
			q.push(t[0].ch[i]);
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=0;i<2;i++)
			if(t[u].ch[i]){
				t[t[u].ch[i]].fa=t[t[u].fa].ch[i];
				q.push(t[u].ch[i]);
			}
			else
				t[u].ch[i]=t[t[u].fa].ch[i];
	}
	for(int i=0;i<=_t;i++)
		for(int u=i;u;u=t[u].fa)
			t[i].ed|=t[u].ed;
}

struct mtr{
	P a[M][M];
	mtr(ll x=-1){
		for(int i=0;i<=_t;i++)
			for(int j=0;j<=_t;j++)
				a[i][j]=P(i==j?x:-1);
	}
};
mtr operator + (mtr x,mtr y){
	for(int i=0;i<=_t;i++)
		for(int j=0;j<=_t;j++)
			x.a[i][j]=x.a[i][j]+y.a[i][j];
	return x;
}
mtr operator * (mtr x,mtr y){
	mtr res;
	for(int i=0;i<=_t;i++)
		for(int j=0;j<=_t;j++)
			for(int k=0;k<=_t;k++)
				res.a[i][j]=res.a[i][j]+x.a[i][k]*y.a[k][j];
	return res;
}

mtr f[N];

int main(){
	scanf("%d%d%d",&G,&n,&m);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d%d",&A[i].first,&k);
		A[i].second.resize(k);
		for(int j=0;j<k;j++)
			scanf("%d",&A[i].second[j]);
	}
	for(int i=1;i<=m;i++){
		int k;
		scanf("%d",&k);
		int u=0;
		for(int j=0;j<k;j++){
			int c=0;
			scanf("%d",&c);
			if(!t[u].ch[c])
				t[u].ch[c]=++_t;
			u=t[u].ch[c];
		}
		t[u].ed=1;
	}
	init();
	for(int i=0;i<=_t;i++)
		if(!t[i].ed)
			f[0].a[i][t[i].ch[0]]=f[1].a[i][t[i].ch[1]]=P(1);
	for(int _=0;_<50;_++)
		for(int i=1;i<=n;i++){
			auto [a,V]=A[i];
			mtr res(0);
			for(auto b:V)
				res=res*f[b];
			f[a]=f[a]+res;
		}
	for(int i=2;i<G;i++){
		P res;
		for(int j=0;j<=_t;j++)
			if(!t[j].ed)
				res=res+f[i].a[0][j];
		if(res.val==-1)
			puts("YES");
		else
			printf("NO %lld\n",res.val);
	}
}