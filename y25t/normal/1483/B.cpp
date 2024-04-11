#include<cstdio>
#include<algorithm>
#include<vector>
#define N 100005

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

int T;

int n,a[N];

int nxt[N],pre[N];

int f[N];
inline int fnd(int x){
	return f[x]?f[x]=fnd(f[x]):x;
}
int cnt;
inline void uni(int x,int y){
	int fx=fnd(x),fy=fnd(y);
	if(fx!=fy)
		f[fx]=fy;
}

std::vector<int> ans;
int lst;
inline void del(int x){
	nxt[pre[x]]=nxt[x];
	pre[nxt[x]]=pre[x];
	ans.push_back(x);
	if(gcd(a[pre[x]],a[nxt[x]])!=1)
		uni(pre[x],nxt[x]);
	lst--;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			f[i]=0;
		for(int i=1;i<n;i++){
			nxt[i]=i+1;
			pre[i+1]=i;
		}
		nxt[n]=1;
		pre[1]=n;
		for(int i=1;i<=n;i++)
			if(gcd(a[i],a[nxt[i]])!=1)
				uni(i,nxt[i]);
		lst=n;
		ans.clear();
		int rt=1;
		while(lst){
			int tmp=fnd(rt);
			if(gcd(a[tmp],a[nxt[tmp]])!=1)
				break;
//			printf("&%d %d\n",rt,tmp);
			rt=nxt[nxt[tmp]];
			del(nxt[tmp]);
		}
		printf("%d ",ans.size());
		for(auto x:ans)
			printf("%d ",x);
		puts("");
	}
}