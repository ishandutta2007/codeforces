#include <bits/stdc++.h>
using namespace std;
const int N=10050;
int r[N];
int Ask(int a,int b,int c){
	printf("? %d %d %d\n",a+1,b+1,c+1);
	fflush(stdout);
	int x;
	scanf("%i",&x);
	return x;
}
int main(){
	int tt;
	scanf("%i",&tt);
	while(tt--){
		int n;
		scanf("%i",&n);
		for(int i=0;i<n;i++){
			int a=i,b=(i+1)%n,c=(i+2)%n;
			r[i]=Ask(a,b,c);
		}
		int crw=-1,imp=-1;
		for(int i=0;i<n;i++){
			if(r[i]!=r[(i+1)%n]){
				if(r[i]==1)crw=i,imp=(i+3)%n;
				else imp=i,crw=(i+3)%n;
			}
		}
		assert(crw!=-1&&imp!=-1);
		vector<int> ans(1,imp);
		for(int i=0;i<n;i++){
			if(i==crw||i==imp)continue;
			if(Ask(i,crw,imp)==0)ans.push_back(i);
		}
		printf("! %d ",ans.size());
		for(int i=0;i<ans.size();i++)printf("%d ",ans[i]+1);
		fflush(stdout);
	}
}