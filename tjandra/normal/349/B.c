#include<stdio.h>
typedef unsigned u;
int main()
{
	u p,a[11],i,m=0xffffffffu,l,v,V,o=1;
	scanf("%u",&p);
	for(i=0;i++<9;)
	{
		scanf("%u",&a[i]);
		if(a[i]<=m)
		{
			m=a[i];v=i;
		}
	}
	l=p/m;V=9;
	if(l)
	{
		p-=l*m;
		while(l--)
		{
			if(o)for(o=0,i=V;i>v;i--)if(p>=a[i]-m)
			{
				p-=a[i]-m;
				o=1;V=i;
				break;
			}
			putchar(i+'0');
		}
	}
	else{putchar('-');putchar('1');}
	putchar('\n');
	return 0;
}