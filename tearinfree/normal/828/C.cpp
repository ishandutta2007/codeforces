#include <bits/stdc++.h>


int n;
std::string tt[100001];
int res[1100000];
char str[3100000];

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		int k,x;
		scanf("%s %d",str,&k);
		tt[i]=str;
		while(k--) {
			scanf("%d",&x);
			if(res[x]==0) res[x]=i;
			else if(tt[res[x]].size()<tt[i].size()) res[x]=i;
		}
	}
	memset(str,0,sizeof(str));
	int r=1;
	for(int i=1;i<=1000000;i++) {
		if(res[i]==0) continue;
		if(r<i) r=i;
		for(;r<i+tt[res[i]].size();r++) {
			str[r]=tt[res[i]][r-i];
		}
	}
	for(int i=1;i<r;i++) {
		if(str[i]==0) printf("a");
		else printf("%c",str[i]);
	}
	
	return 0;
}