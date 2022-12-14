#include<cstdio>
#include<set>
#include<iostream>
#include<algorithm>

using namespace std;

long long f(int n){
	return (long long)n*(n+1)/2;
}

struct solver{
	set<int> se;
	long long sum;
	void init(int N){
		se.clear();
		sum=0;
		for(int i=0;i<N;i++) se.insert(i);
		se.insert(-1);
		se.insert(N);
	}
	void putZero(int id){
		if(se.count(id)>0) return;
		set<int>::iterator it=se.lower_bound(id);
		int hi=(*it);
		it--;
		int lo=(*it);
		int a=id-lo-1;
		int b=hi-id-1;
		int c=hi-lo-1;
		long long cur=f(a)+f(b);
		long long prev=f(c);
		sum=(sum-prev+cur);
		se.insert(id);
	}
	void putOne(int id){
		set<int>::iterator it=se.find(id);
		if(it==se.end()) return;
		se.erase(it++);
		int hi=*it;
		it--;
		int lo=*it;
		long long prev=f(hi-id-1)+f(id-lo-1);
		long long cur=f(hi-lo-1);
		sum=(sum-prev+cur);
	}
	long long get(){
		return sum;
	}
};

solver a[18];

long long get(){
	long long ans=0;
	for(int i=0;i<18;i++){
		ans+=a[i].get()*(1ll<<i);
	}
	return ans;
}

void put(int id,int n){
	for(int i=0;i<18;i++){
		if((n>>i)&1) a[i].putOne(id);
		else a[i].putZero(id);
	}
}

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<18;i++) a[i].init(N);
	for(int i=0;i<N;i++){
		int n;
		scanf("%d",&n);
		put(i,n);
	}
	for(int i=0;i<M;i++){
		int p,v;
		scanf("%d%d",&p,&v);
		p--;
		put(p,v);
		long long ans=get();
		cout<<ans<<endl;
	}
	return 0;
}