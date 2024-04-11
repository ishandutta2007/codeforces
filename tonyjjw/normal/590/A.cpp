//*

#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

const int MN = 500000;

int A[MN];

bool chk(int i){
	return A[i]!=A[i-1] && A[i]!=A[i+1];
}

vector<int> x,y;

int main(){
	int N;
	scanf("%d",&N);
	int ans=0;
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=1;i<N-1;i++){
		if(chk(i)){
			int j=i+1;
			while(j<N-1 && chk(j))j++;
			x.push_back(i);
			y.push_back(j-1);
			if(ans<(j-i+1)/2)ans=(j-i+1)/2;
			i=j;
		}
	}
	for(int i=0;i<x.size();i++){
		int l=x[i];
		int r=y[i];
		if((r-l+1)&1){
			int v=A[l]^1;
			for(int j=l;j<=r;j++)A[j]=v;
		}
		else{
			int m=(l+r)>>1;
			int v=A[l]^1;
			for(int j=l;j<=m;j++)A[j]=v;
			for(int j=m+1;j<=r;j++)A[j]=v^1;
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<N;i++)printf("%d ",A[i]);
	return 0;
}

//*/