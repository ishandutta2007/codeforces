#include<stdio.h>
char s[100020];
char t[100020];
int a[30],b[30],z;
int main()
{
	fscanf(fopen("input.txt","r"),"%s%s",s,t);
	for(int i=0;s[i];i++)
	{
		a[s[i]-'A']++;
		b[t[i]-'A']++;
	}
	for(int i=0;s[i];i++)
	{
		int c=s[i]-'A';
		if(a[c]>b[c])
		{
			for(int j=0;j<26;j++)
				if(a[j]<b[j])
				{
					if(j<c||!b[c])
						s[i]=j+'A',b[j]--,z++;
					else
						b[c]--;
					break;
				}
			a[c]--;
		}
	}
	fprintf(fopen("output.txt","w"),"%d\n%s\n",z,s);
	return 0;
}