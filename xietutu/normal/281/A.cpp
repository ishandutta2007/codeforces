#include <cstdio>
#include <cstring>
char s[1005];
int main() {
	//freopen("1.in","r",stdin); freopen("1.out","w",stdout);
	scanf("%s",s);
	if (!(s[0] >= 'A' && s[0] <= 'Z')) 
		s[0] = s[0] - 'a' + 'A';
	printf("%s",s);
	//fclose(stdin); fclose(stdout);
}