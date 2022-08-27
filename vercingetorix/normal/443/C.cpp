#include <iostream>
#include <vector>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
int n;
char c;
int* cards=new int[25];
for(int yu=0; yu<25; yu++) cards[yu]=0;
int ans = 8;
cin >> n;
for(int i=0; i<n; i++)
{
	int x,y;
	cin >> c;
	if(c=='R') x=0;
	else if(c=='G') x=1;
	else if(c=='B') x=2;
	else if(c=='Y') x=3;
	else if(c=='W') x=4;
	
	cin >> c;
	if(c=='1') y=0;
	else if(c=='2') y=1;
	else if(c=='3') y=2;
	else if(c=='4') y=3;
	else if(c=='5') y=4;
	cards[x*5+y]=1;

}
int cols[5];
int nums[5];
for(int col=0; col<32; col++)
	for(int num=0; num<32; num++)
	{
		int col2=col;
		int num2=num;
		int col_n=0;
		int num_n=0;
		bool flag = true;
		for(int i=0; i<5; i++){
			cols[i]=col2 % 2;
			col_n+=col2%2;
			col2/=2;
			
		}
		for(int j=0; j<5; j++){
			nums[j]=num2 % 2;
			num_n+=num2%2;
			num2/=2;
		}
		if((num_n+col_n)>=ans) continue;
		int sum=0;
		for(int i=0; i<5; i++)
			for(int j=0; j<5; j++)
				sum+=(1-cols[i])*(1-nums[j])*cards[i*5+j];
		if(sum>1) continue;
		for(int i=0; i<5; i++){
			sum=0;
			for(int j=0; j<5; j++)
				sum+=cols[i]*(1-nums[j])*cards[i*5+j];
			if(sum>1) flag=false;
		}

		for(int j=0; j<5; j++){
			sum=0;
			for(int i=0; i<5; i++)
				sum+=(1-cols[i])*nums[j]*cards[i*5+j];
			if(sum>1) flag=false;
		}
		if(flag) ans=num_n+col_n;

	}
	cout<<ans;
//for(int yu=0; yu<25; yu++) cout<< cards[yu];


}