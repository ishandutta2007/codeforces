//This code was designed for tutorial purpose
#include<stdio.h>
int main()
{
	char awal[2],akhir[2],jalan[8][3];
	scanf("%s%s",awal,akhir);
	int selisihX=akhir[0]-awal[0],selisihY=akhir[1]-awal[1],langkah,i;
	for(langkah=0;selisihX!=0||selisihY!=0;langkah++)
	{
		i=0;
		if(selisihX<0)
		{
			selisihX=selisihX+1;
			jalan[langkah][i]='L';
			i=i+1;
		}
		if(selisihX>0)
		{
			selisihX=selisihX-1;
			jalan[langkah][i]='R';
			i=i+1;
		}
		if(selisihY<0)
		{
			selisihY=selisihY+1;
			jalan[langkah][i]='D';
			i=i+1;
		}
		if(selisihY>0)
		{
			selisihY=selisihY-1;
			jalan[langkah][i]='U';
			i=i+1;
		}
		jalan[langkah][i]='\0';
	}
	printf("%i\n",langkah);
	while(langkah--)printf("%s\n",jalan[langkah]);
	return 0;
}