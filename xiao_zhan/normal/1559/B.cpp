#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[105],l,r,res;

char s[100500];
void work(int l,int r){
	int i,j,k;
	k=r-l+1;
	//printf("%d %d\n",l,r);
	if(l==1&&r==n){
		s[1]='B';
		for(i=2;i<=n;i++){
			if(s[i-1]=='B'){s[i]='R';}
			else{s[i]='B';}
		}
		return;
	}
	
	if(l==1){
		for(i=r;i>=l;i--){
			if(s[i+1]=='B'){s[i]='R';}
			else{s[i]='B';}
		}
		return;
	}
	
	if(r==n){
		for(i=l;i<=r;i++){
			if(s[i-1]=='B'){s[i]='R';}
			else{s[i]='B';}
		}
		return;
	}
	
	for(i=l;i<=r;i++){
		if(s[i-1]=='B'){s[i]='R';}
		else{s[i]='B';}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>s+1;
		s[0]=s[n+1]='X';
		l=0;
		for(i=1;i<=n+1;i++){
			if(s[i]=='?'){
				if(!l){
					l=i;
				}
			}
			else{
				if(l){work(l,i-1);
				}
				l=0;
			}
		}
		s[n+1]=0;
		cout<<s+1<<endl;
	}
}