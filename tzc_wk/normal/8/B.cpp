#include <bits/stdc++.h>
using namespace std;
int s[300][300];
char gm[110];
int main(){
	cin>>gm;
	memset(s,0,sizeof(s));
    int x=0,y=0,sum=0;
    s[150][150]=1;
    for(int i=0;i<strlen(gm);i++){
    	if(gm[i]=='L'){
    	    y--;
    	    s[150+x][150+y]+=1;
    	    if(s[151+x][150+y]||s[149+x][150+y]||s[150+x][149+y])
    	        sum++;
    	}
    	if(gm[i]=='R'){
			y++;
    		s[150+x][150+y]+=1;
    		if(s[151+x][150+y]||s[149+x][150+y]||s[150+x][151+y])
    	        sum++;
    	}
    	if(gm[i]=='U'){
    	    x++;
    	    s[150+x][150+y]+=1;
    	    if(s[151+x][150+y]||s[150+x][151+y]||s[150+x][149+y])
    	        sum++;
    	}
    	if(gm[i]=='D'){
    	    x--;
    	    s[150+x][150+y]+=1;
    	    if(s[149+x][150+y]||s[150+x][151+y]||s[150+x][149+y])
    	        sum++;
    	}
    }
    int ans=0;
    for(int i=0;i<300;i++){
    	for(int j=0;j<300;j++)
    		if(s[i][j]>1)
    	    ans++;
    }
	if(sum==0&&ans==0)printf("OK\n");
    else	printf("BUG\n");
    return 0;
}