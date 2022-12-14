#include<cstdio>
#include<iostream>
#include<set>

using namespace std;

struct BIT{
	int N;
	int dat[1100100];
	void init(int N_){
		N=N_;
		for(int i=1;i<=N;i++) dat[i]=0;
	}
	void add(int i,int x){
		while(i<=N){
			dat[i]+=x;
			i+=(i&(-i));
		}
	}
	int get(int i){
		int ans=0;
		while(i>0){
			ans+=dat[i];
			i-=(i&(-i));
		}
		return ans;
	}
};

BIT bit;
set<int> se;

int p[1100100],rp[1100100],a[1100100];
bool used[1100100];

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		scanf("%d",p+i);
		rp[p[i]]=i+1;
	}
	for(int i=0;i<=N;i++) used[i]=false;
	for(int i=0;i<K;i++){
		scanf("%d",a+i);
		used[a[i]]=true;
	}
	long long ans=0;
	se.insert(0);
	se.insert(N+1);
	bit.init(N+1);
	for(int i=1;i<=N+1;i++) bit.add(i,1);
	for(int i=1;i<=N;i++){
		if(used[i]==true){
			se.insert(rp[i]);
		}else{
			set<int>::iterator it=se.lower_bound(rp[i]);
			int r=*it;
			it--;
			int l=*it;
			int rr=bit.get(r);
			int ll=bit.get(l);
			ans+=(rr-ll-1);
			bit.add(rp[i],-1);
		}
	}
	cout<<ans<<"\n";
	return 0;
}