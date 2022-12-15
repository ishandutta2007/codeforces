#include <bits/stdc++.h>
using namespace std;

string wtf[105];
int n, i, j, flag;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		cin >> wtf[i];
	sort(wtf+1,wtf+n+1,[](string s,string t){return s.size()<t.size();});
	for(i=1;i<=n;i++){
		for(j=1;j<i;j++){
			if(wtf[i].find(wtf[j])==string::npos){
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
		printf("%s\n",wtf[i].c_str());
	return 0;
}