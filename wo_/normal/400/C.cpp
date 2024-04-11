#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

int N,M;
int x,y,z;

P clo(int i,int j,int N,int M){
	return P(j,N-i+1);
}

P clo(int i,int j,int N,int M,int t){
	P ans=P(i,j);
	for(int k=0;k<(t%4);k++){
		P p=clo(i,j,N,M);
		i=p.first,j=p.second;
		swap(N,M);
		ans=p;
	}
	return ans;
}

P cclo(int i,int j,int N,int M,int t){
	int num=4-(t%4);
	return clo(i,j,N,M,num);
}

int main(){
	int Q;
	scanf("%d%d%d%d%d%d",&N,&M,&x,&y,&z,&Q);
	for(int q=0;q<Q;q++){
		int i,j;
		int n=N,m=M;
		scanf("%d%d",&i,&j);
		P p1=clo(i,j,n,m,x);
		if(x%2==1) swap(n,m);
		if(y%2==1){
			p1.second=m+1-p1.second;
		}
		i=p1.first,j=p1.second;
		P p2=cclo(i,j,n,m,z);
		printf("%d %d\n",p2.first,p2.second);
	}
	return 0;
}