#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N];
int Q,l,r,num[26][N];
int main(){
	scanf("%s",s+1);
	for (int i=1;s[i];i++){
		for (int j=0;j<26;j++)num[j][i]=num[j][i-1];
		num[s[i]-'a'][i]++;
	}
	scanf("%d",&Q);
	while (Q--){
		scanf("%d%d",&l,&r);
		int cnt=0;
		for (int i=0;i<26;i++)
			if (num[i][r]-num[i][l-1]>0)cnt++;
		if (cnt>2||s[l]!=s[r]||l==r)puts("Yes");
		else puts("No");
	}
}