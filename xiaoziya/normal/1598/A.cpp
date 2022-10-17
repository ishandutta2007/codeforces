#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
const int maxn=105;
int T,n;
int f[maxn][3];
string s[3];
queue< pair<int,int> >q;
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>n>>s[1]>>s[2];
		int flg=0;
		for(int i=0;i<n;i++)
			if(s[1][i]=='1'&&s[2][i]=='1')
				flg=1;
		puts(flg==0? "YES":"NO");
	}
	return 0;
}