#include<stdio.h>
#include<deque>
#include<algorithm>
#define MN 100010

using namespace std;

deque<int>Q;

int N;

long long D[MN],A[MN],B[MN],v[MN];

long long val(int j1,int j2){
	return ((D[j2]-D[j1])/(B[j1]-B[j2]))+1;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,a,b;
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%lld",A+i);
	for(i=0;i<N;i++)scanf("%lld",B+i);
	Q.push_back(0);
	for(i=1;i<N;i++){
		while(Q.size()>1 && v[Q.front()]<=A[i])Q.pop_front();
		D[i]=D[Q.front()]+B[Q.front()]*A[i];
		while(Q.size()>1){
			b=Q.back(),Q.pop_back();
			a=Q.back(),Q.push_back(b);
			if(v[a]>=val(b,i))Q.pop_back();
			else	break;
		}
		v[Q.back()]=val(Q.back(),i);
		Q.push_back(i);
	}
	printf("%lld",D[N-1]);
	return 0;
}