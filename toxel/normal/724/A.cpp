#include<bits/stdc++.h>
int main()
{
	char s1[10], s2[10], day1, day2;
	scanf("%s%s", s1, s2);
	switch (s1[0])
	{
		case 'm': day1 = 1; break;
		case 't': if (s1[1] == 'u') day1 = 2; else day1 = 4; break;
		case 'w': day1 = 3; break;
		case 'f': day1 = 5; break;
		case 's': if (s1[1] == 'a') day1 = 6; else day1 = 7; break;
	}
	switch (s2[0])
	{
		case 'm': day2 = 1; break;
		case 't': if (s2[1] == 'u') day2 = 2; else day2 = 4; break;
		case 'w': day2 = 3; break;
		case 'f': day2 = 5; break;
		case 's': if (s2[1] == 'a') day2 = 6; else day2 = 7; break;
	}
	int mod = (day2 - day1 + 7) % 7;
	if (mod == 0 || mod == 2 || mod == 3)
		printf("Yes");
	else
		printf("No");
	return 0;
}