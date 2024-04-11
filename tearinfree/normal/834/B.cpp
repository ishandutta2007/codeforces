#include <cstdio>

int n,k;
int le[26],ri[26];
char str[3100000];
int main() {
	scanf("%d%d",&n,&k);
	scanf("%s",str);
	for(int i=0;i<26;i++) le[i]=ri[i]=-1;
	for(int i=0;i<n;i++) {
		if(le[str[i]-'A']==-1) le[str[i]-'A']=i;
	}
	for(int i=n-1;i>=0;i--) if(ri[str[i]-'A']==-1) ri[str[i]-'A']=i;
	
	int cnt=0;
	for(int i=0;i<n;i++) {
		if(le[str[i]-'A']==i) {
			cnt++;
			if(cnt>k) {
				puts("YES");
				return 0;
			}
		}
		if(ri[str[i]-'A']==i) {
			cnt--;
		}
	}
	puts("NO");
	return 0;
}