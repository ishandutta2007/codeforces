#include<cstdio>
#include<algorithm>

using namespace std;

int a[] = {0, 1, 1, 0};

int calc(int a, int b, int c, int d){
	int e = a ^ b;//a | b;
	int f = c | d;
	int g = b & c;//b & c;
	int h = a ^ d;//a | d;
	int i = e & f;//e & f;
	int j = g | h;
	return i ^ j;//i | j;
}

int p[4];

int main(){
	for(int i = 0; i < 4; ++i){
		p[i] = i;
	}
	do{
		int x = calc(a[p[0]], a[p[1]], a[p[2]], a[p[3]]);
		if(x == 0){
		//	printf("%d %d %d %d\n", p[0], p[1], p[2], p[3]);
		}
	}while(next_permutation(p, p + 4));
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d\n", calc(a, b, c, d));
	return 0;
}