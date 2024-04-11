#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MN = 100000 + 1;

struct QUERY{
	int type; //1:insert 2:getmin 3:removemin
	int x;
	QUERY(){}
	QUERY(int type,int x):type(type),x(x){}
};
vector<QUERY> querys;
vector<QUERY> ans;
priority_queue<int,vector<int>,greater<int>> pq;


int N;
char buf[1000];

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s",buf);
		if(*buf=='i'){
			int a;
			scanf("%d",&a);
			ans.emplace_back(1,a);
			pq.push(a);
		}
		else if(*buf=='g'){
			int a;
			scanf("%d",&a);
			while(!pq.empty() && pq.top()<a){
				pq.pop();
				ans.emplace_back(3,-1);
			}
			if(!pq.empty() && pq.top()==a){
				ans.emplace_back(2,a);
				continue;
			}
			else{
				ans.emplace_back(1,a);
				ans.emplace_back(2,a);
				pq.push(a);
			}
		}
		else{
			if(pq.empty()){
				ans.emplace_back(1,1);
				pq.push(1);
			}
			ans.emplace_back(3,-1);
			pq.pop();
		}
	}
	printf("%d\n",ans.size());
	for(auto &q:ans){
		if(q.type==1){
			printf("insert %d\n",q.x);
		}
		else if(q.type==2){
			printf("getMin %d\n",q.x);
		}
		else{
			printf("removeMin\n");
		}
	}
	return 0;
}