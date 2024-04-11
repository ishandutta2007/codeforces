#include <bits/stdc++.h>
using namespace std;

string s;
int N, K, ans, i, oc[10];

int main(){
	for(scanf("%d%d",&N,&K),i=0;i<N;i++){
		cin >> s; memset(oc, 0, sizeof(oc));
		for(char c : s) oc[c-'0']++;
		for(int j=0;j<=K;j++){
			if(oc[j]<1) goto next;
		}
		ans++;
		next:;
	}
	printf("%d\n",ans);
	return 0;
}