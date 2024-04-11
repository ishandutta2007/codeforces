#include<bits/stdc++.h>
using namespace std;

int main(){
	char s[100];
	scanf("%s", s);
	int cnt = 1;
	for(int i = 1; i < 7; i++){
		if (s[i] == '1'){
			if (s[i+1] == '0'){
				cnt += 10;
				i++;
			}
			else
				cnt++;
		}
		else{
			cnt += s[i] - '0';
		}
	}
	cout<<cnt<<endl;
	return 0;
}