#include <stdio.h>
#include <string.h>
namespace Input
{
	const int BUF = 65536;
	char buf[BUF + 1];
	char *head = buf, *tail = buf;
}
inline char inputchar()
{
	using namespace Input;
	if(head == tail)
		*(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
	return *head++;
}
inline void inputnum(int &ret)
{
	char ch = inputchar();
	while(ch < '0' || ch > '9')
		ch = inputchar();
	ret = ch - '0';
	ch = inputchar();
	while(ch >= '0' && ch <= '9')
	{
		ret = ret * 10 + ch - '0';
		ch = inputchar();
	}
}
const int MAXN = 303030;
int a[MAXN], *st = a, *ed = a, cnt = 0, ans = 0;
int n;
int main()
{
	inputnum(n);
	n <<= 1;
	for(int i = 1; i <= n; i++)
	{
		char ch = inputchar();
		while(ch != 'a' && ch != 'r')
			ch = inputchar();
		if(ch == 'a')//add
			inputnum(*++ed);
		else
		{
			cnt++;
			if(st == ed)
				;
			else if(*ed == cnt)
				ed--;
			else
				st = ed, ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}