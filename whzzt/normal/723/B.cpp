#include"bits/stdc++.h"
#define F(i,l,r) for(register int i=l;i<=r;i++)
using namespace std;
typedef long long ll;
char s[305];int n,len,cnt,a1,a2;
int main(){
	scanf("%d\n",&n);scanf("%s",s);
	F(i,0,n-1){
		if(s[i]=='(') cnt++;
		if(s[i]==')') cnt--;
		if(s[i]>='a'&&s[i]<='z' || s[i]>='A'&&s[i]<='Z')
			len ++ ;
		else len = 0;
		if (cnt==0) a1=max(a1,len);
		else if (len==1) a2 ++;
	}
	cout<<a1<<' '<<a2<<endl;
	return 0;
}