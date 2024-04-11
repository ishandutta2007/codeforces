#include<bits/stdc++.h>
using namespace std;

long long work(char c){
	int i , j, tmp, k ,l;
	if (c < '@' && '[' > c)
		i = 1;
	else
		i = 0;
	if ('`' < c && '{' > c)
		j = 1;
	else
		j = 0;
	if (c >= 'a')
		tmp = c - 'a' + 1;
	else
		tmp = c - 'A' + 1;
	return (i - j) * tmp;
}

int main(){
	char s[1000];
	scanf("%s", s);
	int len = strlen(s);
	long long ans  = 0;
	for(int i = 0 ; i < len; i++){
		if (s[i] >= 'a' && s[i] <= 'z')
			ans -= s[i] - 'a' + 1;
		if (s[i] >= 'A' && s[i] <= 'Z')
			ans += s[i] - 'A' + 1;
	}
	cout<<ans<<endl;
	return 0;
}