#include <bits/stdc++.h>
using namespace std;
int num[28],cnt,fac[6],ct;
bool good[7];
int main()
{
	for(int i=1;i<=24;i++)
		scanf("%d",&num[i]);
	for(int i=4;i<=24;i+=4)
		if(num[i]==num[i-1]&&num[i-1]==num[i-2]&&num[i-2]==num[i-3])cnt++,good[i/4]=true;
	if(cnt!=2) {printf("NO");return 0;}
	if(good[1]&&good[2]) {printf("NO");return 0;}
	if(good[1]&&good[4]) {printf("NO");return 0;}
	if(good[1]&&good[5]) {printf("NO");return 0;}
	if(good[1]&&good[6]) {printf("NO");return 0;}
	if(good[2]&&good[3]) {printf("NO");return 0;}
	if(good[2]&&good[4]) {printf("NO");return 0;}
	if(good[2]&&good[5]) {printf("NO");return 0;}
	if(good[3]&&good[4]) {printf("NO");return 0;}
	if(good[3]&&good[5]) {printf("NO");return 0;}
	if(good[3]&&good[6]) {printf("NO");return 0;}
	if(good[4]&&good[6]) {printf("NO");return 0;}
	if(good[5]&&good[6]) {printf("NO");return 0;}
	if(good[5])
	{
		if(num[1]!=num[3]) {printf("NO");return 0;}
		if(num[2]!=num[4]) {printf("NO");return 0;}
		if(num[6]!=num[8]) {printf("NO");return 0;}
		if(num[5]!=num[7]) {printf("NO");return 0;}
		if(num[11]!=num[9]) {printf("NO");return 0;}
		if(num[21]!=num[23]) {printf("NO");return 0;}
		if(num[10]!=num[12]) {printf("NO");return 0;}
		if(num[22]!=num[24]) {printf("NO");return 0;}
		if(num[1]==num[6]&&num[5]==num[10]&&num[9]==num[21]&&num[2]==num[22]) {printf("YES");return 0;}
		else if(num[2]==num[5]&&num[6]==num[9]&&num[10]==num[22]&&num[21]==num[1]) {printf("YES");return 0;}
		else {printf("NO");return 0;}
	}
	if(good[1])
	{
		if(num[13]!=num[14]) {printf("NO");return 0;}
		if(num[15]!=num[16]) {printf("NO");return 0;}
		if(num[5]!=num[6]) {printf("NO");return 0;}
		if(num[7]!=num[8]) {printf("NO");return 0;}
		if(num[17]!=num[18]) {printf("NO");return 0;}
		if(num[19]!=num[20]) {printf("NO");return 0;}
		if(num[21]!=num[22]) {printf("NO");return 0;}
		if(num[23]!=num[24]) {printf("NO");return 0;}
		if(num[13]==num[7]&&num[5]==num[19]&&num[17]==num[23]&&num[21]==num[15]) {printf("YES");return 0;}
		else if(num[5]==num[15]&&num[17]==num[7]&&num[21]==num[19]&&num[13]==num[23]) {printf("YES");return 0;}
		else {printf("NO");return 0;}
	}
	if(good[2])
	{
		if(num[1]!=num[2]) {printf("NO");return 0;}
		if(num[3]!=num[4]) {printf("NO");return 0;}
		if(num[13]!=num[15]) {printf("NO");return 0;}
		if(num[14]!=num[16]) {printf("NO");return 0;}
		if(num[9]!=num[10]) {printf("NO");return 0;}
		if(num[11]!=num[12]) {printf("NO");return 0;}
		if(num[17]!=num[19]) {printf("NO");return 0;}
		if(num[18]!=num[20]) {printf("NO");return 0;}
		if(num[1]==num[17]&&num[18]==num[9]&&num[11]==num[14]&&num[15]==num[3]) {printf("YES");return 0;}
		else if(num[1]==num[14]&&num[15]==num[9]&&num[11]==num[17]&&num[18]==num[3]) {printf("YES");return 0;}
		else {printf("NO");return 0;}
	}
	return 0;
}