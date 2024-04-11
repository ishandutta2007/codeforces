#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

typedef int LL;

const int maxn = 1000;
const LL INF = 0x7fffffff;

int p[maxn+7],fp[11];
int cnt,p_num;
bool v[maxn+7];

void make_list(){
	memset(v,1,sizeof(v));
	for (int i=2;i<=maxn;++i){
		if (!v[i]){
			continue;
		}
		p[cnt++]=i;
		for (int j=2;i*j<=maxn;++j){
			v[i*j]=0;
		}
	}
}

LL dfs(LL u,int dep,int fl){
	if (dep==p_num){
		LL ans=u;
		int sz=0;
		for (int i=p_num-1;i>-1;--i){
			if (fl&1){
				ans/=fp[i];
				sz++;
			}
			fl>>=1;
		}
		if(sz%2){
			return -ans;
		}
		else{
			return ans;
		}
	}
	return dfs(u,dep+1,fl<<1)+dfs(u,dep+1,fl<<1|1);
}

LL numbers(LL u,int v){
	p_num=0;
	int pt=0;
	while(v>1&&pt<cnt){
		if (v%p[pt]==0){
			fp[p_num++]=p[pt];
			while(v%p[pt]==0){
				v/=p[pt];
			}
		}
		pt++; 
	}
	if (v>1){
		fp[p_num++]=v;
	}
	return dfs(u,0,0);
}

LL find_ans(LL lt,LL rt,int v,LL gl){
	if (lt==rt){
		return lt;
	}
	LL md=(lt+rt)>>1;
	if (numbers(md,v)<gl){
		return find_ans(md+1,rt,v,gl);
	}
	else{
		return find_ans(lt,md,v,gl);
	}
}
int main(){
	make_list();
	int t;
	scanf("%d",&t);
	while(t--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		printf("%d\n",find_ans(1,INF,v,numbers(u,v)+w));
	}
	return 0;
}