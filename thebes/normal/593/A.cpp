#include <bits/stdc++.h>
using namespace std;

int cnt[30], n, i, j, k, tmp ,ans;
string s[101];

bool check(int x, int y, int id){
	int cnt[30];
	memset(cnt, 0, sizeof(cnt));
	for(char c : s[id])
		if(c-'a'!=x&&c-'a'!=y) return 0;
	return 1;
}

int main(){
	for(scanf("%d",&n),i=0;i<n;i++)
		cin >> s[i];
	for(i=0;i<26;i++){
		for(j=0;j<26;j++){
			tmp = 0;
			for(k=0;k<n;k++)
				if(check(i,j,k)) tmp+=s[k].size();
			ans = max(ans,tmp);
		}
	}
	printf("%d\n",ans);
	return 0;
}