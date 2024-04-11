#include "bits/stdc++.h"
using namespace std;

string day[] =
{
	"monday",
	"tuesday",
	"wednesday",
	"thursday",
	"friday",
	"saturday",
	"sunday"
};

int getday()
{
	char str[100];
	scanf("%s", str);
	return find(day, day + 7, string(str)) - day;
}

int main()
{
	int a1 = getday(), a2 = getday();
	if (a1 == a2 || (a1 + 2) % 7 == a2 || (a1 + 3) % 7 == a2) printf("YES");
	else printf("NO");
}