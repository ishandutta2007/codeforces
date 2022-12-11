#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = (int)1e5 + 10;                          
const int LOG = 17;
int n;

int a[N];

int h[N];
int firstMax[N][LOG];      

int max(int a, int b, int c)
{
	return max(a, max(b, c));
}

void calcH()
{                          	
	h[1] = 0;
	for (int i = 2; i < N; i++)
		h[i] = h[i / 2] + 1;     
}

void calcMax()
{
	for (int s = 0; s < LOG; s++)
	{
		for (int i = 0; i <= (n - (1 << s)); i++)
		{
			if (s == 0)
				firstMax[i][s] = a[i];
			else
				firstMax[i][s] = max(firstMax[i][s - 1], firstMax[i + (1 << (s - 1))][s - 1]);
		}
	}
}
                                               
int getMax(int l, int r)
{
	int len = r - l + 1;
	return max(firstMax[l][h[len]], firstMax[r - (1 << h[len]) + 1][h[len]]);
}

int findWithMask1(int l, int r, int mask, int t, int pos)
{                                  
	while (r - l > 1)
	{
		int m = (l + r) / 2;                                 
		int locMax = getMax(pos + 1, m);
		if (locMax > a[pos])
			r = m;
		else if ((locMax & mask) == mask && ((locMax | mask) & t) == mask)
		{                                           
			return true;
		}
		else if (locMax < mask)
			l = m;
		else
			r = m;
	}
	return false;
}

int findWithMask2(int l, int r, int mask, int t, int pos)
{                                  
	while (r - l > 1)
	{
		int m = (l + r) / 2;                                 
		int locMax = getMax(m, pos - 1);
		if (locMax > a[pos])
			l = m;
		else if ((locMax & mask) == mask && ((locMax | mask) & t) == mask)
		{                                           
			return true;
		}
		else if (locMax < mask)
			r = m;
		else
			l = m;
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	calcH();

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	calcMax();                                              

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		int curMask = 0;
		int oneMask = 0;
		for (int bit = 30; bit >= 0; bit--)
		{	        
			int nMask = curMask;    
			oneMask |= (1 << bit);
			if (!(a[i] & (1 << bit)))
				nMask |= (1 << bit);               
			if (findWithMask1(i, n, nMask, oneMask, i))
				curMask = nMask;
			else
				curMask |= (a[i] & (1 << bit));          
		}                                       
		ans = max(ans, a[i] ^ curMask);
	}

	for (int i = n - 1; i >= 0; i--)	
	{
		int curMask = 0;
		int oneMask = 0;
		for (int bit = 30; bit >= 0; bit--)
		{	        
			int nMask = curMask;    
			oneMask |= (1 << bit);
			if (!(a[i] & (1 << bit)))
				nMask |= (1 << bit);               
			if (findWithMask2(-1, i, nMask, oneMask, i))
				curMask = nMask;
			else
				curMask |= (a[i] & (1 << bit));          
		}                                       
		ans = max(ans, a[i] ^ curMask);		
	}	

	printf("%d", ans);

	return 0;
}