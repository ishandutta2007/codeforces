#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long ll;

const int maxn=100007;
char s[maxn];
char ans[2][maxn];
int l;
int add(int u,int k){
	int i=u-1,j=l-1,t=0,ad=0;
	while(i>=0&&j>=u){
		ans[k][t]=(s[i]+s[j]-'0'-'0'+ad)%10;
		ad=(s[i]+s[j]-'0'-'0'+ad)/10;
		t++,i--,j--;
	}
	while(i>=0){
		ans[k][t]=(s[i]-'0'+ad)%10;
		ad=(s[i]-'0'+ad)/10;
		t++,i--;
	}
	while(j>=u){
		ans[k][t]=(s[j]-'0'+ad)%10;
		ad=(s[j]-'0'+ad)/10;
		t++,j--;
	}
	while(ans[k][t-1]==0){
		t--;
	}
	return t;
}

void print(int k,int cnt){
	for (int i=cnt-1;i>-1;--i){
		printf("%d",ans[k][i]);
	}
}

int main(){
	scanf("%d",&l);
	scanf("%s",s);
	int mdl=l/2,mdr=(l+1)/2;
	while(1){
		if (s[mdl]=='0'&&s[mdr]=='0'){
			mdl--;
			mdr++;
		}
		else{
			int cnt0=3*maxn;
			int cnt1=3*maxn;
			if (s[mdl]!='0'){
				cnt0=add(mdl,0);
			}
			if (s[mdr]!='0'){
				cnt1=add(mdr,1);
			}
			if (cnt0>cnt1){
				print(1,cnt1);
			}
			else{
				if (cnt0<cnt1){
					print(0,cnt0);
				}
				else{
					for (int k=cnt0-1;k>=0;--k){
						if (ans[0][k]<ans[1][k]){
							print(0,cnt0);
							return 0;
						}
						if (ans[1][k]<ans[0][k]){
							print(1,cnt1);
							return 0;
						}
					}
					print(0,cnt0);
					return 0;
				}
			}
			return 0;
		}
	}
	return 0;
}