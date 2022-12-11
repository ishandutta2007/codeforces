#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int num[12];
int used[10];
int cc = 1;
int n;
int a[10];
int mark[12];
            
struct item
{
	int a[4];    
};
vector <item> ans;

void addInAns(int len)
{
	item q;
	int curNum = 0;
	int indA = 0;
                        
	for (int i = 0; i < len; i++)
	{
		if (mark[i])
		{
			if (i != 0)
				q.a[indA++] = curNum;
			curNum = 0;
		}
		curNum = curNum * 10 + num[i];
	}
	q.a[indA++] = curNum;
	ans.push_back(q);
}

void tryBreak(int pos, int cnt, int len)
{
	if (pos == len && cnt == 4)
	{           
		addInAns(len);
		return;
	}
	if (pos == len || cnt == 4)
		return;

	if (num[pos] == 0)
	{
		mark[pos] = 1;
		tryBreak(pos + 1, cnt + 1, len);
		mark[pos] = 0;
		return;
	}
	int curNum = 0;
	for (int s = pos + 1; s <= min(pos + 3, len); s++)
	{
		curNum = curNum * 10 + num[s - 1];
		if (curNum < 256)
		{
			mark[pos] = 1;
			tryBreak(s, cnt + 1, len);
			mark[pos] = 0;
		}
	}
}

void genNum(int pos, int len)
{                           
	if (pos == len)
	{
		cc++;
		int cntInc = 0;
		for (int i = 0; i < len; i++)
			if (used[num[i]] != cc)
			{
				used[num[i]] = cc;
				cntInc++;
			}
               
		if (cntInc != n)
			return;		
		for (int i = len; i < 2 * len; i++)
			num[i] = num[2 * len - i - 1];
		tryBreak(0, 0, 2 * len);
		for (int i = len; i < 2 * len - 1; i++)
			num[i] = num[2 * len - i - 2];

		tryBreak(0, 0, 2 * len - 1);   
		return;
	}
	for (int i = 0; i < n; i++)
	{
		num[pos] = a[i];
		genNum(pos + 1, len);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
          
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int len = 2; len <= 6; len++)
	{
		genNum(0, len);
	}
                   
    printf("%d\n", (int)ans.size());

    for (int i = 0; i < (int)ans.size(); i++)
    {
    	item cur = ans[i];
    	printf("%d.%d.%d.%d\n", cur.a[0], cur.a[1], cur.a[2], cur.a[3]);
    }	

	return 0;
}