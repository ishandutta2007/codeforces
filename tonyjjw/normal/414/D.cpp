#include<stdio.h>
#include<vector>
#include<algorithm>
#define MN 100000
//#pragma warning(disable:4996)

int N,P;
int D[MN],MD;
int cnt[MN+1];
std::vector<int> E[MN];

void dfs(int n,int c){
	D[n]=c;
	if(c>MD)MD=c;
	int i;
	for(i=0;i<E[n].size();i++){
		if(D[E[n][i]])continue;
		dfs(E[n][i],c+1);
	}
}

int main(){
	int l,m,r,i,a,b,ans;
	long long s;
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d%d",&N,&r,&P);
	for(i=0;i<N-1;i++){
		scanf("%d%d",&a,&b),--a,--b;
		E[a].push_back(b),E[b].push_back(a);
	}
	dfs(0,1);
	for(i=0;i<N;i++)cnt[D[i]]++;
	cnt[1]=0;
	for(i=1;i<=MD;i++)cnt[i]+=cnt[i-1];
	l=0;
	if(r>N-1)r=N-1;
	while(l<=r){
		m=(l+r)>>1;
		for(b=std::lower_bound(cnt,cnt+MD+1,m)-cnt,a=1;b<=MD;b++){
			if(a==1){
				s=0;
				for(i=2;i<=b;i++){
					s+=(long long)(cnt[i]-cnt[i-1])*i;
				}
			}
			else{
				s+=(long long)(cnt[b]-cnt[b-1])*b;
			}
			while(cnt[b]-cnt[a]>=m){
				++a;
				s-=(long long)(cnt[a]-cnt[a-1])*a;
			}
			long long v=(long long)m*b-s-(long long)(m-(cnt[b]-cnt[a]))*a;
			if(v<=P)break;
		}
		if(b<=MD){
			ans=m;
			l=m+1;
		}
		else{
			r=m-1;
		}
	}
	printf("%d",ans);
	return 0;
}