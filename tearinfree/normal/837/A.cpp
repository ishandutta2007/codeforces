#include <cstdio>

int n;
char str[222];

int main() {
	scanf("%d\n",&n);
	gets(str);
	int cnt=0,max=0;
	for(int i=0;i<n;i++) {
		if(str[i]==' ') {
			if(max<cnt) max=cnt;
			cnt=0;
		}
		if(str[i]>='A'&&str[i]<='Z') cnt++;
	}
			if(max<cnt) max=cnt;
			cnt=0;
	printf("%d\n",max);
	return 0;
}