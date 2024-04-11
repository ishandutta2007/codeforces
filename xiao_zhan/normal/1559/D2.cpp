#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m1,m2,t,fa[105000],fa2[105000],siz[100500],siz2[100500],res;
int find(int *fa,int x){
	return (fa[x]==x)?x:fa[x]=find(fa,fa[x]);
}
vector<pair<int,int> >v;

bool chk(int x,int y){
	if(find(fa,x)==find(fa,y)){
		return 0;
	}
	if(find(fa2,x)==find(fa2,y)){
		return 0;
	}
	return 1;
}

int chk2(int x,int y){
	if(find(fa,x)==find(fa,y)){
		return 1;
	}
	return 2;
}

struct sb{
	int id,w;
	bool operator<(const sb x)const{return w>x.w;}
};
priority_queue<struct sb> q1,q2;

void add1(int x,int y){
	int xx,yy;
	xx=find(fa,x);yy=find(fa,y);
	siz[fa[yy]]+=siz[fa[xx]];
	fa[fa[xx]]=fa[yy];
	q1.push({fa[yy],siz[fa[yy]]});
}

void add2(int x,int y){
	int xx,yy;
	xx=find(fa2,x);yy=find(fa2,y);
	siz2[fa2[yy]]+=siz2[fa2[xx]];
	fa2[fa2[xx]]=fa2[yy];
	q2.push({fa2[yy],siz2[fa2[yy]]});
}

int main(){
	for(i=1;i<=100005;i++){
		fa[i]=i;fa2[i]=i;
		siz[i]=1;
		siz2[i]=1;
	}
	scanf("%d%d%d",&n,&m1,&m2);
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	uniform_int_distribution<int>lim(1,n);
	for(i=1;i<=n;i++){
		q1.push({i,1});
		q2.push({i,1});
	}
	for(i=1;i<=m1;i++){
		scanf("%d%d",&j,&k);
		add1(j,k);
	}
	for(i=1;i<=m2;i++){
		scanf("%d%d",&j,&k);
		add2(j,k);
	}
	res=n-1-max(m1,m2);
	printf("%d\n",res);
	while(res--){
		int x,y,xx,yy;
		while(1){
			x=q1.top().id;
			y=q1.top().w;
			if(siz[find(fa,x)]!=y){
				q1.pop();
			}
			else{
				break;
			}
		}
		while(1){
			xx=q2.top().id;
			yy=q2.top().w;
			if(siz2[find(fa2,xx)]!=yy){
				q2.pop();
			}
			else{
				break;
			}
		}
		if(chk(x,xx)){
			printf("%d %d\n",x,xx);
			add1(x,xx);
			add2(x,xx);
			continue;
		}
		if(chk2(x,xx)==2){
			while(1){
				y=lim(rng);
				if(chk(x,y)){
					printf("%d %d\n",x,y);
					add1(x,y);
					add2(x,y);
					break;
				}
			}
		}
		else{
			while(1){
				y=lim(rng);
				if(chk(xx,y)){
					printf("%d %d\n",xx,y);
					add1(xx,y);
					add2(xx,y);
					break;
				}
			}
		}
	}
}