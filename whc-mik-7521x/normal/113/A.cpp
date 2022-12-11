#include<bits/stdc++.h>
using namespace std;
int change(char s[])
{
	int len=strlen(s);
	if (len<3)return 0;
	if (strcmp(s+len-3,"etr")==0)return 2;
    if (strcmp(s+len-4,"etra")==0)return -2;
	if (strcmp(s+len-6,"initis")==0)return 3;
	if (strcmp(s+len-6,"inites")==0)return -3;
	if (strcmp(s+len-4,"lios")==0)return 1;
	if (strcmp(s+len-5,"liala")==0)return -1;
	return 0;
}
int main(){
	char s[100005];
	cin.getline(s+1,100005);
	int len=strlen(s+1);
	s[len+1]=' ';
	char wo[100005];
	int k=0,cx=0,cnt1=0,cnt2=0,cnt3=0,now=0;
	for(int i=1;i<=len+1;i++){
		if(s[i]!=' '){
			wo[k]=s[i];
			k++;
		}
		else{
			wo[k]='\0';
			int re=change(wo);
			if(re==0){
				cout<<"NO";
				return 0;
			}
			if(re<0){
				if(cx==0)cx=-1;
				if(cx>0){
					cout<<"NO";
					return 0;
				}
			}
			else{
				if(cx==0)cx=1;
				if(cx<0){
					cout<<"NO";
					return 0;
				}
			}
			if(abs(re)==2){
				cnt2++;	
			}
			if(abs(re)==1){
				cnt1++;
			}
			if(abs(re)==3){
				cnt3++;
			}
			if(abs(re)<now){
				cout<<"NO";
				return 0;
			}
			if(abs(re)>now)now=abs(re);
			k=0;
		}
	}
	if(cnt2==0){
		if(cnt1+cnt3==1)cout<<"YES";
		else cout<<"NO";
		return 0;
	}
	if(cnt2==1){
		cout<<"YES";
	}
	else cout<<"NO";
	return 0;;
}