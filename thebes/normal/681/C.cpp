#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> q;
int N, x, cnt; string s;
pair<string,int> ans[1000006];

int main(){
	for(scanf("%d",&N);N>0;N--){
		cin >> s;
		if(s == "removeMin"){
			if(!q.size()) ans[++cnt]={"insert",1},q.push(1);
			q.pop(); ans[++cnt]={"removeMin",-1};
		}
		else if(s == "insert"){
			cin >> x;
			ans[++cnt]={"insert",x};
			q.push(x);
		}
		else{
			cin >> x;
			while(1){
				if(!q.size()){ans[++cnt]={"insert",x}; q.push(x); break;}
				if(q.top()==x) break;
				if(q.top()>x){ans[++cnt]={"insert",x}; q.push(x); break;}
				else q.pop(), ans[++cnt]={"removeMin",-1};
			}
			ans[++cnt]={"getMin",x};
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++){
		if(ans[i].first=="removeMin") printf("removeMin\n");
		else printf("%s %d\n",ans[i].first.c_str(),ans[i].second);
	}
	return 0;
}