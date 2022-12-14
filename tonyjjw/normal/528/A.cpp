//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#include<set>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 200000
using namespace std;

int W,H,N;
set<int> S1,S2;
int type[MN],A[MN],m1,m2;
char inp[3];
typedef __int64 ll;
ll ans[MN];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d%d",&W,&H,&N);
	S1.insert(0),S1.insert(W);
	S2.insert(0),S2.insert(H);
	for(int i=0;i<N;i++){
		scanf("%s",inp);
		scanf("%d",&A[i]);
		if(*inp=='V'){
			type[i]=0;
		}
		else{
			type[i]=1;
		}
		if(type[i]==0){
			S1.insert(A[i]);
		}
		else{
			S2.insert(A[i]);
		}
	}
	int bef=0;
	for(auto n:S1){
		if(n-bef>m1)m1=n-bef;
		bef=n;
	}
	bef=0;
	for(auto n:S2){
		if(n-bef>m2)m2=n-bef;
		bef=n;
	}
	ans[N-1]=(ll)m1*m2;
	for(int i=N-1;i>0;i--){
		if(type[i]==0){
			auto it=S1.find(A[i]);
			it--;
			int v1=*it;
			it++;
			it++;
			int v2=*it;
			S1.erase(A[i]);
			if(v2-v1>m1)m1=v2-v1;
		}
		else{
			auto it=S2.find(A[i]);
			it--;
			int v1=*it;
			it++;
			it++;
			int v2=*it;
			S2.erase(A[i]);
			if(v2-v1>m2)m2=v2-v1;
		}
		ans[i-1]=(ll)m1*m2;
	}
	for(int i=0;i<N;i++)printf("%I64d\n",ans[i]);
	return 0;
}
//*/