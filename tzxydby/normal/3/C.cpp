#include<bits/stdc++.h>
using namespace std;
int co,cx,wo,wx;
char b[9];
bool f(int i,char c)
{
	return (b[3*i]==c&&b[3*i+1]==c&&b[3*i+2]==c)
	||(b[i]==c&&b[i+3]==c&&b[i+6]==c)
	||(b[0]==c&&b[4]==c&&b[8]==c)
	||(b[2]==c&&b[4]==c&&b[6]==c);
}
int main()
{
	for(int i=0;i<9;i++)
	{
		scanf("%c",&b[i]);
		while(b[i]!='0'&&b[i]!='X'&&b[i]!='.')
			scanf("%c",&b[i]);
		if(b[i]=='0')
			co++;
		if(b[i]=='X')
			cx++;
	}
	for(int i=0;i<3;i++)
	{
		wo=wo||f(i,'0');
		wx=wx||f(i,'X');
	} 
	if((wx&&cx!=co+1)||(wo&&cx!=co)||(cx!=co+1&&cx!=co))
		puts("illegal");
	else if(wx)
		puts("the first player won");
	else if(wo)
		puts("the second player won");
	else if(cx+co==9)
		puts("draw");
	else if(cx==co)
		puts("first");
	else
		puts("second"); 
	return 0;
}
////