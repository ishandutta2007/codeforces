#include<bits/stdc++.h>
using namespace std;
string a,b;
int len;
bool check(int l,int r,int l1,int r1){
	if((r-l+1)%2==1){
		for(int o=0;o<=r-l;o++)
			if(a[l+o]!=b[l1+o]) return 0;
		return 1;
	}
	else{
		int mid1=(l+r)/2,mid2=(l1+r1)/2;
		if((check(l,mid1,l1,mid2) && check(mid1+1,r,mid2+1,r1)) || (check(l,mid1,mid2+1,r1) && check(mid1+1,r,l1,mid2))) return 1;
		return 0;
	}
}
int main(){
	int t;t=1;
	while(t--){
		cin>>a>>b;len=a.size();
		if(check(0,len-1,0,len-1)) puts("YES");
		else puts("NO");
	}
	return 0;
}