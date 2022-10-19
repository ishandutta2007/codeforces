#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;

int a[N] , b[N] , n , m;

int main(void) {
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
	for(int i = 1;i <= m;i ++) scanf("%d",&b[i]);
	int flag = -1;
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= m;j ++) if(a[i] == b[j]) {
			if(flag == -1) flag = a[i];
			else flag = min(flag , a[i]);
		}
	}
	if(flag != -1) {
		cout<<flag<<endl; return 0;
	}
	int min1 = 9 , min2 = 9;
	for(int i = 1;i <= n;i ++) min1 = min(min1 , a[i]);
	for(int j = 1;j <= m;j ++) min2 = min(min2 , b[j]);
	if(min1 < min2) swap(min1 , min2);
	cout<<min2<<min1<<endl;
}