#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

int n;
char s[15];
int to[15],a,b,c,x;

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s%d",s,&x);
		if(*s=='|'){
			for(int i=0;i<10;i++) if(x>>i&1) to[i]=3;
		}else if(*s=='&'){
			for(int i=0;i<10;i++) if(~x>>i&1) to[i]=2;
		}else {
			for(int i=0;i<10;i++) if(x>>i&1) to[i]^=1;
		}
	}
	printf("%d\n",3);
	for(int i=0;i<10;i++)
		switch(to[i]){
			case 0: b+=1<<i; break;
			case 1: b+=1<<i; c+=1<<i; break;
			case 2: break;
			case 3: a+=1<<i; b+=1<<i; break;
		}
	printf("| %d\n",a);
	printf("& %d\n",b);
	printf("^ %d\n",c);
	return 0;
}