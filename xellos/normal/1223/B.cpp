#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		static char buf[2][110];
		scanf("%s %s", buf[0], buf[1]);
		bool ans = false;
		for(int i = 0; buf[0][i]; i++) for(int j = 0; buf[1][j]; j++)
			if(buf[0][i] == buf[1][j]) ans = true;
		if(ans) printf("Yes\n");
		else printf("No\n");
	}
}