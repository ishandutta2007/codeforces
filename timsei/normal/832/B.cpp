using namespace std;
#include<bits/stdc++.h>
char bef[1000001],af[1000001],good[1000001],pi[1000001];
int l,cnt,it;
bool well[256],flag = 0;
int main() {
	scanf("%s",good);
	int lw=strlen(good);
	for(int i = 0;i < lw ;i ++ ) {
		well[good[i]]=1;
	}
	scanf("%s",bef);
	l = strlen(bef);it=-1;
	for(int i = 0;i < l; i ++) {
		if(bef[i] == '*') {
			it = i;break;
		}
	}
	
	if(it == -1) flag = 0 ; else flag=1;
	int n;
	cin>>n;
	for(int i = 1;i <= n;i ++ ){
		
		scanf("%s",pi);
		int ll=strlen(pi);
		if(ll<l-1||((l-1==ll)&&!flag)) {
			puts("NO");continue;
		}
		if(ll>l&&!flag)  {
			puts("NO");continue;
		}
		if(!flag) {
			bool pk=0;
			for(int j=0;j < l ;j++) {
				if(pi[j] != bef[j]) {
					if(bef[j]=='?' && well[pi[j]]) continue;
					puts("NO"); pk = 1;break;
				}
			}
			if(!pk) puts("YES");
			continue;
		}
		
		
		bool pk = 0;
		for(int j = 0;j<it;j++) {
			if(pi[j] != bef[j]) {
				if(bef[j]=='?' && well[pi[j]]) continue;
				puts("NO");pk = 1;break;
			}
		}
		if(pk) continue;
		for(int j = l-1;j>it;j--) {
			if(pi[ll-l+j] != bef[j]) {
				if(bef[j]=='?' && well[pi[ll-l+j]]) continue;
				puts("NO");pk=1;break;
			}
		}
		if(pk) continue;
		for(int j=it;j<=ll-l+it;j++) {
			if(well[pi[j]]) {
				puts("NO");pk=1;break;
			}
		}
		if(pk) continue;
		puts("YES");
	}
}