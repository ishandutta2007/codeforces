#include<bits/stdc++.h>
using namespace std;
int t,k,ty[2505];
int main(){
	cin>>t>>k;
	for(int NNE=1;NNE<=t;NNE++){
		map<string,short>pd;
		string s[5];
		for(int i=1;i<=4;i++)cin>>s[i];
		int cnt=0,type[5];
		for(int i=1;i<=4;i++){
			int kk=0,len=s[i].size();
			for(int o=len;o>=0;o--){
				if(s[i][o]=='a'||s[i][o]=='e'||s[i][o]=='i'||s[i][o]=='o'||s[i][o]=='u'){
					kk++;
					if(k==kk){
						string hz=s[i].substr(o);
						if(pd[hz]==0){
							cnt++;
							pd[hz]=cnt;
							type[i]=cnt;
						}
						else{
							type[i]=pd[hz];
						}
						break;
					}
				}
			}
			if(kk!=k){
				cout<<"NO"<<endl;
				return 0;
			}
		}
		if(cnt>2){
			cout<<"NO"<<endl;
			return 0;
		}
		if(type[1]==1&&type[2]==1&&type[3]==2&&type[4]==2)ty[NNE]=2;
		else if(type[1]==1&&type[2]==2&&type[3]==2&&type[4]==1)ty[NNE]=4;
		else if(type[1]==1&&type[2]==2&&type[3]==1&&type[4]==2)ty[NNE]=3;
		else if(type[1]==1&&type[2]==1&&type[3]==1&&type[4]==1)ty[NNE]=1;
		else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	int pd=0;
	for(int i=1;i<=t;i++){
		if(ty[i]!=1){
			if(pd==0){
				pd=ty[i];
			}
			else if(pd!=ty[i]){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	if(pd==0)cout<<"aaaa";
	if(pd==2)cout<<"aabb";
	if(pd==3)cout<<"abab";
	if(pd==4)cout<<"abba";
	return 0;
}