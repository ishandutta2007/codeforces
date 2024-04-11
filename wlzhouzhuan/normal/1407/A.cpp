#include <bits/stdc++.h>

using namespace std;

int read(){
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-')f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return num * f;
}
int n, cnt[2];
void work(){
	n = read(); cnt[0] = 0; cnt[1] = 0;
	for(int i = 1; i <= n; i++){
		cnt[read()]++;
	}
	if(cnt[0] >= cnt[1]){
		printf("%d\n", cnt[0]);
		for(int i = 1; i <= cnt[0]; i++)
			printf("0 ");
		printf("\n");
	}else {
		if(cnt[1] & 1)cnt[1]--;
		printf("%d\n", cnt[1]);
		for(int i = 1;i <= cnt[1]; i++)
			printf("1 ");
		printf("\n");
	}
}
int main()
{
	int Case = read();
	while(Case--)work();
	return 0;
}