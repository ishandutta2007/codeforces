#include <iostream>
#include <string>
using namespace std;
string s1,s2;
int p[200009],n, m,l,r,i,j,mid,a;
main(){
	cin>>s1>>s2;
	n=s1.length();
	m=s2.length();
	for(i=0; i<n; i++){
		cin>>a;
		p[a-1]=i;
	}
	l=0;r=n;
	while (r-l>1){
		mid=(r+l)/2;
		j=0;
		for (i=0; i<n; i++)
			if(s1[i]==s2[j] && mid<=p[i])j++;
		if (j==m)l=mid; 
		else r=mid;
	}
	cout<<l<<endl;
}