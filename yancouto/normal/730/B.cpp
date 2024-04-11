#include <bits/stdc++.h>
using namespace std;

int b[110];
int s[110];

main(){
	
	int nt;
	scanf("%d",&nt);
	while(nt--){
		
		int n;
		scanf("%d",&n);
		
		if(n == 1){
		
			printf("! 1 1\n");
			fflush(stdout);
			continue;
		}
		
		for(int i=0;i+1<n;i+=2){
		
			printf("? %d %d\n",i+1,i+2);
			fflush(stdout);
			
			char ch;
			scanf(" %c",&ch);
			if(ch == '>')
				b[i] = i, s[i] = i+1;
			else
				b[i] = i+1, s[i] = i;
				
		}
		
		int S = s[0], B = b[0];
		
		for(int i=2;i+1<n;i+=2){
			
			printf("? %d %d\n",S+1,s[i]+1);
			fflush(stdout);
			char ch;
			scanf(" %c",&ch);
			if(ch == '>')
				S = s[i];
				
			printf("? %d %d\n",B+1,b[i]+1);
			fflush(stdout);
			scanf(" %c",&ch);
			if(ch == '<')
				B = b[i];
			
		}
		
		if(n%2 == 1){
			
			int u = n-1;
			
			printf("? %d %d\n",B+1,u+1);
			fflush(stdout);
			char ch;
			scanf(" %c",&ch);
			if(ch == '<')
				B = u;
			printf("? %d %d\n",S+1,u+1);
			fflush(stdout);
			scanf(" %c",&ch);
			if(ch == '>')
				S = u;
		
		}
		
		printf("! %d %d\n",S+1,B+1);
		fflush(stdout);
		
	}
	
}