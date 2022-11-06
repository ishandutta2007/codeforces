#include<stdio.h>
char in[30];
int l[30];
char o[2][30];
int main()
{
	int n = 27, x, y;
	scanf("%s", in);
	for (int i = 0; i < 27; i++) {
		if (l[in[i] - 'A'] == 0) l[in[i] - 'A'] = i+1;
		else {
			x = l[in[i] - 'A']-1;
			y = i;
		}
	}
	if (y - x == 1) {
		printf("Impossible");
		return 0;
	}
	int s = 12 - (y - x - 1) / 2;
	for (int i = 0; i <= x; i++) {
		if(s-x+i >= 0) o[0][s+i-x] = in[i];
		else o[1][(-s + x - i) - 1] = in[i];
	}
	for (int i = x + 1; i < y; i++) {
		if(s+i-x < 13) o[0][s + i - x] = in[i];
		else o[1][2 * 13 - (s + i - x) - 1] = in[i];
	}
	for (int i = y + 1; i < n; i++) {
		if(-i + y + s + 1 - (y - x - 1) %2 >= 0) o[1][-i + y + s + 1 - (y - x - 1) % 2] = in[i];
		else o[0][-(-i + y + s + 1 - (y - x - 1) % 2) - 1] = in[i];
	}
	printf("%s\n%s", o[0], o[1]);
	return 0;
}