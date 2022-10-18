#include<bits/stdc++.h>
#define N 100005

int T;

int n;
char s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int x=0,y=n+1;
		for(int i=n;i;i--)
			if(s[i]=='0')
				x=i;
		for(int i=1;i<=n;i++)
			if(s[i]=='0')
				y=i;
		if(!x)
			puts("0");
		else{
			bool flg=1;
			for(int i=x;i<=y;i++)
				if(s[i]!='0')
					flg=0;
			puts(flg?"1":"2");
		}
	}
}