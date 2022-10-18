#include<cstdio>

int a,b,c;
char aa,bb,cc;

int s[15],m[15],p[15];

int main(){
	scanf("%d%c%d%c%d%c",&a,&aa,&b,&bb,&c,&cc);
	if(aa=='s')
		s[a]++;
	else if(aa=='m')
		m[a]++;
	else
		p[a]++;
	if(bb=='s')
		s[b]++;
	else if(bb=='m')
		m[b]++;
	else
		p[b]++;
	if(cc=='s')
		s[c]++;
	else if(cc=='m')
		m[c]++;
	else
		p[c]++;
	for(int i=1;i<=9;i++){
		if(s[i]==3||m[i]==3||p[i]==3){
			printf("0");
			return 0;
		}
		if((s[i]&&s[i+1]&&s[i+2])||(m[i]&&m[i+1]&&m[i+2])||(p[i]&&p[i+1]&&p[i+2])){
			printf("0");
			return 0;
		}
		if(s[i]==2||m[i]==2||p[i]==2){
			printf("1");
			return 0;
		}
		if((s[i]&&s[i+1])||(m[i]&&m[i+1])||(p[i]&&p[i+1])||(s[i]&&s[i+2])||(m[i]&&m[i+2])||(p[i]&&p[i+2])){
			printf("1");
			return 0;
		}
	}
	printf("2");
}