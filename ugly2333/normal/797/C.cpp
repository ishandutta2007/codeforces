//CF 797C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
int s[111111],t[111111];
char c[111111];
int main()
{
	int n,i,j,k,p,l,ii;
	cin>>c;
	n=strlen(c);
	for(i=1;i<=n;i=i+1)
		s[i]=c[i-1]-96;
	p=1;
	l=0;
	for(ii=1;ii<=26;ii=ii+1)
	for(i=1;i<=ii;i=i+1)
	{
		//cout<<l<<p<<endl;
		while(l>0&&t[l]<=i){
			cout<<char(96+t[l]);
			l--;
		}
		while(p<=n&&s[p]<=i){
			cout<<char(96+s[p]);
			p++;
		}
		
		for(j=n;j>=p;j=j-1)
		{
			if(s[j]==i){
				for(;p<=j;p=p+1){
					if(s[p]==i)
						cout<<char(96+i);
					else{
						l++;
						t[l]=s[p];
					}
				}
				p=j+1;
				break;
			}
		}
		while(l>0&&t[l]<=i){
			cout<<char(96+t[l]);
			l--;
		}
	}
	for(i=l;i>0;i=i-1)
		cout<<char(96+t[i]);
	return 0;
}
//iccgddahcaejfccggdacjbbbidifgggaifjabcdefghij