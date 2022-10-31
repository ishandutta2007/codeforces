#include <stdio.h>
#include <string>

int n, m;
std::string pb[1000],eb[1000];
char str[1020];

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%s",str);
		pb[i]=str;
	}
	for(int j=0;j<m;j++) {
		scanf("%s",str);
		eb[j]=str;
	}

	int pcnt=n, ecnt=m;
	int cnt=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(pb[i]==eb[j]) {
				cnt++;
				pcnt--; ecnt--;
			}
		}	
	}
	pcnt+=(cnt%2);
	if(pcnt>ecnt) 
		printf("YES\n");
	else 
		printf("NO\n");

	return 0;
}