#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char name[40][100] = {"Washington", "Adams", "Jefferson", "Madison", "Monroe", "Adams", "Jackson", "Van Buren", "Harrison", "Tyler", "Polk", "Taylor", "Fillmore", "Pierce", "Buchanan", "Lincoln", "Johnson", "Grant", "Hayes", "Garfield", "Arthur", "Cleveland", "Harrison", "Cleveland", "McKinley", "Roosevelt", "Taft", "Wilson", "Harding", "Coolidge", "Hoover", "Roosevelt", "Truman", "Eisenhower", "Kennedy", "Johnson", "Nixon", "Ford", "Carter", "Reagan"}; 

int main() {
	int n;
	scanf("%d", &n);
	printf("%s\n", name[n - 1]);
	return 0;
}