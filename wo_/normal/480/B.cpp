#include<cstdio>
#include<set>
#include<algorithm>

using namespace std;

set<int> se;

int N,L,x,y;

bool exi(int a){
	set<int>::iterator it=se.lower_bound(a);
	if(it!=se.end()&&(*it)==a) return true;
	return false;
}

int main(){
	scanf("%d%d%d%d",&N,&L,&x,&y);
	for(int i=0;i<N;i++){
		int a;
		scanf("%d",&a);
		se.insert(a);
	}
	bool xflg=false,yflg=false;
	set<int>::iterator it=se.begin();
	for(;it!=se.end();it++){
		int cur=*it;
		if(exi(cur+x)) xflg=true;
		if(exi(cur+y)) yflg=true;
	}
	if(xflg&&yflg){
		printf("0\n");
		return 0;
	}else if(xflg&&(!yflg)){
		printf("1\n");
		printf("%d\n",y);
		return 0;
	}else if((!xflg)&&yflg){
		printf("1\n");
		printf("%d\n",x);
		return 0;
	}
	it=se.begin();
	for(;it!=se.end();it++){
		int cur=*it;
		if(exi(cur+x+y)){
			printf("1\n");
			printf("%d\n",cur+x);
			return 0;
		}
		if(exi(cur+y-x)){
			if(cur>=x){
				printf("1\n");
				printf("%d\n",cur-x);
				return 0;
			}
			if(cur+y<=L){
				printf("1\n");
				printf("%d\n",cur+y);
				return 0;
			}
		}
	}
	printf("2\n");
	printf("%d %d\n",x,y);
	return 0;
}