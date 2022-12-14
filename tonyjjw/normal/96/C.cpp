#include<stdio.h>
#include<string.h>
#include<ctype.h>

int N,lens[100],len,chk[1001];
char strs[100][101],str[1001],inp[3],letter;

int main()
{
	int i,j,k;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%s",strs[i]);
		lens[i]=strlen(strs[i]);
	}
	scanf("%s",str);
	len=strlen(str);
	scanf("%s",inp);
	letter=inp[0];
	for(i=0;i<len;i++){
		for(j=0;j<N;j++){
			if(lens[j]+i>len)continue;
			for(k=0;k<lens[j];k++){
				if(tolower(str[i+k])!=tolower(strs[j][k]))break;
			}
			if(k==lens[j])
				for(k=0;k<lens[j];k++)chk[i+k]=1;
		}
	}
	for(i=0;i<len;i++){
		if(!chk[i])continue;
		if(tolower(str[i])!=letter){
			if(tolower(str[i])==str[i])
				str[i]=letter;
			else
				str[i]=letter+'A'-'a';
		}
		else{
			if(letter=='a'){
				if(tolower(str[i])==str[i])str[i]='b';
				else	str[i]='B';
			}
			else{
				if(tolower(str[i])==str[i])str[i]='a';
				else	str[i]='A';
			}
		}
	}
	printf("%s",str);
	return 0;
}