#include<bits/stdc++.h>

using namespace std;

char s[100000 + 10], t[1000];

int main(){
	scanf("%s", s);
	scanf("%s", t);
	int l1 = strlen(s), l2 = strlen(t);
	int ans = 0;
	for(int i = 0; i <= l1 - l2; i++){
		int flag = 1;
		for(int j = 0; j < l2; j++)
			if (s[i+j] != t[j])
				flag = 0;
		if (flag){
			s[i + l2 - 1] = '#'; 
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}