#include<bits/stdc++.h>
using namespace std;

int t;
string s;
queue<int> q[2];
int main(){
	cin>>t;
	while (t--){
		cin>>s;
		for (int i=0;i<2;++i){
			if (!q[i].empty()) q[i].pop();
		}
		int n=s.size();
		for (int i=0;i<n;++i){
			int u=s[i]-'0';
			q[u&1].push(u);
		}
		while (q[0].size()&&q[1].size()){
			if (q[0].front()<q[1].front()){
				printf("%d",q[0].front());
				q[0].pop();
			}
			else{
				printf("%d",q[1].front());
				q[1].pop();
			}
		}
		while (q[0].size()){
			printf("%d",q[0].front());
			q[0].pop();
		}
		while (q[1].size()){
			printf("%d",q[1].front());
			q[1].pop();
		}
		printf("\n"); 
	}
	return 0;
}