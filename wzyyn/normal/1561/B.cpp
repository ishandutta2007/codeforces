#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int q[200005];
void solve(){
	int a,b;
	scanf("%d%d",&a,&b);
	int s1=(a+b+1)/2,s2=a+b-s1;
	*q=0;
	for (int i=0;i<=a;i++){
		int p1=i,p2=a-i,p3=s1-i,p4=b-p3;
		if (p3<0||p4<0) continue;
		q[++*q]=p2+p3;
	}
	if (s1!=s2){
		swap(s1,s2);
		for (int i=0;i<=a;i++){
			int p1=i,p2=a-i,p3=s1-i,p4=b-p3;
			if (p3<0||p4<0) continue;
			q[++*q]=p2+p3;
		}
	}
	sort(q+1,q+*q+1);
	for (int i=0;i<=*q;i++)
		printf("%d%c",q[i],i==0||i==*q?'\n':' ');
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}