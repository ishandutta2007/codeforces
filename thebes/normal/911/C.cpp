#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main(){
	scanf("%d%d%d",&a,&b,&c);
	if(a==1||b==1||c==1) printf("YES\n");
	else if((a==2&&b==2)||(a==2&&c==2)||(b==2&&c==2)) printf("YES\n");
	else if(a==3&&b==3&&c==3) printf("YES\n");
	else{
		if(b<a && b<c) swap(a,b);
		if(c<a && c<b) swap(a,c);
		if(a==2&&b==4&&c==4) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}