#include <bits/stdc++.h>
using namespace std;

string s; int ans;

int main(){
	cin >> s;
	for(char c : s){
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == '1' || c == '3' || c == '5' || c == '7' || c == '9')
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}