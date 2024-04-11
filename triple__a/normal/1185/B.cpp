#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1000007;
int n;
char s1[maxn],s2[maxn];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		cin>>s1>>s2;
		int n1=strlen(s1),n2=strlen(s2),j=0,k=0;
		bool check=true;
		while(j<n1&&k<n2){
			char t=s1[j];
			int u=0;
			while(j<n1&&s1[j]==t){
				j++;
				u++;
			}
			while(k<n2&&s2[k]==t){
				k++;
				u--;
			}
			if (u>0){
				check=false;
			}
		}
		if (j==n1&&k==n2&&check){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}