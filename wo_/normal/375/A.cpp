#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

char ch[1100100];
int num[1100100];

int cnt[10];

string str;

int main(){
	scanf("%s",ch);
	num[0]=1;
	for(int i=1;i<1100100;i++){
		num[i]=num[i-1]*10;
		num[i]%=7;
	}
	int ln=strlen(ch);
	for(int i=0;i<ln;i++){
		cnt[ch[i]-'0']++;
	}
	int rem=0,c=0;
	for(int i=0;i<10;i++){
		if(i==1||i==6||i==8||i==9){
			for(int j=0;j<cnt[i]-1;j++){
				str+=('0'+i);
				rem+=num[c]*i;
				c++;
				rem%=7;
			}
		}
		else for(int j=0;j<cnt[i];j++){
			str+=('0'+i);
			rem+=num[c]*i;
			c++;
			rem%=7;
		}
	}
	int per[4]={1,6,8,9};
	do{
		int tmp=0;
		for(int i=0;i<4;i++){
			tmp+=num[c+i]*per[i];
		}
		if((tmp+rem)%7==0){
			for(int i=0;i<4;i++){
				str+=('0'+per[i]);
			}
			break;
		}
	}while(next_permutation(per,per+4));
	reverse(str.begin(),str.end());
	cout<<str<<"\n";
	return 0;
}