#include<cstdio>
#include<algorithm>
#include<bitset>
#define N 1005

int n;

std::bitset<N> s[N],t[N];

int cnt;
bool flg[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		while(k--){
			int j;
			scanf("%d",&j);
			s[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			std::bitset<N> tmp=s[i]&s[j];
			if(tmp.count()!=2)
				continue;
			int u=tmp._Find_first(),v=tmp._Find_next(u);
			if(t[u][v])
				continue;
			printf("%d %d\n",u,v);
			cnt++;
			t[u][v]=t[v][u]=t[u][u]=t[v][v]=1;
			flg[u]=flg[v]=1;
		}
	if(!cnt){
		for(int i=2;i<=n;i++)
			printf("1 %d\n",i);
		return 0;
	}
	if(cnt==1){
		for(int u=1;u<=n;u++)
			for(int v=u+1;v<=n;v++)
				if(t[u][v])
					for(int i=1;i<=n;i++)
						if(s[i].count()!=n){
							for(int w=1;w<=n;w++)
							if(w!=u&&w!=v)
								printf("%d %d\n",s[i][w]?u:v,w);
							break;
						}
		return 0;
	}
	for(int u=1;u<=n;u++)
		if(!flg[u]){
			std::bitset<N> tmp;
			for(int i=1;i<=n;i++)
				tmp[i]=1;
			for(int i=1;i<=n;i++)
				if(s[i][u]&&s[i].count()<tmp.count())
					tmp=s[i];
			for(int i=1;i<=n;i++)
				if(!flg[i])
					tmp[i]=0;
			for(int v=1;v<=n;v++)
				if(flg[v]&&tmp==t[v]){
					printf("%d %d\n",u,v);
					break;
				}
		}
}