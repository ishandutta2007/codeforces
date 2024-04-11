#include<cstdio>
#include<algorithm>
#include<vector>
#define N 100005
#define W 10000005

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

int pr[W],_pr,mu[W];
bool npr[W];
inline void sieve(int x){
	mu[1]=1;
	for(int i=2;i<=x;i++){
		if(!npr[i]){
			pr[++_pr]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=_pr&&i*pr[j]<=x;j++){
			npr[i*pr[j]]=1;
			if(i%pr[j]==0)
				break;
			mu[i*pr[j]]=-mu[i];
		}
	}
}

int n,k,a[N],w;

std::vector<int> d[N];

int deg[N],cnt[W];
bool tri[N];
inline void cal(int x){
	for(int i=1;i<=x;i++)
		for(std::vector<int>::iterator it=d[i].begin();it!=d[i].end();it++)
			cnt[*it]=0;
	for(int i=1;i<=x;i++)
		if(!tri[i])
			for(std::vector<int>::iterator it=d[i].begin();it!=d[i].end();it++)
				cnt[*it]++;
	for(int i=1;i<=x;i++)
		deg[i]=0;
	for(int i=1;i<=x;i++)
		if(!tri[i])
			for(std::vector<int>::iterator it=d[i].begin();it!=d[i].end();it++)
				deg[i]+=mu[*it]*cnt[*it];
}

inline int f(int x){
	int res=3;
	cal(x);
	for(int i=1;i<=x;i++)
		if(deg[i])
			res++;
	return res;
}

std::vector<int> ans;
inline bool sol(){
	for(int i=1;i<=n;i++)
		for(std::vector<int>::iterator it=d[i].begin();it!=d[i].end();it++)
			cnt[*it]=0;
	for(int i=1;i<=n;i++){
		for(std::vector<int>::iterator it=d[i].begin();it!=d[i].end();it++)
			cnt[*it]++;
		deg[i]=0;
		for(std::vector<int>::iterator it=d[i].begin();it!=d[i].end();it++)
			deg[i]+=mu[*it]*cnt[*it];
		if(!deg[i])
			ans.push_back(i);
		else
			for(std::vector<int>::iterator it=d[i].begin();it!=d[i].end();it++)
				cnt[*it]--;
	}
	if(ans.size()>=k){
		for(int i=0;i<k;i++)
			printf("%d ",ans[i]);
		puts("");
		return 1;
	}
	return 0;
}

bool del[N];

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=1;j*j<=a[i];j++)
			if(a[i]%j==0){
				d[i].push_back(j);
				if(j*j!=a[i])
					d[i].push_back(a[i]/j);
			}
		w=std::max(w,a[i]);
	}
	sieve(w);
	if(sol())
		return 0;
	cal(n);
	int flg=2,lf=0;
	for(int i=1;i<=n;i++)
		if(deg[i]>=2){
			tri[i]=1;
			for(int j=1;j<=n;j++)
				if(gcd(a[i],a[j])==1){
					tri[j]=1;
					lf=j;
					if(!--flg)
						break;
				}
			break;
		}
	int L=1,R=n,c=n+1;
	while(L<=R){
		int mid=(L+R)>>1;
		if(f(mid)>=k){
			c=mid;
			R=mid-1;
		}
		else
			L=mid+1;
	}
	int tot=f(c),tmp=tot-f(c-1)-1;
//	for(int i=1;i<=n;i++)
//		if(tri[i])
//			printf("%d ",i);
//	puts("");
//	printf("%d\n",lf);
//	printf("*%d %d %d\n",c,tot,tmp);
	cal(c);
	for(int i=1;i<=n;i++)
		if(!tri[i])
			del[i]=1;
	for(int i=1;i<=c;i++)
		if(deg[i])
			del[i]=0;
	cal(c-1);
//	for(int i=1;i<c;i++)
//		printf("%d ",deg[i]);
//	puts("");
	for(int i=1;i<c;i++)
		if(!del[i]&&!tri[i]&&!deg[i]&&tot>k&&tmp>1){
			del[i]=1;
//			printf("-%d\n",i);
			tmp--;
			tot--;
		}
//	printf("&%d %d %d\n",c,tot,tmp);
	if(tot==k+1)
		del[lf]=1;
	for(int i=1;i<=n;i++)
		if(!del[i])
			printf("%d ",i);
	puts("");
}