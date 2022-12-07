#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define PB push_back
using namespace std;
int n;
int q[100005];
char s[100005];
bool check(int x,int d){
	if (d==1) return x==1;
	if (d==2) return x%2==0;
	return d==x||d<=x-2;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	s[0]=s[n+1]='_'; s[n+2]='#';
	int rem=1;
	For(i,1,n+2)
		if (s[i]=='#'){
			if (rem) q[++*q]=rem;
			rem=0;
		}
		else
			++rem;
	sort(q+1,q+*q+1);
	int r=1;
	for (;r<=q[1];r++){
		bool flag=0;
		For(i,1,*q) if (!check(q[i],r)) flag=1;
		if (!flag) break;
	}
	if (r>q[1]){
		puts("-1");
		return 0;
	}
	else{
		int rem=1,l=0; *q=0;
		For(i,1,n+2)
			if (s[i]=='#'){
				if (rem){
					for (;;)
						if (check(rem,r)){
							q[++*q]=l;
							if (rem==r) break;
							rem-=2; l+=2;
						}
						else
							--rem,++l;
				}
				rem=0; l=i+1;
			}
			else
				++rem;
	}
	printf("%d\n",(*q)-1);
	For(i,2,*q) printf("%d ",q[i]-q[i-1]-1);
}
/*

_#__##____#####_
*/