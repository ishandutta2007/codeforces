#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
deque<int> id[2], d[MN];
string s; int nxt;

int main(){
	cin >> s;
	for(int i=0;i<s.size();i++){
		char c = s[i];
		if(c == '0'){
			if(id[1].size()){
				id[0].push_back(id[1].front());
				d[id[1].front()].push_back(i+1);
				id[1].pop_front();
			}
			else{
				id[0].push_back(++nxt);
				d[nxt].push_back(i+1);
			}
		}
		else{
			if(id[0].size()){
				id[1].push_back(id[0].front());
				d[id[0].front()].push_back(i+1);
				id[0].pop_front();
			}
			else{
				printf("-1\n");
				return 0;
			}
		}
	}
	if(id[1].size()) printf("-1\n");
	else{
		printf("%d\n",id[0].size());
		while(id[0].size()){
			int v = id[0].front();
			id[0].pop_front();
			printf("%d ",d[v].size());
			while(d[v].size()){
				printf("%d ",d[v].front());
				d[v].pop_front();
			}
			printf("\n");
		}
	}
	return 0;
}