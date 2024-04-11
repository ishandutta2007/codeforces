#include <bits/stdc++.h>
using namespace std;

int cnt[4], N;

int main(){
	for(scanf("%d",&N),getchar();N>0;N--){
		char c = getchar();
		if(c == 'L') cnt[0]++;
		if(c == 'R') cnt[1]++;
		if(c == 'D') cnt[2]++;
		if(c == 'U') cnt[3]++;
	}
	printf("%d\n",2*min(cnt[0],cnt[1])+2*min(cnt[2],cnt[3]));
	return 0;
}