#include<cstdio>
#include<deque>
#include<cstring>

using namespace std;

deque<int> deq;
char ch[1100100];

int main()
{
	scanf("%s",ch);
	int N=strlen(ch);
	if(N==1)
	{
		printf("1\n");
		return 0;
	}
	deq.push_back(N);
	for(int i=N-2;i>=0;i--)
	{
		if(ch[i]=='r')
		{
			deq.push_front(i+1);
		}
		else
		{
			deq.push_back(i+1);
		}
	}
	while(!deq.empty())
	{
		int id=deq.front();
		deq.pop_front();
		printf("%d\n",id);
	}
	return 0;
}