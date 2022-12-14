#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

P ps[300300];
int N;

int ans[300300];

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int in;
		scanf("%d",&in);
		ps[i]=P(in,i);
	}
	sort(ps,ps+N);
	int prev=0;
	for(int i=0;i<N;i++){
		int id=ps[i].second;
		if(prev<ps[i].first){
			ans[id]=ps[i].first;
			prev=ps[i].first;
		}
		else{
			ans[id]=prev+1;
			prev++;
		}
	}
	for(int i=0;i<N;i++){
		printf("%d%c",ans[i],i==N-1?'\n':' ');
	}
	return 0;
}