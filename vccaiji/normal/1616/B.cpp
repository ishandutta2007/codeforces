#include<bits/stdc++.h> 
using namespace std;
char s[210000]; 
int main(){
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		scanf("%s",s+1);
		if(n==1||s[1]<=s[2])printf("%c%c\n",s[1],s[1]);
		else{
			int k;
			for(int i=2;;i++){
				if(i==n||s[i]<s[i+1]){
					k=i;
					break;
				}
			}
			for(int i=1;i<=k;i++)printf("%c",s[i]);
			for(int i=k;i;i--)printf("%c",s[i]);
			printf("\n");
		}
	}
	return 0;
}