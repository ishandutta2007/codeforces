#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int N,p;

int main(){
	cin>>N>>p;
	string str;
	cin>>str;
	if(N==1){
		int a=str[0]-'a';
		if(a==p-1){
			cout<<"NO"<<"\n";
			return 0;
		}else{
			str[0]++;
			cout<<str<<"\n";
			return 0;
		}
	}
	if(p==2){
		if(str=="ab"){
			cout<<"ba\n";
			return 0;
		}else{
			cout<<"NO\n";
			return 0;
		}
	}
	int ln=str.size();
	for(int i=ln-1;i>=0;i--){
		vector<char> ng;
		for(int j=i-1;j>=max(i-2,0);j--){
			if(str[j]>str[i]){
				ng.push_back(str[j]);
			}
		}
		int rem=p-(str[i]-'a'+1);
		if(ng.size()>=rem) continue;
		str[i]++;
		for(int k=0;k<10;k++){
			for(int j=0;j<ng.size();j++){
				if(str[i]==ng[j]) str[i]++;
			}
		}
		for(int j=i+1;j<ln;j++){
			for(int k=0;k<3;k++){
				bool ok=true;
				for(int m=1;m<=2;m++){
					if(j-m>=0){
						if(str[j-m]-'a'==k) ok=false;
					}
				}
				if(ok==false) continue;
				str[j]='a'+k;
				break;
			}
		}
		cout<<str<<"\n";
		return 0;
	}
	cout<<"NO\n";
	return 0;
}