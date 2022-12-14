//*
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#pragma warning(disable:4996)
#define MN 200000
using namespace std;

int N,M;
typedef __int64 ll;

ll L[MN],R[MN];
vector<int> in[MN];
int ans[MN],out[MN];
int heap[MN],HS;

int cmp(int a,int b){
	return out[a]>out[b];
}

struct BRIDGE{
	int index;
	ll len;
	bool operator <(BRIDGE A)const{
		return len<A.len;
	}
}bridge[MN];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=0;i<N-1;i++)ans[i]=-1;
	for(int i=0;i<N;i++)scanf("%I64d%I64d",&L[i],&R[i]);
	for(int i=0;i<M;i++){
		scanf("%I64d",&bridge[i].len);
		bridge[i].index=i;
	}
	sort(bridge,bridge+M);
	for(int i=0;i<N-1;i++){
		ll val=L[i+1]-R[i];
		int l,m,r,p=-1;
		for(l=0,r=M-1;l<=r;){
			m=(l+r)>>1;
			if(bridge[m].len>=val){
				p=m;
				r=m-1;
			}
			else{
				l=m+1;
			}
		}
		if(p==-1){
			puts("No");
			return 0;
		}
		in[p].push_back(i);
		p=-1;
		val=R[i+1]-L[i];
		for(l=0,r=M-1;l<=r;){
			m=(l+r)>>1;
			if(bridge[m].len<=val){
				p=m;
				l=m+1;
			}
			else{
				r=m-1;
			}
		}
		if(p==-1){
			puts("No");
			return 0;
		}
		out[i]=p;
	}

	for(int i=0;i<M;i++){
		for(auto n:in[i]){
			heap[HS++]=n;
			push_heap(heap,heap+HS,cmp);
		}
		while(HS>0){
			int top=heap[0];
			pop_heap(heap,heap+HS,cmp);
			heap[--HS]=0;
			if(out[top]<i)continue;
			ans[top]=bridge[i].index+1;
			break;
		}
	}
	int flag=0;
	for(int i=0;i<N-1;i++){
		if(ans[i]==-1){
			flag=1;
			break;
		}
	}
	if(flag){
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=0;i<N-1;i++)printf("%d ",ans[i]);
	return 0;
}
//*/