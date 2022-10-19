#include<bits/stdc++.h>
using namespace std;

const int N = 1000001;
char s[N];
int k , n;
int hh[N];
int main() {
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for(int i = 0;i <n;i ++) hh[s[i]] ++;
	for(int j = 'a';j <='z';j ++) {
		if(hh[j] > k) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}