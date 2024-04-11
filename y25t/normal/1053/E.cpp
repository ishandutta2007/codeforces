#include<cstdio>
#include<algorithm>
#include<vector>
#define N 500005

int n,a[N<<1];

int nxt[N<<1],pre[N<<1];
inline void init(){
	for(int i=1;i<=2*n-1;i++){
		nxt[i]=i+1;
		pre[i]=i-1;
	}
	pre[2*n]=2*n-1;
	nxt[2*n]=2*n;
	pre[0]=0;
	nxt[0]=1;
}
inline void del(int x,int y){
	nxt[pre[x]]=nxt[y];
	pre[nxt[y]]=pre[x];
}

bool vis[N];
std::vector<int> id;

int lst[N];
inline bool sol(int L,int R){
	if((R-L+1)%2==0)
		return 0;
	int cnt=0;
	for(int i=L;i<=R;i=nxt[i])
		if(a[i]){
			if(lst[a[i]]&&i!=lst[a[i]]){
				if(i==R&&lst[a[i]]==L)
					break;
				if(lst[a[i]]<L)
					return 0;
				if(!sol(lst[a[i]],i))
					return 0;
				del(lst[a[i]]+1,i);
			}
			else if(!lst[a[i]]){
				cnt++;
				lst[a[i]]=i;
			}
		}
	int len=0;
	for(int i=L;i<=R;i=nxt[i])
		len++;
	cnt=0;
	for(int i=L;i<=R;i=nxt[i])
		vis[a[i]]=0;
	for(int i=L;i<=R;i=nxt[i])
		if(a[i]&&!vis[a[i]]){
			vis[a[i]]=1;
			cnt++;
		}
	if(cnt*2-1>len)
		return 0;
	if(a[L]&&a[R]&&a[L]!=a[R])
		return 0;
	a[L]=a[R]=a[L]|a[R];
	for(int i=L;i<=R&&cnt*2-1<len;i=nxt[i])
		if(!a[i]){
			if(!id.size())
				return 0;
			a[i]=id.back();
			id.pop_back();
			cnt++;
		}
	for(int i=L;i<=R;i=nxt[i]){
		while(pre[i]>=L&&nxt[i]<=R&&!a[pre[i]]&&a[i]&&a[nxt[i]]){
			a[pre[i]]=a[nxt[i]];
			del(i,nxt[i]);
			i=pre[pre[i]];
		}
		while(i>=L&&nxt[nxt[i]]<=R&&a[i]&&a[nxt[i]]&&!a[nxt[nxt[i]]]){
			a[nxt[nxt[i]]]=a[i];
			del(nxt[i],nxt[nxt[i]]);
			i=pre[i];
		}
	}
	if(a[L]&&a[R]&&a[L]!=a[R])
		return 0;
	for(int i=L;i<=R;i=nxt[i])
		if(!a[i])
			a[i]=a[L];
	return 1;
}

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n*2-1;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n*2-1;i++)
		vis[a[i]]=1;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			id.push_back(i);
	init();
	if(!sol(1,2*n-1))
		puts("no");
	else{
		puts("yes");
		for(int i=1;i<=n*2-1;i++)
			printf("%d ",a[i]);
		puts("");
	}
}