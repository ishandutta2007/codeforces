#include <cstdio>
#include <string>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n0, n1, n2;
		scanf("%d%d%d", &n0, &n1, &n2);
		int n0c = n0;
		int n1c = n1;
		int n2c = n2;
		string s;
		if (n0) {
			s.push_back('0');
			while (n0--) s.push_back('0');
		}
		if (n2) {
			s.push_back('1');
			while (n2--) s.push_back('1');
			if (n0c) --n1;
		}
		if (n1) {
			if (!n0c && !n2c) s.push_back('0');
			while (n1--) s.push_back(*(s.end() - 1) == '0' ? '1' : '0');
		}
		printf("%s\n", s.c_str());
	}
	return 0;
}