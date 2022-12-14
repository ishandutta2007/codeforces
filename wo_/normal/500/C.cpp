#include<cstdio>
#include<set>
#include<algorithm>

using namespace std;

int N;
int w[550];
int M;
int p[1010];

int cnt[550];

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",w+i);
	for(int i=0;i<M;i++){
		scanf("%d",p+i);
		p[i]--;
	}
	for(int i=0;i<M;i++){
		int x=p[i];
		set<int> se;
		for(int j=i-1;j>=0;j--){
			if(p[j]==x) break;
			se.insert(p[j]);
		}
		set<int>::iterator it=se.begin();
		for(;it!=se.end();it++){
			int a=*it;
			cnt[a]++;
		}
	}
	int ans=0;
	for(int i=0;i<N;i++){
		ans+=cnt[i]*w[i];
	}
	printf("%d\n",ans);
	return 0;
}