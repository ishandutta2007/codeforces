#include<bits/stdc++.h>
using namespace std;
int T,n;
set<int>s;
void mina(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),s.insert(x);
	if(s.find(0)!=s.end()&&s.find(1)!=s.end()){puts("NO");return;}
	if(s.find(1)==s.end()){puts("YES");return;}
	for(auto x:s)if(s.find(x+1)!=s.end()){puts("NO");return;}
	puts("YES");
}
int main(){
	scanf("%d",&T);
	while(T--)mina(),s.clear();
	return 0;
}