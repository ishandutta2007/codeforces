//*

#include<stdio.h>
#include<queue>
#include<algorithm>
#include<map>
//#pragma warning(disable:4996)
#define MN 100000

using namespace std;

priority_queue<pair<int,int> >Q;
map<int,int> M;

int N,ans;
int p[MN][3],arr[3];

int main(){
	int i,a;
	pair<int,int> A,B,C;
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&a);
		if(M.find(a)!=M.end()){
			M[a]++;
		}
		else{
			M[a]=1;
		}
	}
	map<int,int>::iterator it;
	for(it=M.begin();it!=M.end();it++){
		Q.push(make_pair(it->second,it->first));
	}
	while(Q.size()>=3){
		A=Q.top(),Q.pop();
		B=Q.top(),Q.pop();
		C=Q.top(),Q.pop();
		p[ans][0]=A.second,p[ans][1]=B.second,p[ans][2]=C.second;
		sort(p[ans],p[ans]+3);
		ans++;
		A.first--,B.first--,C.first--;
		if(A.first)Q.push(A);
		if(B.first)Q.push(B);
		if(C.first)Q.push(C);
	}
	printf("%d\n",ans);
	for(i=0;i<ans;i++){
		for(a=2;a>=0;a--){
			printf("%d ",p[i][a]);
		}
		printf("\n");
	}
	return 0;
}

//*/