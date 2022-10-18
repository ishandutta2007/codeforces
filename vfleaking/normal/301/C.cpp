#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	printf("9??>>??0\n");
	for (int i = 0; i <= 8; i++)
		printf("%d??<>%d\n", i, i + 1);
	printf("??<>1\n");
	for (int i = 0; i <= 9; i++)
		printf("?%d>>%d?\n", i, i);
	for (int i = 0; i <= 9; i++)
		printf("%d>>%d?\n", i, i);

	return 0;
}