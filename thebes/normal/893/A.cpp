#include <bits/stdc++.h>
using namespace std;

int o=3, N, i, b, x;
pair<int,int> p(1,2);

int main(){
	for(scanf("%d",&N),i=0;i<N;i++){
		scanf("%d",&x);
		if(p.first==x) swap(p.second,o);
		else if(p.second==x) swap(p.first,o);
		else b=1;
	}
	printf("%s\n",(b)?"NO":"YES");
	return 0;
}