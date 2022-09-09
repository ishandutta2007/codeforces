#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=300050;
bool InStack[N];
int Stack[N],stk;
int tr=1,sol;
char ch[12];
bool Compare(int a, int b){ return a>b;}
int max(int a, int b){ return a>b?a:b;}
int Max_E;
int main()
{
	int n,i,x,j;
	scanf("%i",&n);
	for(i=0;i<2*n;i++)
	{
		scanf("%s",&ch);
		if(ch[0]=='a')
		{
			scanf("%i",&x);
			Stack[stk]=x;
			stk++;
			InStack[x]=true;
			Max_E=max(Max_E,x);
		}
		else
		{
			if(stk>0 && Stack[stk-1]!=tr)
			{
				sol++;
				stk=0;
				//for(j=Max_E;j>0;j--) if(InStack[j]) Stack[stk++]=j;
				//sort(Stack,Stack+stk,Compare);
			}
			if(stk>0) stk--;
			//InStack[tr]=false;
			tr++;
		}
	}
	printf("%i\n",sol);
	return 0;
}