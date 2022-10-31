#include <cstdio>
#include <algorithm>
#include <cstring>

char s1[100],s2[100];

int main() {
	scanf("%s%s",s1,s2);
	int n=strlen(s1);
	for(int i=1;i<n;i++) {
		if(s1[i]>=s2[0]) {
			for(int j=0;j<i;j++) printf("%c",s1[j]);
			printf("%c\n",s2[0]);
			return 0;
		}
	}
	for(int i=0;i<n;i++) printf("%c",s1[i]);
	printf("%c\n",s2[0]);
	return 0;
}