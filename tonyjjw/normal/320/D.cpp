#include<stdio.h>
#include<list>

using namespace std;

list<int> A,B;
list<int>::iterator pos[100001],it,it2,l,r;

int N,dead[100001];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,a;
	bool flag;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&a);
		A.push_back(a);
		pos[a]=A.end();
		pos[a]--;
		B.push_back(a);
	}
	for(i=0;i<N;i++){
		it=B.end();it--;
		flag=true;
		while(1){
			if(dead[*it]){
				if(it==B.begin()){
					B.erase(it);
					break;
				}
				it2=it;
				it--;
				B.erase(it2);
				continue;
			}
			l=pos[*it];r=pos[*it];
			r++;
			if(r==A.end() || *l<*r){
				if(it==B.begin()){
					B.erase(it);
					break;
				}
				it2=it;
				it--;
				B.erase(it2);
				continue;
			}
			dead[*r]=1;
			flag=false;
			A.erase(r);
			if(it==B.begin())break;
			it--;
		}
		if(flag)break;
	}
	printf("%d",i);
	return 0;
}