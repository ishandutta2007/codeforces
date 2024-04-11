#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=105;
int n,T,suma,sumb,all;
int a[maxn],b[maxn];
vector< pair<int,int> >p,q;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),suma=sumb=all=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),suma+=a[i];
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]),sumb+=b[i];
		if(suma!=sumb){
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++){
			int x=a[i]-b[i];
			if(x>0)
				p.push_back(make_pair(i,x)),all+=x;
			if(x<0)
				q.push_back(make_pair(i,x)),all-=x;
		}
		printf("%d\n",all/2);
		while(p.size()&&q.size()){
			pair<int,int>x=p.back(),y=q.back();
			printf("%d %d\n",x.first,y.first);
			p.pop_back(),q.pop_back();
			if(x.second>1)
				p.push_back(make_pair(x.first,x.second-1));
			if(y.second<-1)
				q.push_back(make_pair(y.first,y.second+1));
		}
		p.clear(),q.clear();
	}
	return 0;
}