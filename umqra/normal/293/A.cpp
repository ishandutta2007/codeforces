#include <iostream>
#include <string>
#include <algorithm>
using namespace std;   

const int N = (int)3e6;

char a[N], b[N];
int t[4][N];
int tInd[4];

const int perm[2][4] = {{0, 1, 2, 3}, {0, 2, 1, 3}};

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
                 
	int n;
	scanf("%d\n", &n);     
	scanf("%s\n%s", a, b);

	for (int i = 0; i < 2 * n; i++)
	{
		if (a[i] == '1' && b[i] == '1')
			t[0][tInd[0]++] = i;
		else if (a[i] == '1' && b[i] == '0')
			t[1][tInd[1]++] = i;
		else if (a[i] == '0' && b[i] == '1')
			t[2][tInd[2]++] = i;
		else
			t[3][tInd[3]++] = i;
	}
                     
    int pl = 0;
    char cur[2];   	
    int cntStep = 0;
	while (1)
	{
		if (cntStep == 2 * n)
			break;
		for (int s = 0; s < 4; s++)
		{
			int ind = perm[pl][s];
			if (tInd[ind] != 0)
			{
				if (pl == 0)
					cur[0] = a[t[ind][tInd[ind] - 1]];
				else 
					cur[1] = b[t[ind][tInd[ind] - 1]];
				tInd[ind]--;
				break;
			}
		}
		if (pl == 1)
		{
			if (cur[0] > cur[1])
			{
				puts("First");
				return 0;
			}
			else if (cur[0] < cur[1])
			{
				puts("Second");
				return 0;
			}
			pl = 0;
		}
		else
			pl = 1;
		cntStep++;
	}

	puts("Draw");

	return 0;
}