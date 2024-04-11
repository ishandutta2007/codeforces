#include <stdio.h>
#include <algorithm>
#include <string>
#include <memory.h>

char S[1111];
std::string name,s1,s2,ss[1111];
int res[1111],kg=0,kol[1111],n,cr;

int findnom(std::string s){
	for (int i=0;i<kg;i++)
		if (ss[i]==s)return i;
	ss[kg]=s;
	kg++;
	return kg-1;
}

bool cmp(int a,int b){
	if (kol[a]==kol[b])
		return ss[a]<ss[b];
	else return kol[a]>kol[b];
}

int main(){
	gets(S);
	S[strlen(S)]=0;
	name=std::string(S);
	scanf("%d\n",&n);
	for (int i=0;i<n;i++){
		gets(S);
		s1="";
		int j=0;
		while (S[j]!=' '){
			s1+=S[j];
			j++;
		}
		while (S[j]==' ')j++;
		if (S[j]=='p'){cr=15;j+=10;}else
		if (S[j]=='c'){cr=10;j+=13;}else
		if (S[j]=='l'){cr=5;j+=6;}
		s2="";
		while (int(S[j])!=39){
			s2+=S[j];
			j++;
		}
		if (s1==name){
			int x=findnom(s2);
			kol[x]+=cr;
                }else
                if (s2==name){
                	int x=findnom(s1);
                	kol[x]+=cr;
                }else{
                	findnom(s1);
                	findnom(s2);
                }
	}
	for (int i=0;i<kg;i++)res[i]=i;
	std::sort(res,res+kg,cmp);
	for (int i=0;i<kg;i++){
		for (int j=0;j<ss[res[i]].size();j++)
			putchar(ss[res[i]][j]);
		puts("");
	}
}