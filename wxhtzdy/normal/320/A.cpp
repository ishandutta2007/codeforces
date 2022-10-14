#include <bits/stdc++.h>
using namespace std;
int main(){
	char s[10];
	scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++){
		if(s[i]!='1'&&s[i]!='4')return 0*printf("NO");
    }
    if(s[0]=='4')return 0*printf("NO");
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='4')cnt++;
        else cnt=0;
        if(cnt>2)return 0*printf("NO");
    }
    printf("YES");
    return 0;
}