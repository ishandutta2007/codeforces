#include <bits/stdc++.h>
using namespace std;

char dat[6][6];

int main()
{
	for (int i = 1; i <= 4; i++) scanf("%s", dat[i] + 1);
	for (int i = 1; i <= 4; i++) for (int j = 1; j <= 4; j++)
	{
		if (dat[i][j] != '.') continue;
#define F(x1,y1,x2,y2) if(dat[i+x1][j+y1]=='x'&&dat[i+x2][j+y2]=='x')return printf("YES\n"),0;

		F(1,0,2,0)
		F(1,0,-1,0)
		F(-1,0,-2,0)
		F(0, 1, 0, 2)
		F(0, 1, 0, -1)
		F(0, -1, 0, -2)
		F(1,1,2,2)
		F(1,1,-1,-1)
		F(-1,-1,-2,-2)
		F(1, -1, 2, -2)
		F(-1, 1, -2, 2)
		F(-1,1,1,-1)
	}
	printf("NO\n");
}