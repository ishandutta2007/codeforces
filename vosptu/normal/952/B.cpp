#include <cstdio>
#include <iostream>
#include <string>
// #include <isstream>
using namespace std;

string S;

int main() {
	for (int i = 0; i <= 5; i++) {
		// scanf("")

		printf("%d\n", i);
		fflush(stdout);
		getline(cin, S);
		if (S[0] == 'a' && S[1] == 'r' && S[2] == 'e') {
			// return 202;
			printf("grumpy\n");
			return 0;
		}
		if (S[0] == 't') {
			// return 202;
			printf("grumpy\n");
			return 0;
		}
		if (S == "don't even") {
			// return 202;
			printf("grumpy\n");
			return 0;
		}
		if (S == "no way") {
			// return 202;
			printf("grumpy\n");
			return 0;
		}
		if (S == "go die in a hole") {
			// return 202;
			printf("grumpy\n");
			return 0;
		}
		if (S == "worse") {
			// return 202;
			printf("grumpy\n");
			return 0;
		}
		
	}
	// printf("grumpy\n");
	printf("normal\n");
	// cin >> S;
	// if (S == "are")
	// 	printf("grumpy\n");
	// else
	// 	printf("normal\n");
}