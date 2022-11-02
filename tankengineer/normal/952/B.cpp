#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

bool isGood(char *s) {
	return strstr(s, "cool") != NULL 
		|| strstr(s, "great!") != NULL 
		|| strstr(s, "not bad") != NULL
		|| strstr(s, "don't touch me!") != NULL
		|| strstr(s, "don't think so") != NULL;
}

bool isBad(char *s) {
	return strstr(s, "terrible") != NULL 
		|| strstr(s, "worse") != NULL 
		|| strstr(s, "die") != NULL
		|| strstr(s, "serious") != NULL
		|| strstr(s, "even") != NULL
		|| strstr(s, "way") != NULL;
}

int main() {
	srand(42);
	char response[100005];
	for (int i = 0; i < 100000; ++i) {
		printf("%d\n", rand() % 10);
		fflush(stdout);
		gets(response);
		if (isGood(response)) {
			puts("normal");
			return 0;
		} else if (isBad(response)) {
			puts("grumpy");
			return 0;
		}
	}
	if (rand() & 1) {
		puts("grumpy");
	} else {
		puts("normal");
	}
	return 0;
}