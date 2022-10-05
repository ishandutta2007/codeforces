#include<bits/stdc++.h>

const int N = 2010;

std::vector <int> vec;
int rev[N];
char s[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		vec.push_back(i);
	}
	for (int i = 1; i <= n; ++ i){
		int sz = vec.size();
		rev[vec[(sz + 1) / 2 - 1]] = i;
		vec.erase(vec.begin() + (sz + 1) / 2 - 1);
	}
	scanf("%s", s);
	for (int i = 1; i <= n; ++ i){
		putchar(s[rev[i] - 1]);
	}
	putchar('\n');
	return 0;
}