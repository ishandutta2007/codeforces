#include <iostream>

using namespace std;

int n,a[100010],cn,prime[200010],prs = 0,prt[200010] = {0},opn = 0,b[100010];
int ptid[2000010];
bool isnp[2000010] = {0};
bool ok(int num){
	int i = 0;
	while(i<prs&&num!=1){
		while(num%prime[i] == 0){
			if(prt[i])return 0;
			num/=prime[i];
		}
		if(prime[i]*prime[i]>num){
			i = ptid[num]-1;
		}
		i+=1;
	}
	return 1;
}
void add(int num){
	b[opn] = num;
	opn++;
	int i = 0;
	while(i<prs&&num!=1){
		while(num%prime[i] == 0){
			prt[i] = 1; 
			num/=prime[i];
		}
		if(prime[i]*prime[i]>num){
			i = ptid[num]-1;
		}
		i+=1;
	}
}
int main(){
	for(int i = 2;i<2000010;i++){
		if(!isnp[i]){
			ptid[i] = prs;
			prime[prs] = i;
			prs++;
			for(int j = i+i;j<2000010;j+=i) isnp[j] = 1;
		}
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		//cout<<i<<endl;
		if(ok(a[i])){
			
			add(a[i]);
		}else{
			int tgt=a[i];
			while(!ok(tgt)){
				//cout<<tgt<<endl;
				tgt++;
			}
			add(tgt);
			cn = i;
			break;
		}
	}
	//cout<<"Going"<<endl;
	for(int i=0;i<prs;i++){
		if(opn == n) break; 
		if(!prt[i]){
			prt[i] = 1;
			b[opn] = prime[i];
			opn+=1;
		}
	}
	for(int i=0;i<n;i++)cout<<b[i]<<' ';
	return 0;
}