#include <stdio.h>
#include <cstring>
const int N=1000500;
char word[N];
int l[N],r[N];
void AddLeft(int i, int j)
{
	r[l[j]]=i;
	l[i]=l[j];
	r[i]=j;
	l[j]=i;
}
void AddRight(int i, int j)
{
	l[r[j]]=i;
	r[i]=r[j];
	l[i]=j;
	r[j]=i;
}
int main()
{
	int n,i;
	scanf("%s",word+1);
	word[0]='#';
	n=(unsigned) strlen(word);
	for(i=1;i<n-1;i++)
	{
		if(word[i]=='l') AddLeft(i+1,i);
		else AddRight(i+1,i);
	}
	int root=0;
	for(i=1;i<n;i++) if(l[i]==0) root=i;
	for(i=1;i<n;i++) printf("%i\n",root),root=r[root];
	//for(i=1;i<n;i++) printf("%i %i\n",l[i],r[i]);
	return 0;
}