#include<stdio.h>
#include<string.h>

char str[20];

bool bigger(char *A,char *B){
	int i,len=strlen(A);
	for(i=0;i<len;i++){
		if(A[i]>B[i])return true;
		if(A[i]<B[i])return false;
	}
	return true;
}

char tmp[20];

int main()
{
	int len,i,j,cnt4,cnt7,temp;
	scanf("%s",str);
	len=strlen(str);
	if(len&1){
		len++;
		for(i=0;i<len/2;i++)tmp[i]='4';
		for(i=len/2;i<len;i++)tmp[i]='7';
		printf("%s",tmp);
		return 0;
	}
	for(i=0;i<len/2;i++)tmp[i]='7';
	for(i=len/2;i<len;i++)tmp[i]='4';
	if(!bigger(tmp,str)){
		len+=2;
		for(i=0;i<len/2;i++)tmp[i]='4';
		for(i=len/2;i<len;i++)tmp[i]='7';
		printf("%s",tmp);
		return 0;
	}
	cnt4=cnt7=len/2;
	for(i=0;i<len;i++){
		if(cnt4){
			tmp[i]='4';cnt4--;
			temp=cnt7;
			for(j=i+1;j<len;j++){
				if(cnt7)tmp[j]='7',cnt7--;
				else	tmp[j]='4';
			}
			cnt7=temp;
			if(bigger(tmp,str)){
				continue;
			}
			cnt4++;
		}
		tmp[i]='7';
		cnt7--;
	}
	printf("%s",tmp);
	return 0;
}