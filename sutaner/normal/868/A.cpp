#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	char pass[10];
	char op[10];
	int n;
	bool a = 0, b = 0;
	scanf("%s", pass);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%s", op);
		if (op[0] == pass[0] && op[1] == pass[1]){
			printf("YES");
			return 0;
		}
		if (op[0] == pass[1]) a = 1;
		if (op[1] == pass[0]) b = 1;
		if (a && b){
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}