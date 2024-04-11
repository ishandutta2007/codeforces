#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int MAXN = 202020;
char s[MAXN];
int n;
stack<int> st;
int next0[MAXN], next1[MAXN];
bool visit[MAXN];
void gg()
{
	printf("-1\n");
	exit(0);
}
vector<int> output;
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	memset(next0, -1, sizeof(next0));
	memset(next1, -1, sizeof(next1));
	for(int i = n; i >= 1; i--)
		if(s[i] == '0')
			st.push(i);
		else
		{
			if(st.empty())
				gg();
			next0[i] = st.top();
			st.pop();
		}
	int ansnum = st.size();
	while(!st.empty())
		st.pop();
	for(int i = 1; i <= n; i++)
		if(s[i] == '0')
			st.push(i);
		else
		{
			if(st.empty())
				gg();
			next1[st.top()] = i;
			st.pop();
		}
	memset(visit, false, sizeof(visit));
	printf("%d\n", ansnum);
	for(int i = 1; i <= n; i++)
		if(!visit[i])
		{
			output.clear();
			int now = i;
			while(now != -1)
			{
				visit[now] = true;
				output.push_back(now);
				if(next1[now] == -1)
					break;
				now = next1[now];
				visit[now] = true;
				output.push_back(now);
				now = next0[now];
			}
			printf("%d", (int)output.size());
			for(vector<int>::iterator it = output.begin(); it != output.end(); it++)
				printf(" %d", *it);
			printf("\n");
		}
	return 0;
}