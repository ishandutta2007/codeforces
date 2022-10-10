#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string S;
		cin >> S;
		if(S[S.length()-1] == 'o') cout << "FILIPINO\n";
		if(S[S.length()-1] == 'u') cout << "JAPANESE\n";
		if(S[S.length()-1] == 'a') cout << "KOREAN\n";
	}
}