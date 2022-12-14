#include<stdio.h>
#include<string.h>

char str[1000];
int len;

int main()
{
	int i,cnt=1;
	scanf("%s",str);
	len=strlen(str);
	for(i=1;i<len;i++){
		if(str[i-1]==str[i]){
			cnt++;
			if(cnt==7){
				printf("YES");
				return 0;
			}
		}
		else
			cnt=1;
	}
	printf("NO");
	return 0;
}