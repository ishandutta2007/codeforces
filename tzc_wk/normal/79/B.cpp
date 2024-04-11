#include <bits/stdc++.h>
using namespace std;
pair<int,int> w[1001];
const char s[3][100]={"Carrots","Kiwis","Grapes"};
int n,m,k,t;
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(int i=0;i<k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		w[i]={x,y};
	}
	sort(w,w+k);
	while(t--){
		int x,y;
		scanf("%d%d",&x,&y);
		int ind=lower_bound(w,w+k,make_pair(x,y))-w;
		if(w[ind].first==x&&w[ind].second==y){
			printf("Waste\n");
			continue;
		}
		printf("%s\n",s[((x-1)*m+y-ind-1)%3]);
	}
}