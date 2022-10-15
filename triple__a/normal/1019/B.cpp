#include<bits/stdc++.h>
using namespace std;

int n;

int query(int u){
	printf("? %d\n",u);
	fflush(stdout);
	int a,b;
	scanf("%d",&a);
	printf("? %d\n",u+n/2);
	fflush(stdout);
	scanf("%d",&b);
	return a-b;
}

int main(){
	scanf("%d",&n);
	if (n%4){
		printf("! -1\n");
		return 0;
	}
	int l=1,r=n/2,md=(l+r)>>1,ansl=query(l),ansr=query(r);
	if (ansl==0){
		printf("! %d\n",l);
		return 0;
	}
	if (ansr==0){
		printf("! %d\n",r);
		return 0;
	}
	while (l<=r){
		md=(l+r)>>1;
		int ans=query(md);
		if (ans==0){
			printf("! %d\n",md);
			return 0;
		}
		if ((long long)ans*ansr<0){
			l=md+1;
		}
		else{
			r=md;
			ansr=ans;
		}
	}
	return 0;
}