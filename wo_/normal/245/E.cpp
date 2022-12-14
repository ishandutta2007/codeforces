#include<cstdio>
#include<cstring>

using namespace std;

char ch[330];

int in=0,out=0;

int main()
{
	scanf("%s",ch);
	int N=strlen(ch);
	for(int i=0;i<N;i++)
	{
		if(ch[i]=='+')
		{
			if(out!=0)
			{
				out--;in++;
			}
			else in++;
		}
		else
		{
			if(in!=0)
			{
				in--;out++;
			}
			else out++;
		}
	}
	printf("%d\n",in+out);
	return 0;
}