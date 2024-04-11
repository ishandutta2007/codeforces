#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		static char buf[100010];
		scanf("%s", buf);
		int i = 0;
		bool fail = false;
		while(buf[i]) {
			if(i && buf[i] == buf[i-1]) fail = true;
			if(buf[i] == '?') {
				buf[i] = 'a';
				if(i && buf[i-1] == 'a') buf[i] = 'b';
				if(buf[i+1] == 'a') buf[i] = 'b';
				if(buf[i] == 'b') {
					if(i && buf[i-1] == 'b') buf[i] = 'c';
					if(buf[i+1] == 'b') buf[i] = 'c';
				}
			}
			i++;
		}
		if(fail) printf("-1\n");
		else printf("%s\n", buf);
	}
}