#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const char res[6][4]={"RGB","RBG","BRG","BGR","GRB","GBR"};
int n,ans,minn=2147483647;
char c[200005];
int main()
{
	scanf("%d",&n);
	scanf("%s",c);
	for(int i=0;i<6;i++)
	{
		int num=0;
		for(int j=0;j<n;j++)
		  if(c[j]!=res[i][j%3])
		    num++;
		if(num<minn)
		{
			ans=i;
			minn=num;
		}
	}
	printf("%d\n",minn);
	for(int i=0;i<n;i++)
	  putchar(res[ans][i%3]);
	putchar('\n');
	return 0;
}