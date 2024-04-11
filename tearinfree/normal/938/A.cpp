#include <cstdio>

int main() {
	int n;
	char str[101];
	scanf("%d%s",&n,str);
	
	int f=0;
	for(int i=0;i<n;i++) {
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'i' || str[i] == 'u' || str[i] =='y') {
			if(!f) printf("%c",str[i]);
			f=1;
		}
		else printf("%c",str[i]),f=0;
	}
}