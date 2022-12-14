#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

long long a[8];
int N;
int cnt[8];

int par[8];

bool check(int p){
	long long prod=1;
	int cnt=0;
	for(int i=0;i<N;i++){
		if(par[i]==p){
			cnt++;
			if(prod>a[p]/a[i]) return false;
			prod*=a[i];
			if(prod>a[p]) return false;
		}
	}
	if(cnt==0) return true;
//	if(prod!=a[p]) return false;
	if(a[p]%prod!=0) return false;
	return true;
}

int ans=-1;

void dfs(int v){
	if(v==N){
		for(int i=0;i<N;i++){
			bool flg=check(i);
			if(flg==false) return;
		}
		int tmp=0;
		int cntTop=0,cntLeaf=0;
		for(int i=0;i<N;i++){
			if(cnt[i]==1) cntLeaf++;
			if(par[i]==N){
				cntTop++;
				tmp+=cnt[i];
			}
		}
		if(cntTop>=2) tmp++;
		tmp+=N;
		tmp-=cntLeaf;
		if(ans==-1||ans>tmp) ans=tmp;
	}else{
		for(int i=v+1;i<=N;i++){
			par[v]=i;
			dfs(v+1);
		}
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++) cin>>a[i];
	sort(a,a+N);
	for(int i=0;i<N;i++){
		cnt[i]=0;
		long long tmp=a[i];
		for(long long j=2;j*j<=a[i];j++){
			while(tmp%j==0){
				cnt[i]++;
				tmp/=j;
			}
		}
		if(tmp!=1){
			cnt[i]++;
		}
	}
	dfs(0);
	cout<<ans<<"\n";
	return 0;
}