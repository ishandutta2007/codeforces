#include<bits/stdc++.h>
using namespace std;
int main(){
	string t;
	cin>>t;
	int s=(int)(t[0]-'0')*10+(int)(t[1]-'0');
	int m=(int)(t[3]-'0')*10+(int)(t[4]-'0');
	if((s==0||s==12)&&m==0){cout<<"0 0";return 0;}
	int rs=12-(s%12),rm=(60-m)%60;
	if(m>0)rs--;
	double angle1=(double)(s*60+m)/2;
	if(angle1>=360)angle1-=360;
	double angle2=m*6;
	cout<<fixed<<setprecision(9)<<angle1<<" "<<angle2;
}