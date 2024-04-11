#include <stdio.h>
int n;char buf[233333],b2[2333333],*op=b2;
int isv[23333];
int main()
{
	isv['a']=isv['e']=isv['i']
	=isv['o']=isv['u']=isv['y']=1;
	scanf("%d%s",&n,buf);
	int ls=-1,cc=0,i=0;
	for(i=0;buf[i];++i)
	{
		if(buf[i]!=ls)
			ls=buf[i], cc=0;
		++cc;
		if(cc>1&&isv[buf[i]]
		&&!(cc==2&&(ls=='e'||ls=='o')&&buf[i+1]!=ls));
		else *(op++)=ls;
	}
	*op=0; puts(b2);
}