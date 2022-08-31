#include<stdio.h>
typedef unsigned u;
int main()
{
	u r=0,d=0,m=0;
	char c;
	while(1)
	{
		while((c=getchar())<'F')if(c<0)goto fin;
		if(c=='F')
		{
			if(m){if(r<d+m)r=d+m;d++;}
		}
		else{m++;if(d)d--;}
	}
	fin:;
	printf("%u\n",r);
	return 0;
}