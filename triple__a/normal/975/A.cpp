#include "bits/stdc++.h"
using namespace std;

const int maxn=1007;
bool fg[maxn][31],tx[maxn];
int n,cnt=0;

bool check(int t){
	for (int i='a';i<='z';++i){
		if (tx[i-'a']!=fg[t][i-'a']) return 0;
	}
	return 1;
}
int main(){
	memset(fg,0,sizeof(fg));
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		memset(tx,0,sizeof(tx));
		char chs[maxn];
		scanf("%s",&chs);
		int len=strlen(chs);
		for (int k=0;k<len;++k){
			tx[chs[k]-'a']=1;
		}
		int k;
		for (k=1;k<=cnt;++k){
			if (check(k)) break;
		}
		if (k>cnt){
			cnt++;
			for (int j='a';j<='z';++j){
				fg[cnt][j-'a']=tx[j-'a'];
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}