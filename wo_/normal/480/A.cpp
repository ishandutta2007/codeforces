#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

P ps[5050];
int N;

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		ps[i]=P(a,b);
	}
	sort(ps,ps+N);
	int cur=-1;
	for(int i=0;i<N;i++){
		if(ps[i].second>=cur) cur=ps[i].second;
		else cur=ps[i].first;
	}
	printf("%d\n",cur);
	return 0;
}