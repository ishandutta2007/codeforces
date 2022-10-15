#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;

char s[maxn];
bool fg[17];
int main(){
	int n;
	scanf("%d",&n);
	memset(fg,0,sizeof(fg));
	cin>>s;
	for (int i=0;i<n;++i){
		if (s[i]=='L'){
			for (int j=0;j<10;++j){
				if (!fg[j]){
					fg[j]=1;
					break;
				}
			}
		}
		else{
			if (s[i]=='R'){
				for (int j=9;j>-1;--j){
					if (!fg[j]){
						fg[j]=1;
						break;
					}
				}
			}
			else{
				fg[s[i]-'0']=0;
			}
		}
	}
	for (int i=0;i<10;++i){
		printf("%d",fg[i]);
	}
	return 0;
}