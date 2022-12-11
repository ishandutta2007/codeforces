#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

double matrix[128][128];
double buf[128][128];
double prob[105];
double vt[128];
double buf2[128];

void mul()
{
	memset(buf2,0,sizeof(buf2));
	for (int i = 0; i < 128; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			buf2[j] += vt[i] * matrix[i][j];
		}
	}
	memcpy(vt,buf2,sizeof(buf2));
}

void sqr()
{
	memset(buf,0,sizeof(buf));
	for (int i = 0; i < 128; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			for (int k = 0; k < 128; k++)
			{
				buf[i][j] += matrix[i][k] * matrix[k][j];
			}
		}
	}
	memcpy(matrix, buf, sizeof(buf));
}

int main()
{
	unsigned n;int x;
	scanf("%u%d",&n,&x);
	for (int i = 0; i <= x; i++)
	{
		scanf("%lf",&prob[i]);
	}

	for (int i = 0; i < 128; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			matrix[i][i^j] = prob[j];
		}
	}

	vt[0] = 1;

	for (unsigned i = 1; i <= n; i <<= 1)
	{
		if (i & n) mul();
		sqr();
	}

	printf("%.9f", max(0.0,1-vt[0]));
}