#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char s[15], rev_s[15];// 

int main()
{
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++)// 
	{
		if (s[i] == '1' || s[i] == '2')
		{
			printf("No");// 12
			return 0;
		}
		if (s[i] == '3') rev_s[i] = '3';// 
		if (s[i] == '4') rev_s[i] = '6';
		if (s[i] == '5') rev_s[i] = '9';
		if (s[i] == '6') rev_s[i] = '4';
		if (s[i] == '7') rev_s[i] = '7';
		if (s[i] == '8') rev_s[i] = '0';
		if (s[i] == '9') rev_s[i] = '5';
		if (s[i] == '0') rev_s[i] = '8';
	}
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != rev_s[strlen(s)-i-1])// 
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");// yes
	return 0;
}