/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
char s[1000005];
int tp[1000005], sum;
int main()
{
	int top = 0, cnt0 = 0, cnt1 = 1; tp[top = 1] = 1;
	scanf("%s", s + 1);
	while(1)
	{
		scanf("%s", s + 1);
		if(s[1] == '=') {scanf("%d", &sum); break;}
		if(s[1] == '+') tp[++top] = 1, cnt1++;
		if(s[1] == '-') tp[++top] = 0, cnt0++;
		scanf("%s", s + 1);
	}
	int tmp = sum;
	sum += cnt0 - cnt1; tmp--;
	if(sum > tmp * cnt1 || sum < -tmp * cnt0) {printf("Impossible\n"); return 0;}
	printf("Possible\n");
	ru(i, 1, top)
	{
		if(tp[i] == 0) 
		{
			int now = 1 + min(tmp, max(0, -sum));
			printf("- %d ", now);
			sum += now - 1;
		}
		else 
		{
			int now = 1 + min(tmp, max(0, sum));
			if(i != 1) printf("+ ");
			printf("%d ", now);
			sum -= (now - 1);
		}
	}
	printf("= %d\n", tmp + 1);
	return 0;
}