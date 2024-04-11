#include <bits/stdc++.h>
using namespace std;
int no;
int main() {
	for (int i = 0; i < 10; i++) {
		cout << i << endl;
		fflush(stdout);
		string s;
		getline(cin, s);
		if (s == "no") {
			no++;
			if (no > 3) {
				printf("normal\n");
				break;
			}
		}
		if (s == "cool" || s == "not bad" || s == "don't touch me" || s == "don't think so" || s == "great!") {
			printf("normal\n");
			break;
		}
		if (s == "terrible" || s == "worse" || s == "go die in a hole" || s == "are you serious" || s == "no way") {
			printf("grumpy\n");
			break;
		}
	}
}