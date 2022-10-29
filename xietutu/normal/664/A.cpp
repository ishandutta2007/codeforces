#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
string A, B;
int main() {
	cin >> A >> B;
	while (A.size() > 1 && A[0] == '0') A.erase(A.begin());
	while (B.size() > 1 && B[0] == '0') B.erase(B.begin());
	if (A == B) cout << A << endl;
	else cout << 1 << endl;	
}