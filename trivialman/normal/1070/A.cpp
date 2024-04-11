#include<iostream>
#include<cstring> 
#include<queue> 
#include<string>
using namespace std;
#define N 100000010

class Number{
public:
	int modd=0, sumdigit=0;
	string num="";
	Number(){
		this->modd = this->sumdigit = 0;
		this->num = "";
	}
	Number(int x, int y, string z){
		this->modd = x;
		this->sumdigit = y;
		this->num = z;
	}
};

bool dp[510][5010];
int main(){
	int d, s;
	cin>>d>>s;
	queue<Number> numlist;
	memset(dp,false,sizeof(dp));
	Number a;
	numlist.push(a);
	while(!numlist.empty()){
		a = numlist.front();
		numlist.pop();
		for(int l=0;l<=9;l++){
			int j=(a.modd*10+l)%d, k=a.sumdigit+l;
			if(k>s)break;
			if(!dp[j][k]){
				dp[j][k] = true;
				Number b(j,k,a.num+char(l+48));
				numlist.push(b);
				//cout<<b.num<<endl;
				if((j==0)&&(k==s)){
					cout<<b.num<<endl;
					return 0;
				}
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}